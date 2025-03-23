/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:25:20 by avelandr          #+#    #+#             */
/*   Updated: 2025/03/23 14:59:27 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_cache(char *cache, char *buffer)
{
	char	*new_cache;

	if (!cache)
		return (ft_strdup(buffer));
	new_cache = ft_strjoin(cache, buffer);
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
		{
			free(*cache);
			*cache = NULL;
			return (NULL);
		}
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

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*texto;
	char		*linea;
	int			leido;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (cache)
		{
			free(cache);
			cache = NULL;
		}
		return (NULL);
	}
	texto = (char *)malloc(BUFFER_SIZE + 1);
	if (!texto)
		return (NULL);
	while (!is_new_line(cache))
	{
		if (!cache)
			cache = ft_strdup("");
		leido = read(fd, texto, BUFFER_SIZE);
		if (leido <= 0)
		{
			free(texto);
			return (handle_eof(&cache));
		}
		texto[leido] = '\0';
		temp = update_cache(cache, texto);
		if (!temp)
		{
			free(texto);
			free(cache);
			return (NULL);
		}
		cache = temp;
	}
	free(texto);
	linea = extract_line(&cache);
	return (linea);
}
