/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:39:19 by tmarkita          #+#    #+#             */
/*   Updated: 2020/02/02 17:53:01 by tmarkita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

void	mino_del(char *map)
{
	int		i;

	--g_c;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == g_c)
			map[i] = '.';
		i++;
	}
}

int		compare(char **arr, int *mino_arr)
{
	int		i;
	int		l;
	int		k;

	l = 0;
	i = -1;
	while (++i < 19)
	{
		k = -1;
		while (++k < (int)(ft_strlen(arr[l])))
		{
			if (ft_strnequ((arr[l] + k), g_mino[i], ft_strlen(g_mino[i])))
			{
				mino_arr[l] = i;
				free(arr[l++]);
				if (l == g_count)
					return (1);
				k = -1;
				i = 0;
			}
		}
	}
	put_error(1);
	return (0);
}

void	put_mino(char *map, int cur_mino, int i)
{
	int l;
	int tmp;

	if (map[i] == '\n')
		i++;
	tmp = i;
	while (tmp >= g_size + 1)
		tmp = tmp - (g_size + 1);
	l = 0;
	while (map[i] != '\0' && g_mino_g[cur_mino][l] != '\0')
	{
		if (g_mino_g[cur_mino][l] == '\n')
			i = i + tmp + ft_strnlen(&map[i], '\n');
		if (map[i] == '.' && g_mino_g[cur_mino][l] == '#')
			map[i] = g_c;
		i++;
		l++;
	}
	g_c++;
}

int		check_pos(char *map, int cur_mino, int i)
{
	int l;
	int flag;
	int tmp;

	if (map[i] == '\n')
		i++;
	tmp = i;
	while (tmp >= g_size + 1)
		tmp = tmp - (g_size + 1);
	l = 0;
	flag = 0;
	while (map[i] != '\0' && g_mino_g[cur_mino][l] != '\0')
	{
		if (g_mino_g[cur_mino][l] == '\n')
			i = i + tmp + ft_strnlen(&map[i], '\n');
		if (map[i] == '.' && g_mino_g[cur_mino][l] == '#')
			flag++;
		i++;
		l++;
	}
	if (flag == 4)
		return (1);
	return (0);
}

int		grid(char *map, int *mino_arr, int pos, int offset)
{
	int len;
	int i;
	int k;

	len = ft_strlen(map);
	i = offset;
	k = offset;
	while (i < len && !(check_pos(map, mino_arr[pos], i)))
		i++;
	if (check_pos(map, mino_arr[pos], i))
	{
		k = i;
		put_mino(map, mino_arr[pos], i);
		if (pos == g_count - 1)
			print_map(map);
		if (!(grid(map, mino_arr, ++pos, 0)))
		{
			mino_del(map);
			grid(map, mino_arr, --pos, ++k);
		}
		else
			return (1);
	}
	return (0);
}
