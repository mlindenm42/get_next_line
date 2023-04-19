/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:24:39 by mlindenm          #+#    #+#             */
/*   Updated: 2022/10/18 15:10:50 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
		*(ptr + i++) = '\0';
	return (s);
}

int	allocate_str(char **str, int length)
{
	*str = (char *)malloc((length + 1) * sizeof(char));
	if (*str == NULL)
		return (0);
	ft_bzero(*str, (length + 1));
	return (1);
}

void	free_str(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

int	check_new_line(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i++) == '\n')
			return (1);
	}
	return (0);
}

int	expand_str(char **str, int str_length)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	if (!allocate_str(&temp, str_length))
		return (0);
	while ((i++) < str_length)
		*(temp + i - 1) = *(*str + i - 1);
	i = 0;
	free_str(str);
	if (!allocate_str(str, str_length + BUFFER_SIZE))
	{
		free_str(&temp);
		return (0);
	}
	while ((i++) < str_length)
		*(*str + i - 1) = *(temp + i - 1);
	free_str(&temp);
	return (1);
}
