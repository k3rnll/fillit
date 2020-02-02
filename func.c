/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:38:56 by tmarkita          #+#    #+#             */
/*   Updated: 2020/02/02 16:14:52 by tmarkita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

void	put_error(int var)
{
	if (var == 1)
	{
		write(1, "error\n", 6);
		exit(0);
	}
}

void	validate_minos(char **map)
{
	int		total;
	int		i;

	total = 0;
	i = 0;
	while ((*map)[i] != '\0')
	{
		if ((*map)[i] == '#')
			total++;
		i++;
	}
	if (total > g_count * 4)
	{
		write(1, "error\n", 6);
		exit(0);
	}
}

int		count_minos(char **map)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while ((*map)[i] != '\0')
	{
		if ((*map)[i] == '\n' && (*map)[i + 1] == '\n')
			count++;
		i++;
	}
	return (count + 1);
}

void	print_map(char *map)
{
	while (*map != '\0')
	{
		write(1, map, 1);
		map++;
	}
	exit(0);
}

int		square(int mino_nums)
{
	int	sqr;
	int i;

	i = 0;
	if (mino_nums < 5)
		return (2);
	sqr = mino_nums * 4;
	while ((i * i) < sqr)
		i++;
	return (i);
}
