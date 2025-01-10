/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:23:36 by adammour          #+#    #+#             */
/*   Updated: 2025/01/07 21:23:36 by adammour         ###   ########.fr       */
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

char    *clean_line(char *str);

char    *get_next_line(int fd, void *buf, size_t count);

#endif
