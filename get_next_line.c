/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:25:20 by avelandr          #+#    #+#             */
/*   Updated: 2025/03/05 16:23:48 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	update_cache() retorna un puntero copia de la cache restante al hacer
	retorno de la linea
*/

char *update_cache(char *cache, char *texto)
{
	char *tmp;

	tmp = ft_strjoin(cache, texto);
	free(cache);
	return (tmp);
}

/*
	ft_substr extrae una subcadena de *cache desde la posición justo después
	del \n hasta el final.
	-	new_line - *cache + 1: calcula cuántos caracteres hay hasta justo
			después del \n
	-	ft_strlen(*cache) - (new_line - *cache + 1) : restar esto de la
		longitud total nos da el tamaño restante de la cadena después del \n
	ft_substr(*cache, inicio, longitud)
	extract_line necesita modificar cache. La función extrae la línea actual
	(hasta el salto de línea) y actualiza cache con el resto del texto. Para
	modificar cache (que es un puntero), necesitamos pasar un puntero a cache
	(es decir, un doble puntero).
*/

char *extract_line(char **cache)
{
	char	*new_line;
	char	*linea;
	char	*aux;
	int		len;

	new_line = ft_strchr(*cache, '\n');
	if (!new_line)
		return (NULL);
	linea = ft_substr(*cache, 0, new_line - *cache + 1);
	if (!linea)
		return (NULL);
	len = ft_strlen(*cache) - (new_line - *cache + 1);
	aux = ft_substr(*cache, new_line - *cache + 1, len);
	free(*cache);
	*cache = aux;
	return (linea);
}

//	Gestiona la cache una vez llegado a eof

char *handle_eof(char **cache)
{
	char	*linea;

	if (!*cache || **cache == '\0')
	{
		free(*cache);
		*cache = NULL;
		return (NULL);
	}
	linea = ft_strdup(*cache);
	free(*cache);
	*cache = NULL;
	return (linea);
}

int	is_new_line(char *cache)
{
	char	*line;
	
	if (!cache)
		return (0);
	line = ft_strchr(cache, '\n');
	if (!line)
		return (0);
	return (1);
}

/*
    - fd es un entero que identifica el proceso ejecutado, los estandar son
    0(stdin), 1(stdout) y 2(stderr)
    - buffer es un puntero al bloque de memoria donde se almacenan los datos
    ha de ser lo suficientemente grande para contener count, si no, concatenar
    - count es el numero de bytes por leer
    - read() retorna el numero de bytes leidos, -1 (error) o 0 (EOF)
*/

char *get_next_line(int fd)
{
	static char	*cache;
	char		texto[BUFF_SIZE + 1];
	char		*linea;
	int			leido;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	while (!is_new_line(cache))
	{
		if (!cache)
			cache = ft_strdup("");
		leido = read(fd, texto, BUFF_SIZE);
		if (leido <= 0)
			return (handle_eof(&cache));
		texto[leido] = '\0';
		cache = update_cache(cache, texto);
		if (!cache)
			return (NULL);
	}
	linea = extract_line(&cache);
	return (linea);
}
