/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:41:43 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/23 11:26:43 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_deg
{
	int		oct;
	char	buf[6];
}t_deg;

static int	isline(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*gnl_strjoin(char *tmp, char *buf, int oct)
{
	char	*new;
	int		i;
	int		j;

	if (ft_salloc(&new, sizeof(char) * (ft_strlen(tmp) + oct + 1)))
		return (NULL);
	i = 0;
	while (tmp && tmp[i])
	{
		new[i] = tmp[i];
		i++;
	}
	j = 0;
	while (oct-- > 0)
	{
		new[i + j] = buf[j];
		j++;
	}
	new[i + j] = 0;
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (new);
}

static char	*ft_strcdup(char *tmp)
{
	int		i;
	char	*newline;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (ft_salloc(&newline, sizeof(char) * (i + 1)))
		return (NULL);
	newline[i] = 0;
	while (i-- > 0)
	{
		newline[i] = tmp[i];
	}
	return (newline);
}

static char	*gnl_substr(char *tmp)
{
	char	*newtmp;
	int		i;
	int		j;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (ft_salloc(&newtmp, sizeof(char) * (ft_strlen(tmp) - i)))
		return (NULL);
	i++;
	j = 0;
	while (tmp[i + j])
	{
		newtmp[j] = tmp[i + j];
		j++;
	}
	newtmp[j] = 0;
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (newtmp);
}

int	get_next_line(int fd, char **line)
{
	t_deg		deg;
	static char	*tmp;

	if (fd <= -1 || !line)
		return (-1);
	deg.oct = 1;
	while (deg.oct != 0 && isline(tmp) == 0)
	{
		deg.oct = read(fd, deg.buf, 5);
		if (deg.oct == -1)
		{
			free(tmp);
			return (-1);
		}
		tmp = gnl_strjoin(tmp, deg.buf, deg.oct);
	}
	*line = ft_strcdup(tmp);
	if (deg.oct == 0)
	{
		free(tmp);
		tmp = NULL;
		return (0);
	}
	tmp = gnl_substr(tmp);
	return (1);
}
