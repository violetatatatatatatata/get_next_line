/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:28:18 by avelandr          #+#    #+#             */
/*   Updated: 2025/03/05 15:31:24 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*s3rtn;
	int		i;
	int		j;

	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	s3rtn = s3;
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		s3[j++] = s2[i++];
	s3[j] = '\0';
	return (s3rtn);
}

char	*ft_strdup(char *s)
{
	int		i;
	char		*strdup;

	i = 0;
	strdup = (char *)malloc((ft_strlen(s) + 1));
	if (!strdup)
		return (NULL);
	while (s[i] != '\0')
	{
		strdup[i] = s[i];
		i++;
	}
	strdup[i] = '\0';
	return (strdup);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

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

/*
La función ft_substr genera una subcadena (substring) de una cadena dada (s).
Extrae una parte de la cadena, empezando en un índice específico (start) y con
una longitud máxima (len).
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	char	*subsrtn;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		subs = (char *)malloc(sizeof(char));
		if (!subs)
			return (NULL);
		subs[0] = '\0';
		return (subs);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	subsrtn = subs;
	while (s[start] && len--)
		*subs++ = s[start++];
	*subs = '\0';
	return (subsrtn);
}
