/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <skn.aga108@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:17:10 by adammour          #+#    #+#             */
/*   Updated: 2025/01/23 17:11:13 by adammour         ###   ########.fr       */
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
        str = malloc(sizeof(char));
    while (rd > 0 && !ft_strrchr(str, '\n'))
    {
        rd = read(fd, buffer, BUFFER_SIZE);
        buffer[rd] = '\0';
        new_str = ft_strjoin(str, buffer);
        if(!new_str)
            return (NULL);
        //free(str);
        str = new_str;
    }
    free(buffer);
    return(str);
}
char    *get_line(char *str)
{
    char    *line;
    int     i;
    int     j;

    i = 0;
    while (str[i] && str[i] != '\0')
        i++;
    if(str[i] == '\n')
        i++;
    line = malloc(sizeof(char *) * (i + 1));
    if (!line)
        return(NULL);
    j = 0;
    while (str[j] && str[j] == '\n')
    {
        line[j] = str[j];
        j++;
    }
    if (str[j] == '\n')
        line[j++] = '\n';
    line[j] = '\0';
    return (line);
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
int main()
{
    int fd;

    fd = open("texte", O_RDONLY);
    
    char *str = "";
    printf("%s", read_line(fd, str));
}
