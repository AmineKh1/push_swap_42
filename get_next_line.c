/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:43:18 by akhouya           #+#    #+#             */
/*   Updated: 2022/06/11 17:01:34 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_free(char *s, char c)
{
	char	*r;
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	r = malloc((i + 2) * sizeof(char));
	if (!r)
		return (NULL);
	i = 0;
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	r[i++] = c;
	r[i] = '\0';
	free(s);
	return (r);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buff;
	int		ret;
	int		i;

	i = 0;
	if (fd < 0)
		return (NULL);
	line = ft_strdup("");
	ret = read(fd, &buff, 1);
	while (ret > 0)
	{
		line = ft_strjoin_free(line, buff);
		if (buff == '\n')
			break ;
		ret = read(fd, &buff, 1);
	}
	while (line[i])
		i++;
	if (i == 0 || ret == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
