/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:49:20 by alpicard          #+#    #+#             */
/*   Updated: 2022/11/20 16:09:52 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *save)
{
	int		read_bytes;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while ((ft_strchr(save, '\n') == 0 || !save) && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(save);
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = 0;
		save = ft_strjoin(save, buff);
		if (!save)
			return (ft_free(buff));
	}
	free(buff);
	return (save);
}

char	*ft_save(char *save)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (ft_free(save));
	ret = malloc((ft_strlen(save) - i) + 1);
	if (!ret)
		return (NULL);
	i++;
	j = 0;
	while (save && save[i])
		ret[j++] = save[i++];
	ret[j] = 0;
	free(save);
	save = NULL;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
		return (ft_free(save));
	line = ft_substr(save, '\n');
	save = ft_save(save);
	if (!line)
		return (ft_free(save));
	return (line);
}
