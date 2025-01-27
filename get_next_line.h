/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:23:36 by adammour          #+#    #+#             */
/*   Updated: 2025/01/27 20:24:37 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 999

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*read_line(int fd, char *str);

char	*get_line(char *str);

char	*clean_line(char *str);

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c);

char	*ft_strjoin(char const *s1, char const *s2);

#endif
