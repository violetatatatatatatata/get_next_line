/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:25:20 by avelandr          #+#    #+#             */
/*   Updated: 2025/03/16 17:55:03 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	update_cache(char **cache, char *buffer, int fd)
{
	char	*temp;
	int		leido;

	if (!*cache)
		*cache = ft_strdup("");
	leido = read(fd, buffer, BUFFER_SIZE);
	if (leido <= 0)
		return (leido);
	buffer[leido] = '\0';
	temp = ft_strjoin(*cache, buffer);
	if (!temp)
		return (-1);
	free(*cache);
	*cache = temp;
	return (ft_strchr(*cache, '\n') != NULL);
}

char	*extract_line(char **cache)
{
	char	*new_line;
	char	*linea;
	char	*aux;
	size_t	len;

	new_line = ft_strchr(*cache, '\n');
	if (!new_line)
		return (NULL);
	len = new_line - *cache + 1;
	linea = ft_substr(*cache, 0, len);
	if (!linea)
		return (NULL);
	len = ft_strlen(*cache) - len;
	if (len > 0)
	{
		aux = ft_substr(*cache, new_line - *cache + 1, len);
		free(*cache);
		*cache = aux;
	}
	else
	{
		free(*cache);
		*cache = NULL;
	}
	return (linea);
}

char	*handle_eof(char **cache, char *buffer)
{
	char	*linea;

	if (buffer)
		free(buffer);
	if (!*cache || **cache == '\0')
	{
		if (*cache)
			free(*cache);
		*cache = NULL;
		return (NULL);
	}
	linea = ft_strdup(*cache);
	free(*cache);
	*cache = NULL;
	return (linea);
}

int	read_and_update_cache(char **cache, char *buffer, int fd)
{
	int	result;

	result = update_cache(cache, buffer, fd);
	if (result == -1)
	{
		free(buffer);
		if (*cache)
		{
			free(*cache);
			*cache = NULL;
		}
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*texto;
	int			result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (handle_eof(&cache, NULL));
	texto = (char *)malloc(BUFFER_SIZE + 1);
	if (!texto)
		return (NULL);
	while (1)
	{
		result = read_and_update_cache(&cache, texto, fd);
		if (result == -1)
			return (NULL);
		if (result == 1)
		{
			free(texto);
			return (extract_line(&cache));
		}
		if (result == 0)
			return (handle_eof(&cache, texto));
	}
}
