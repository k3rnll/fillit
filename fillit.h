/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 12:45:59 by tmarkita          #+#    #+#             */
/*   Updated: 2020/02/02 17:56:18 by tmarkita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

void	put_mino(char *map, int cur_mino, int i);
int		check_pos(char *map, int cur_mino, int i);
int		grid(char *map, int *mino_arr, int pos, int offset);
int		square(int mino_nums);
void	validate_minos(char **map);
char	*create_map(int size);
void	erase_map(char *map);
void	mino_del(char *map);
int		get_map(char *av, char **map);
int		convert_map(char **map);
int		validate(char *map);
int		count_minos(char **map);
int		map_to_massive(char *map, int *mino_arr);
int		compare(char **arr, int *mino_arr);
void	print_map(char *map);
void	init(void);
void	init_second(void);
void	put_error(int var);
int		ft_strnlen(char *str, char c);

char *g_mino_g[19];
char *g_mino[19];
char g_c;
int g_size;
int g_count;
#endif
