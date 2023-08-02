/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:28:00 by ttaneski          #+#    #+#             */
/*   Updated: 2023/08/01 16:28:14 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_until_newline(int fd, char *left_str)
{
	char	*buff;
	int		bytes;
	char	*temp;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(left_str, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			free(left_str);
			return (NULL);
		}
		buff[bytes] = '\0';
		temp = ft_strjoin(left_str, buff);
		free(left_str);
		left_str = temp;
	}
	free (buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!left_str)
		left_str = ft_strdup("");
	left_str = ft_read_until_newline(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_read_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}
