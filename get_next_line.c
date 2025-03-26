/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:25:20 by avelandr          #+#    #+#             */
/*   Updated: 2025/03/26 17:44:32 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*read_until_newline(int fd, char **cache, char *texto)
{
	int		leido;
	char	*temp;
	char	*line;

	while (1)
	{
		if (!*cache)
			*cache = ft_strdup("");
		line = ft_strchr(*cache, '\n');
		if (line)
			break ;
		leido = read(fd, texto, BUFFER_SIZE);
		if (leido <= 0)
			return (handle_eof(cache));
		texto[leido] = '\0';
		temp = update_cache(*cache, texto);
		if (!temp)
			return (free(texto), free(*cache), NULL);
		*cache = temp;
	}
	return (NULL);
}

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
