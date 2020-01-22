#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

# include <unistd.h>
# include <stdlib.h>
# define MAX_FD 4096


int         get_next_line(int fd, char **line);
char        *ft_substr(char const *str, unsigned int start, size_t len);
char        *ft_strchr(const char *s, int c);
char        *ft_strjoin(const char *s1, const char *s2);
char        *ft_strdup(const char *s1);
size_t      ft_strlen(const char *str);
#endif