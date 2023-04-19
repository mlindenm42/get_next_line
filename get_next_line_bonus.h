/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:04:45 by mlindenm          #+#    #+#             */
/*   Updated: 2022/10/20 13:37:36 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

char	*get_next_line(int fd);
void	*ft_bzero(void *s, size_t n);
int		allocate_str(char **str, int length);
void	free_str(char **str);
int		check_new_line(char *str);
int		expand_str(char **str, int str_length);
int		buffer_to_str(char **buffer, char **str);
int		read_line(int fd, char **buffer, char **str);

#endif
