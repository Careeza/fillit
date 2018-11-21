/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:53:14 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/20 15:55:22 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reader(const int fd, char *buf, int *ret)
{
	char	temp[BUFF_SIZE + 1];
	char	*tempdel;

	*ret = read(fd, temp, BUFF_SIZE);
	temp[*ret] = '\0';
	tempdel = buf;
	if (!(buf = ft_strjoin(buf, temp)))
		return (NULL);
	ft_strdel(&tempdel);
	return (buf);
}

int		ft_copy_end(char **line, char **buf)
{
	if (!(*line = ft_strdup(*buf)))
		return (-1);
	ft_bzero(*buf, ft_strlen(*buf));
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buf = "";
	char		*str;
	int			ret;

	ret = 1;
	if (fd == -1 || line == NULL || (buf[0] == '\0' && (!(buf = ft_strnew(0)))))
		return (-1);
	while (ret > 0)
	{
		if ((str = ft_strchr(buf, '\n')) != NULL)
		{
			*str = '\0';
			if (!(*line = ft_strdup(buf)))
				return (-1);
			ft_memmove(buf, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		if (!(buf = ft_reader(fd, buf, &ret)))
			return (-1);
	}
	ft_strdel(&str);
	if (ret == 0 && ft_strlen(buf))
		ret = ft_copy_end(&(*line), &buf);
	return (ret);
}
