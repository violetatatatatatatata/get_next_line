/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:26:28 by avelandr          #+#    #+#             */
/*   Updated: 2025/03/16 17:55:14 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char			*extract_line(char **cache);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*get_next_line(int fd);
char			*handle_eof(char **cache, char *buffer);
int				read_and_update_cache(char **cache, char *buffer, int fd);
int				update_cache(char **cache, char *buffer, int fd);
unsigned long	ft_strlen(const char *s);

#endif
