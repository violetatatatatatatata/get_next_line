/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:26:28 by avelandr          #+#    #+#             */
/*   Updated: 2025/03/05 16:10:45 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strdup(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char *update_cache(char *cache, char *texto);
char *extract_line(char **cache);
char *handle_eof(char **cache);
int is_new_line(char *cache);

#endif
