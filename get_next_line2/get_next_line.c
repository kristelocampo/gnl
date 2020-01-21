/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krisocam <krisocam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:15:59 by krisocam          #+#    #+#             */
/*   Updated: 2020/01/21 17:21:54 by krisocam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int                                     ft_read(int fd, char *buffer, char **tab)
{
        int             ret;

        while (!ft_strchr(tab[fd], '\n') &&
                (ret = read(fd, buffer, BUFFER_SIZE)) > 0)
        {
                buffer[ret] = '\0';
                tab[fd] = ft_strjoin(tab[fd], buffer);
        }
        return (ret);
}

int                                     get_next_line(int fd, char **line)
{
        char            buffer[BUFFER_SIZE + 1];
        int                     ret;
        int                     i;
        static char     *tab[MAX_FD];
        char            *tmp;

        if (fd < 0 || BUFFER_SIZE <= 0 || !line)
                return (-1);
        if (!tab[fd])
                tab[fd] = ft_calloc(0, 0);
        if ((ret = ft_read(fd, buffer, tab)) == -1)
                return (-1);
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