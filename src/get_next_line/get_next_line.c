/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/14 20:15:26 by mdraper       #+#    #+#                 */
/*   Updated: 2024/03/20 12:04:24 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fn(char **ptr)
{
	if (*ptr)
	{
		free (*ptr);
		*ptr = NULL;
	}
}

char	*ft_read_file(int fd, char **line, char **rem, char *buf)
{
	int	read_count;

	read_count = 1;
	while (ft_pos(buf, '\n') == -1 && read_count != 0)
	{
		read_count = read(fd, buf, BUFFER_SIZE);
		if (read_count == -1)
			return (ft_fn(&buf), NULL);
		else if (read_count == 0)
			return (ft_fn(rem), ft_fn(&buf), *line);
		buf[read_count] = '\0';
		if (ft_pos(buf, '\n') == -1)
			*line = ft_gnl_strjoin(*line, buf);
		else
		{
			*line = ft_gnl_strjoin(*line, buf);
			if (!*line)
				return (ft_fn(rem), ft_fn(&buf), NULL);
			*rem = ft_gnl_strdup(buf);
			if (ft_pos(buf, '\n') != (int)ft_strlen(buf) && !*rem)
				return (ft_fn(line), ft_fn(&buf), NULL);
		}
	}
	return (ft_fn(&buf), *line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	char		*buf;
	static char	*rem[8192];

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, NULL, 0) == -1)
		return (ft_fn(&rem[fd]), NULL);
	if (rem[fd])
	{
		if (ft_pos(rem[fd], '\n') != -1)
		{
			tmp = rem[fd];
			line = ft_gnl_strjoin(line, rem[fd]);
			if (!line)
				return (ft_fn(&rem[fd]), NULL);
			return (rem[fd] = ft_gnl_strdup(rem[fd]), ft_fn(&tmp), line);
		}
		line = rem[fd];
		rem[fd] = NULL;
	}
	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (ft_fn(&line), NULL);
	return (ft_read_file(fd, &line, &rem[fd], buf));
}

// // #include "ft_printf.h"
// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	char	*line1;
// 	char	*line2;
// 	char	*line3;
// 	int		count;

// 	fd1 = open("example1.txt", O_RDONLY);
// 	fd2 = open("example2.txt", O_RDONLY);
// 	fd3 = open("example3.txt", O_RDONLY);
// 	ft_printf("fd1: %d\n", fd1);
// 	ft_printf("fd2: %d\n", fd2);
// 	ft_printf("fd3: %d\n", fd3);

// 	ft_printf("\n\n\n");
// 	count = 0;
// 	while (1)
// 	{
// 		line1 = get_next_line(fd1);
// 		line2 = get_next_line(fd2);
// 		line3 = get_next_line(fd3);
// 		count++;
// 		if (!line1 && !line2 && !line3)
// 			break ;
// 		if (line1)
// 			ft_printf("line1 [%d]:%s", count, line1);
// 		if (line2)
// 			ft_printf("line2 [%d]:%s", count, line2);
// 		if (line3)
// 			ft_printf("line3 [%d]:%s", count, line3);
// 		ft_printf("\n---newline---\n");
// 		ft_fn(&line1);
// 		ft_fn(&line2);
// 		ft_fn(&line3);
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }
