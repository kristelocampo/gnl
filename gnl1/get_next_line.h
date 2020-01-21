/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krisocam <krisocam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:26:04 by krisocam          #+#    #+#             */
/*   Updated: 2019/12/02 18:47:05 by krisocam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
#endif

size_t		    ft_strlen(const char *str);
char		    *ft_strdup(const char *s1);
char            *ft_substr(char const *str, unsigned int start, size_t len);
char			*ft_join(char *s1, char *s2);
void		    ft_strdel(char **str);
int			    get_next_line(int fd, char **line);

#endif
