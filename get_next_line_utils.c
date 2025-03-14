/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:11:51 by avelandr          #+#    #+#             */
/*   Updated: 2025/03/14 13:12:19 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strjoin(char *s1, char const *s2)
{
	char    *s3;
	size_t  len_s1;
	size_t  len_s2;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = (char *)malloc(len_s1 + len_s2 + 1);
	if (!s3)
		return (NULL);

	ft_strlcpy(s3, s1, len_s1 + 1);
	ft_strlcpy(s3 + len_s1, s2, len_s2 + 1);

	if (s1)
		free(s1);

	return (s3);
}

char    *ft_strdup(const char *s)
{
	char    *dup;
	size_t  len;

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

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	char    *subs;
	size_t  s_len;

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
