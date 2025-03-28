/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:25:20 by avelandr          #+#    #+#             */
/*   Updated: 2025/03/27 22:14:28 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/***************************************************************************
	- Esta función toma dos cadenas, cache y buffer.
	- Si cache es NULL, devuelve una copia de buffer.
	- Si buffer es NULL, devuelve NULL.
	- Calcula la longitud de cache y buffer.
	- Reserva memoria para una nueva cadena que combine cache y buffer.
	- Copia cache a la nueva cadena y luego añade buffer al final de la nueva
	  cadena.
	- Libera la memoria ocupada por cache y devuelve la nueva cadena combinada.
***************************************************************************/

char	*update_cache(char *cache, char *buffer)
{
	char	*new_cache;
	size_t	cache_len;
	size_t	buffer_len;

	if (!cache)
		return (ft_strdup(buffer));
	if (!buffer)
		return (NULL);
	cache_len = ft_strlen(cache);
	buffer_len = ft_strlen(buffer);
	new_cache = (char *)malloc(cache_len + buffer_len + 1);
	if (!new_cache)
		return (NULL);
	ft_strlcpy(new_cache, cache, cache_len + 1);
	ft_strlcpy(new_cache + cache_len, buffer, buffer_len + 1);
	free(cache);
	return (new_cache);
}

/***************************************************************************
	Esta función toma un puntero a cache y extrae una línea que termina en \n.
	Si cache o *cache es NULL, devuelve NULL.
	Busca el carácter \n en *cache.
	Si no encuentra \n, devuelve NULL.
	Crea una subcadena desde el inicio de *cache hasta el carácter \n incluido.
	Calcula la longitud restante en *cache después de la línea extraída.
	Si hay contenido restante, crea una nueva subcadena con el contenido restante.
	Libera la memoria de *cache y actualiza *cache con la nueva subcadena restante.
	Devuelve la línea extraída.
***************************************************************************/

char	*extract_line(char **cache)
{
	char			*new_line;
	char			*linea;
	char			*aux;
	unsigned int	len;

	if (!cache || !*cache)
		return (NULL);
	new_line = ft_strchr(*cache, '\n');
	if (!new_line)
		return (NULL);
	linea = ft_substr(*cache, 0, new_line - *cache + 1);
	if (!linea)
		return (NULL);
	len = (unsigned int)ft_strlen(*cache) - (new_line - *cache + 1);
	if (len > 0)
	{
		aux = ft_substr(*cache, new_line - *cache + 1, len);
		if (!aux)
			return (free(*cache), NULL);
	}
	else
		aux = NULL;
	free(*cache);
	*cache = aux;
	return (linea);
}

/***************************************************************************
	Esta función gestiona la situación de fin de archivo (EOF).
	Si *cache es NULL o está vacía, libera *cache y devuelve NULL.
	Si *cache tiene contenido, crea una copia de *cache y la devuelve.
	Libera la memoria de *cache y la establece en NULL.
***************************************************************************/

char	*handle_eof(char **cache)
{
	char	*linea;

	if (!*cache || **cache == '\0')
	{
		free(*cache);
		*cache = NULL;
		return (NULL);
	}
	linea = ft_strdup(*cache);
	if (!linea)
	{
		free(*cache);
		*cache = NULL;
		return (NULL);
	}
	free(*cache);
	*cache = NULL;
	return (linea);
}

/***************************************************************************
	Esta función lee desde un archivo hasta encontrar un \n.
	En un bucle continuo, verifica si cache es NULL y la inicializa si es necesario.
	Busca \n en *cache.
	Si encuentra \n, devuelve NULL.
	Lee desde el archivo y si la lectura es menor o igual a 0, gestiona EOF y devuelve NULL.
	Añade el contenido leído a *cache usando update_cache.
***************************************************************************/

char	*read_until_newline(int fd, char **cache, char *texto)
{
	int		leido;
	char	*aux;
	char	*line;

	while (1)
	{
		if (!*cache)
			*cache = ft_strdup("");
		line = ft_strchr(*cache, '\n');
		if (line)
			return (NULL);
		leido = read(fd, texto, BUFFER_SIZE);
		if (leido <= 0)
			return (handle_eof(cache));
		texto[leido] = '\0';
		aux = update_cache(*cache, texto);
		if (!aux)
			return (free(texto), free(*cache), NULL);
		*cache = aux;
	}
	return (NULL);
}

/***************************************************************************
	Esta es la función principal que devuelve la siguiente línea de un archivo.
	Verifica si el descriptor de archivo (fd) es válido y si BUFFER_SIZE es mayor que 0.
	Si hay un cache previo, lo libera si es necesario.
	Reserva memoria para texto con tamaño BUFFER_SIZE + 1.
	Usa read_until_newline para leer el archivo hasta encontrar un \n.
	Libera la memoria de texto.
	Extrae una línea de cache usando extract_line.
	Devuelve la línea extraída.
***************************************************************************/

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*texto;
	char		*linea;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (cache)
			return (free(cache), NULL);
		return (NULL);
	}
	texto = (char *)malloc(BUFFER_SIZE + 1);
	if (!texto)
		return (NULL);
	if (read_until_newline(fd, &cache, texto))
		return (NULL);
	free(texto);
	linea = extract_line(&cache);
	return (linea);
}
