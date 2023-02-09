/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:51:14 by alpicard          #+#    #+#             */
/*   Updated: 2022/11/20 14:38:50 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *save, int c);
void	*ft_free(void *p);
char	*ft_save(char *save);
char	*ft_read(int fd, char *save);

#endif
