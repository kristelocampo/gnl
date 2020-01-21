/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krisocam <krisocam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:16:01 by krisocam          #+#    #+#             */
/*   Updated: 2020/01/21 17:08:46 by krisocam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t         ft_strlen(const char *str)
{
    size_t    i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char        *ft_strdup(const char *s1)
{
    char    *s2;
    int     i;

    if (!s1)
        return (NULL);
    if (!(s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
        return (NULL);
    i = 0;
    while (s1[i])
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}

char        *ft_strjoin(const char *s1, const char *s2)
{
    int             i;
    int             j;
    char    *str;

        i = 0;
        j = 0;
        if (!s1 || !s2)
                return (NULL);
        if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
                return (NULL);
        while (s1[i] != '\0')
        {
                str[i] = s1[i];
                i++;
        }
        while (s2[j] != '\0')
        {
                str[i + j] = s2[j];
                j++;
        }
        str[i + j] = '\0';
        if (s1)
                free((char*)s1);
        return (str);
}

char    *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    if (!s)
        return (NULL);
    while (s[i])
    {
        if (s[i] == (char)c)
            return ((char*)s + i);
        ++i;
    }
    if (c != '\0')
        return (NULL);
    return ((char*)s + i);
}

char    *ft_substr(char const *str, unsigned int start, size_t len)
{
    unsigned int    i;
    char            *tab;

    i = 0;
    if (!str)
        return (NULL);
    if (!(tab = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    if (start < len)
    {
        while (str[start + i] && i < len)
        {
            tab[i] = str[start + i];
            i++;
        }
    }
    tab[i] = '\0';
    return (tab);
}