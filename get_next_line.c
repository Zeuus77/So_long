/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:19:37 by youel-id          #+#    #+#             */
/*   Updated: 2022/12/14 01:37:33 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_from_save(char *save)
{
	int		i;
	char	*ret;

	i = 0;
	if (!save[0])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] && save[i] == '\n')
		i++;
	ret = (char *)malloc(sizeof(char) * i + 1);
	if (!ret)
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		ret[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

char	*update_save(char *save)
{
	int		i;
	int		j;
	char	*new_save;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	new_save = (char *)malloc(sizeof(char) * (ft_strlen(save) - i) + 1);
	i++;
	while (save[i])
		new_save[j++] = save[i++];
	new_save[j] = '\0';
	free(save);
	return (new_save);
}

char	*get_next(char *save, int fd, char *buffer)
{
	int	rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(save);
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		save = ft_strjoin(save, buffer);
		if (ft_strchr(save, '\n'))
			break ;
	}
	//free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save;
	char		*line;

	if (fd < 0 || fd == 1 || fd == 2|| BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	save = get_next(save, fd, buffer);
	if (!save)
		return (NULL);
	line = get_line_from_save(save);
	save = update_save(save);
	return (line);
}

//int main ()
//{
//	int fd = open ("test",O_RDONLY);
//	printf("%s",get_next_line(fd));
//	close(fd);
//	open("test",O_RDONLY);
//	printf("%s",get_next_line(fd));
	
//}