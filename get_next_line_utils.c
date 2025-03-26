/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:08:12 by avelandr          #+#    #+#             */
/*   Updated: 2025/03/26 14:30:54 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
