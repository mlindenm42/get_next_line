/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:04:07 by mlindenm          #+#    #+#             */
/*   Updated: 2022/10/19 20:53:19 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[FD_SETSIZE];
	char		*output;

	if (fd < 0 || fd >= FD_SETSIZE)
		return (NULL);
	if (buffer[fd] == NULL)
		if (!allocate_str(&buffer[fd], BUFFER_SIZE))
			return (NULL);
	if (!allocate_str(&output, BUFFER_SIZE))
	{
		free_str(&buffer[fd]);
		return (NULL);
	}
	while (check_new_line(buffer[fd]) == 0)
	{
		if (*buffer[fd] != '\0')
			if (!buffer_to_str(&buffer[fd], &output))
				return (NULL);
		if (!read_line(fd, &buffer[fd], &output))
			return (output);
	}
	buffer_to_str(&buffer[fd], &output);
	return (output);
}

int	buffer_to_str(char **buffer, char **str)
{
	int	i;
	int	j;
	int	str_length;

	i = 0;
	j = 0;
	str_length = 0;
	while (*(*str + str_length) != '\0')
		str_length++;
	if ((str_length + BUFFER_SIZE) > BUFFER_SIZE)
		if (!expand_str(str, str_length))
			return (0);
	while (*(*buffer + i) != '\n' && *(*buffer + i) != '\0')
	{
		*(*str + str_length++) = *(*buffer + i);
		*(*buffer + i++) = '\0';
	}
	if (*(*buffer + i++) == '\n')
		*(*str + str_length++) = '\n';
	*(*str + str_length) = '\0';
	while (i < BUFFER_SIZE)
		*(*buffer + j++) = *(*buffer + i++);
	*(*buffer + j) = '\0';
	return (1);
}

int	read_line(int fd, char **buffer, char **str)
{
	ft_bzero(*buffer, BUFFER_SIZE);
	if (read(fd, *buffer, BUFFER_SIZE) <= 0)
	{
		if (*buffer != NULL)
			free_str(buffer);
		if (**str != '\0')
			return (0);
		free_str(str);
		return (0);
	}
	return (1);
}
