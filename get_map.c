/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:39:09 by tmarkita          #+#    #+#             */
/*   Updated: 2020/02/02 16:14:52 by tmarkita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"
#include <fcntl.h>

char	*create_map(int size)
{
	char	*tmp;
	char	*tmp2;
	int		i;
	int		k;

	tmp = ft_strnew((size * size) + size + 10);
	tmp2 = tmp;
	k = 0;
	while (k < size)
	{
		i = 0;
		while (i < size)
		{
			*tmp2 = '.';
			tmp2++;
			i++;
		}
		*tmp2 = '\n';
		tmp2++;
		k++;
	}
	return (tmp);
}

void	erase_map(char *map)
{
	int		i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '.' && map[i] != '\n')
			map[i] = '.';
		i++;
	}
}

int		map_to_massive(char *map, int *mino_arr)
{
	char	*arr[g_count];
	char	*tmp;
	int		k;
	int		l;

	k = 0;
	l = 0;
	tmp = (char*)malloc(sizeof(char) * 17);
	while (*map != '\0')
	{
		if (k == 17)
		{
			arr[l++] = ft_strsub(&tmp[0], 0, 16);
			k = 0;
			continue;
		}
		if (*map == '\n')
			map++;
		tmp[k++] = *(map++);
	}
	arr[l++] = ft_strsub(&tmp[0], 0, 16);
	free(tmp);
	compare(&arr[0], mino_arr);
	return (1);
}

int		validate(char *map)
{
	int		k;
	int		c;

	c = 0;
	while (*map != '\0')
	{
		k = 0;
		while (*map != '\n' && *(map++) != '\0')
			k++;
		if (c == 4 && *map == '\n')
		{
			map++;
			c = 0;
			continue;
		}
		c++;
		map++;
		if (k != 4)
			return (0);
	}
	if (c != 4)
		return (0);
	if (*(--map) != '\n')
		return (0);
	return (1);
}

int		get_map(char *av, char **map)
{
	int		fd;
	int		ret;

	fd = open(av, O_RDONLY);
	*map = ft_strnew(1024);
	ret = read(fd, *map, 1024);
	(*map)[ret] = '\0';
	close(fd);
	return (1);
}
