
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>

int             main(int ac,const char **av)
{
        int     fd;
        int     fd2;
        int     fd3;
        char    *line;

        fd = open(av[1], O_RDONLY);
        fd2 = open(av[2], O_RDONLY);
        fd3 = open(av[3], O_RDONLY);
        line = NULL;
        (void)ac;
        while (get_next_line(fd, &line) > 0)
        {
                if (line)
                {
                        printf("%s\n", line);
                        free(line);
                        line = NULL;
                }
        }
        while (get_next_line(fd2, &line) > 0)
        {
                if (line)
                {
                        printf("%s\n", line);
                        free(line);
                        line = NULL;
                }
        }
        while (get_next_line(fd3, &line) > 0)
        {
                if (line)
                {
                        printf("%s\n", line);
                        free(line);
                        line = NULL;
                }
        }
		while(1);
		close(**av);
		return (0);
}
