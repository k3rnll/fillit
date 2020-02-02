/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 08:56:28 by tmarkita          #+#    #+#             */
/*   Updated: 2020/02/02 17:19:46 by tmarkita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

void	init_second(void)
{
	g_mino[0] = "####";
	g_mino[1] = "##..#...#.";
	g_mino[2] = "##...#...#";
	g_mino[3] = "#...#...##";
	g_mino[4] = ".#...#..##";
	g_mino[5] = "#...###";
	g_mino[6] = "..#.###";
	g_mino[7] = "###.#..";
	g_mino[8] = "###...#";
	g_mino[9] = "#...#...#...#";
	g_mino[10] = "##..##";
	g_mino[11] = "##...##";
	g_mino[12] = ".##.##.";
	g_mino[13] = ".#..##..#.";
	g_mino[14] = "#...##...#";
	g_mino[15] = ".#..###";
	g_mino[16] = "###..#.";
	g_mino[17] = ".#..##...#";
	g_mino[18] = "#...##..#.";
}

void	init(void)
{
	g_c = 'A';
	g_mino_g[0] = "####\n";
	g_mino_g[1] = "##\n#.\n#.\n";
	g_mino_g[2] = "##\n.#\n.#\n";
	g_mino_g[3] = "#.\n#.\n##\n";
	g_mino_g[4] = ".#\n.#\n##\n";
	g_mino_g[5] = "#..\n###\n";
	g_mino_g[6] = "..#\n###\n";
	g_mino_g[7] = "###\n#..\n";
	g_mino_g[8] = "###\n..#\n";
	g_mino_g[9] = "#\n#\n#\n#\n";
	g_mino_g[10] = "##\n##\n";
	g_mino_g[11] = "##.\n.##\n";
	g_mino_g[12] = ".##\n##.\n";
	g_mino_g[13] = ".#\n##\n#.\n";
	g_mino_g[14] = "#.\n##\n.#\n";
	g_mino_g[15] = ".#.\n###\n";
	g_mino_g[16] = "###\n.#.\n";
	g_mino_g[17] = ".#\n##\n.#\n";
	g_mino_g[18] = "#.\n##\n#.\n";
	init_second();
}

int		main(int ac, char **av)
{
	char	*map;
	int		*mino_arr;

	if (ac != 2)
		put_error(1);
	get_map(av[1], &map);
	if (!(validate(map)))
		put_error(1);
	init();
	g_count = count_minos(&map);
	validate_minos(&map);
	mino_arr = ft_memalloc(g_count);
	map_to_massive(map, mino_arr);
	free(map);
	g_size = square(g_count);
	map = create_map(g_size);
	while (g_size < 20)
	{
		grid(map, mino_arr, 0, 0);
		free(map);
		map = create_map(++g_size);
	}
}
