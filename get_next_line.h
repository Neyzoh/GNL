/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:23:36 by adammour          #+#    #+#             */
/*   Updated: 2025/01/31 22:53:42 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 18
#endif

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*read_line(int fd, char *str);

char	*ft_get_line(char *str);

char	*clean_line(char *str);

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c);

char	*ft_strjoin(char const *s1, char const *s2);

#endif
