/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:21:15 by alpicard          #+#    #+#             */
/*   Updated: 2022/11/22 09:30:30 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_free(void *p)
{
	if (p)
		free(p);
	return (0x0);
}

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (ft_free(s1));
		s1[0] = 0;
	}
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	join = malloc((i + j) + 1);
	if (!join)
		return (ft_free(s1));
	i = -1;
	j = -1;
	while (s1[++i])
		join[i] = s1[i];
	while (s2[++j])
		join[i + j] = s2[j];
	join[i + j] = 0;
	free(s1);
	return (join);
}

char	*ft_substr(char *save, int c)
{
	int		i;
	char	*buff;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != c)
		i++;
	if (save[i] == '\n')
		i++;
	buff = malloc(i + 1);
	if (!buff)
		return (NULL);
	i = -1;
	while (save[++i] && save[i] != c)
		buff[i] = save[i];
	if (save[i] == 10)
	{
		buff[i] = save[i];
		i++;
	}
	buff[i] = 0;
	return (buff);
}
