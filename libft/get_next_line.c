/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:28:00 by ttaneski          #+#    #+#             */
/*   Updated: 2023/07/12 14:28:38 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_read_until_newline(int fd, char *left_str)
{
	char *buff;
	int bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return NULL;
	bytes = 1;
	while (!ft_strchr(left_str, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			free(left_str);
			return NULL;
		}
		buff[bytes] = '\0';

		// Create a temporary variable to hold the result of ft_strjoin
		char *temp = ft_strjoin(left_str, buff);
		free(left_str);  // Free the previous value of left_str
		left_str = temp; // Assign the updated value to left_str
	}
	free(buff);
	return left_str;
}


char *get_next_line(int fd)
{
	char *line;
	static char *left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!left_str)
		left_str = ft_strdup("");
	left_str = ft_read_until_newline(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_read_line(left_str);
	left_str = ft_new_left_str(left_str);
	return line;
}

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	// while (1)
	// {
		line = get_next_line(fd);
		printf("%s", line);
		free(line);

		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	// }
	return (0);
} */

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
