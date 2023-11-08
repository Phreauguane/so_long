/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:04:11 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/24 17:00:17 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	process_rest(char rest[BUFFER_SIZE], char **line)
{
	int	i;
	int	j;

	i = 0;
	while (rest[i] != '\n' && rest[i] != '\0' && i++ < BUFFER_SIZE);
	if (rest[0] == '\n')
		*line = str_addc(*line, '\n');
	else if (i > 0 || rest[i] == '\n')
		*line = str_adds(*line, rest, i + 1);
	j = 0;
	while (j < BUFFER_SIZE)
	{
		if (j + i + 1 < BUFFER_SIZE)
			rest[j] = rest[j + i + 1];
		else
			rest[j] = 0;
		j++;
	}
}

char	*get_next_line(int fd)
{
	static char	rest[4096][BUFFER_SIZE];
	char		buff[BUFFER_SIZE];
	char		*line;
	int			rsize;

	line = NULL;
	rsize = 1;
	if (fd < 0)
		return (NULL);
	process_rest(rest[fd], &line);
	while (stchr(line, '\n') == 0 && rsize > 0)
	{
		rsize = 0;
		while (rsize < BUFFER_SIZE)
			buff[rsize++] = 0;
		rsize = read(fd, buff, BUFFER_SIZE);
		if (rsize < 0 && line)
			free(line);
		if (rsize < 0)
			return (NULL);
		ft_memcpy(rest[fd], buff, rsize);
		if (rsize > 0)
			process_rest(rest[fd], &line);
	}
	return (line);	
}
