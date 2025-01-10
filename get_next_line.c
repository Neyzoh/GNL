/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:17:10 by adammour          #+#    #+#             */
/*   Updated: 2025/01/07 21:17:10 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *read_line(int fd, char *str)
{
    char    *buf;
    int rd;

    if (!str)
        str = ft_calloc(1, 1);
    buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    rd = 1;
    while (rd > 0)
    {
        //concatenation des buffers 
        // rechercher le \n a chauqe strjoin 
            //si \n break boucle while
    }
    
}

char    *get_line(char *str)
//malloc la ligne qu'on return a la fin
//parcourir la chaine de caractere jusqu'au \n et copier les caracteres
//return la ligne 
//verifier si il y a un \n a la fin de la ligne si oui l'ajouter

char    *clean_line(char *str)
//malloc la ligne qui commence au \n et termine a la fin de read_line(fd, str)
//parcourir la chaine de caractere a partir du \n et la copier dans la nouvelle str
//return la chaine de caracteres

char    *get_next_line(int fd)
{
    static char    *buffer;
    //str = read_line(fd, buffer);
    //line = get_line(str);
    //buffer = clean_line(str);

}