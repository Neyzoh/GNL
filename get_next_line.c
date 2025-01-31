/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:17:10 by adammour          #+#    #+#             */
/*   Updated: 2025/01/31 23:32:04 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_check(char *str)
{
	if (!str)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	return (str);
}

char	*read_line(int fd, char *str)
{
	char	*buffer;
	char	*new_str;
	int		rd;

	rd = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	str = ft_check(str);
	if (!str)
		return (free(buffer), NULL);
	while (rd > 0 && !ft_strrchr(str, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (free(buffer), NULL);
		buffer[rd] = '\0';
		new_str = ft_strjoin(str, buffer);
		if (!new_str)
			return (free(str), free(buffer), NULL);
		free(str);
		str = new_str;
	}
	free(buffer);
	return (str);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (free(str), NULL);
    // je dois m'assurer que la chaine line est correctement copié
	i = 0;
	while (str[i] && str[i] != '\n') 
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*clean_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n') 
		i++;
	if (!str)
		return (free(str), NULL);
	line = malloc(ft_strlen(&str[i]) + 1);
	if (!line)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	free(str);
	return (line);
}

#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, buffer); 
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	if (!line || !line[0]) 
	{
		free(buffer);
		buffer = NULL;
		return(NULL);
	}
	buffer = clean_line(buffer);
	free(buffer);
	return (line); 
}


#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("texte", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}

