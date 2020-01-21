/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:27:07 by krisocam          #+#    #+#             */
<<<<<<< HEAD:gnl1/get_next_line.c
/*   Updated: 2019/12/04 15:36:31 by krisocam         ###   ########.fr       */
=======
/*   Updated: 2019/12/03 17:26:35 by marvin           ###   ########.fr       */
>>>>>>> 44b20b8ae4935217650c5b38bb9f0b164a7209c1:get_next_line.c
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		read_file(char *tab[], int fd, char *tmp)
{
	char	buffer[BUFFER_SIZE + 1];
	int		ret;

	if ((ret = read(fd, buffer, BUFFER_SIZE)) == 0)
		return (0);
	buffer[ret] = '\0';
	tmp = ft_strjoin(tab[fd], buffer);
	ft_strdel(&tab[fd]);
	tab[fd] = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (1);
}

static int		check_line(char *tab[], char **line)
{
	if (!tab || !line)
		return (-1);
	*line = ft_strdup(*tab);
	if (tab)
		while (*tab)
			*tab++ = '\0';
	return (1);
}

int				get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*tab[MAX_FD];
	char		*tmp;
	char		*dest;
	
	if (!line || fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (-1);
	if (!tab[fd])
		tab[fd] = malloc(1);
	tmp = NULL;
	while (dest = ft_strchr(tab[fd], '\n') == NULL)
		if((read_file(tab, fd, tmp)) == 0)
			break;
	if (ft_strlen(tab[fd] != 0))
	{
		check_line(&tab[fd], &*line);
		*dest = '\0';
		tmp = ft_strdup(dest + 1);
		*line = ft_strdup(tab[fd]);
		ft_strdel(&tab[fd]);
		tab[fd] = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else
		return (0);
	return (1);
	
}