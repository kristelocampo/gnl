#include "get_next_line_bonus.h"

void                     *ft_calloc(size_t count, size_t size)
{
        void    *str;

        if (count == 0 || size == 0)
        {
                size = 1;
                count = 1;
        }
        if (!(str = malloc(size * count)))
                return (NULL);
        if (size != 0)
        {
                while (size--)
                        ((unsigned char *)str)[size] = '\0';
        }
        return (str);
}

int             check_file(char **tab,char **line, int fd, int ret)
{
        int     i;
        char    *tmp;

        i = 0;
        while (tab[fd][i] && tab[fd][i] != '\n')
                i++;
        *line = ft_substr(tab[fd], 0, i);
        tmp = tab[fd][i] ? ft_strdup(tab[fd] + i + 1) : NULL;
        free(tab[fd]);
        tab[fd] = tmp;
        if (ret != 0 || tab[fd])
                return (1);
        return (0);
}
int             get_next_line(int fd, char **line)
{
        char            buffer[BUFFER_SIZE + 1];
        static char     *tab[MAX_FD];
        int             ret;

        if (fd < 0 || BUFFER_SIZE <= 0 || !line)
                return (-1);
        if (!tab[fd])
                tab[fd] = ft_calloc(0, 0);
        while (!ft_strchr(tab[fd], '\n') && (ret = read(fd, buffer, BUFFER_SIZE)) > 0)
        {
                buffer[ret] = '\0';
                tab[fd] = ft_strjoin(tab[fd], buffer);
        }
        if (ret == -1)
                return (-1);
        return (check_file(tab, line, fd, ret));
}