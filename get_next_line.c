/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <skn.aga108@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:17:10 by adammour          #+#    #+#             */
/*   Updated: 2025/01/27 18:45:21 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *read_line(int fd, char *str)
{
    char    *buffer;
    char    *new_str;
    int rd;

    rd = 1;
    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;
    if (!str)
    {
        str = malloc(sizeof(char));
        if (!str)
            return(free(buffer), NULL);
        str[0] = '\0'; 
    }
    while (rd > 0 && !ft_strrchr(str, '\n'))
    {
        rd = read(fd, buffer, BUFFER_SIZE);
        if (rd < 0)
            return(free(buffer), NULL);
        buffer[rd] = '\0';
        new_str = ft_strjoin(str, buffer);
        if (!new_str)
            return(free(str), free(buffer), NULL); 
        str = new_str;
    }
    free(buffer);
    return (str);
}

char    *get_line(char *str)
{
    char    *buffer;
    int     i;
    int     j;

    i = 0;
    if(!str)
        return(NULL);
    while (str[i] && str[i] != '\0')
        i++;
    buffer = malloc(sizeof(char) * (i + 2)); // +2 pour recup '\n' et '\0'
    if (!buffer)
        return(free(str), NULL);
    j = 0;
    while (j < i)
    {
        buffer[j] = str[j];
        j++;
    }
    if (str[j] == '\n')
        buffer[j++] = '\n';
    buffer[j] = '\0';
    return (buffer);
}

char    *clean_line(char *str)
{
    char    *buffer;
    int i;
    int j;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!str)
        return (free(str), NULL); // si str echoue libere memoire du 1er malloc
    buffer = malloc(ft_strlen(&str[i]) + 1);
    if(!buffer)
        return (free(str), NULL);
    j = 0;
    while(str[i])
        buffer[j++] = str[i++];
    buffer[j]= '\0';
    free(str);
    return(buffer);
}
char    *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    buffer = read_line(fd, line);
    if (!buffer)
        return(NULL);
    line = get_line(buffer);
    buffer = clean_line(buffer);
    return(line);
}
//malloc la ligne qu'on return a la fin
//parcourir la chaine de caractere jusqu'au \n et copier les caracteres
//return la ligne 
//verifier si il y a un \n a la fin de la ligne si oui l'ajouter

//char    *clean_line(char *str)
//malloc la ligne qui commence au \n et termine a la fin de read_line(fd, str)
//parcourir la chaine de caractere a partir du \n et la copier dans la nouvelle str
//return la chaine de caracteres

#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd;
    char *line;

    fd = open("texte", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    return 0;
}

