/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <skn.aga108@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:23:36 by adammour          #+#    #+#             */
/*   Updated: 2025/01/30 20:56:02 by adammour         ###   ########.fr       */
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

//char	*ft_strjoin_free(char *s1, char const *s2);

char	*clean_line(char *str);

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c);

char	*ft_strjoin(char const *s1, char const *s2);

#endif
