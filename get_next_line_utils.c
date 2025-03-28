/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:08:12 by avelandr          #+#    #+#             */
/*   Updated: 2025/03/27 22:10:43 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/***************************************************************************
	- Verifica si la cadena s es NULL. Si es así, retorna NULL.
	- Calcula la longitud de la cadena s utilizando la función ft_strlen.
	- Reserva memoria para una nueva cadena dup con una longitud de len + 1.
	- Si la reserva de memoria falla, retorna NULL.
	- Copia la cadena s en la nueva cadena dup utilizando la función ft_strlcpy.
	- Retorna la nueva cadena dup.
***************************************************************************/

char	*ft_strdup(const char *s)
{
	char		*dup;
	size_t		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, len + 1);
	return (dup);
}

/***************************************************************************
	- Verifica si la cadena s es NULL. Si es así, retorna 0.
	- Inicializa un contador i a 0.
	- Recorre la cadena s caracter por caracter hasta encontrar el carácter
	  nulo \0.
	- Incrementa el contador i por cada carácter no nulo encontrado.
	- Retorna el valor del contador i, que representa la longitud de la cadena.
***************************************************************************/

unsigned long long	ft_strlen(const char *s)
{
	unsigned long long	i;

	if (!s)
		return (0);
	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

/***************************************************************************
	- Inicializa un índice i a 0.
	- Recorre la cadena s caracter por caracter.
	- Si encuentra el carácter c en s[i], retorna un puntero a s[i].
	- Si no encuentra el carácter y llega al final de la cadena, verifica si c
	  es el carácter nulo \0. Si es así, retorna un puntero al carácter nulo.
	- Si no encuentra el carácter c, retorna NULL.
***************************************************************************/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/***************************************************************************
    - Verifica si la cadena s es NULL. Si es así, retorna NULL.
    - Calcula la longitud de la cadena s utilizando la función ft_strlen.
    - Si el índice start es mayor o igual a la longitud de la cadena,
      retorna una cadena vacía.
    - Si la longitud desde start hasta el final de la cadena s es menor que
      len, ajusta len al valor adecuado.
    - Reserva memoria para una nueva cadena subs con una longitud de len + 1.
    - Si la reserva de memoria falla, retorna NULL.
    - Copia la subcadena desde s[start] hasta s[start + len] en la nueva
      cadena subs utilizando la función ft_strlcpy.
    - Retorna la nueva cadena subs.
***************************************************************************/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*subs;
	size_t		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, s + start, len + 1);
	return (subs);
}

/***************************************************************************
	- Inicializa un contador src_len a 0 y un índice i a 0.
	- Verifica si dst o src son NULL. Si es así, retorna 0.
	- Calcula la longitud de la cadena src recorriéndola hasta encontrar el
	  carácter nulo \0.
	- Si size es 0, retorna src_len.
	- Copia hasta size - 1 caracteres de src a dst.
	- Asegúrate de que dst esté siempre terminada en nulo agregando \0 en
	  dst[size - 1].
	- Retorna src_len.
***************************************************************************/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			src_len;
	size_t			i;
	unsigned char	*dst_aux;
	unsigned char	*src_aux;

	src_len = 0;
	i = 0;
	dst_aux = (unsigned char *) dst;
	src_aux = (unsigned char *) src;
	if (!dst || !src)
		return (0);
	while (src_aux[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	while (i < (size - 1) && src_aux[i] != '\0')
	{
		dst_aux[i] = src[i];
		i++;
	}
	dst_aux[i] = '\0';
	return (src_len);
}
