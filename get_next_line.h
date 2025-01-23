/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <skn.aga108@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:23:36 by adammour          #+#    #+#             */
/*   Updated: 2025/01/22 18:57:33 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 5

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char    *read_line(int fd, char *str);

size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c);

char	*ft_strjoin(char const *s1, char const *s2);

#endif
