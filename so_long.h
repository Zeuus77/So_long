/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:17:02 by youel-id          #+#    #+#             */
/*   Updated: 2022/12/18 16:17:03 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct	s_data 
{
	void *mlx;
	void *win;
	int count;
	int xp;
	int yp;
	int xp2;
	int yp2;
	int cx;
	int cy;
	int width;
	int Length;
	void *tower2;
	void *wall;
	void *coin;
	void *player1;
	void *grass;
	void *tower;
	char **arr;
	char **arr2;
	int game_end;
	int total_number_of_coins;
	int number_of_player;

}				t_data;

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include <limits.h>
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
char	*get_line_from_save(char *save);
char	*update_save(char *save);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strchr(char *str, char c);
char	*get_next(char *save, int fd, char *buffer);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void check_map(t_data *data);
void exit_game(t_data *data);
void move(t_data *data, int *coin_count);
int key_move(int key,t_data *data);
int ft_key(int key, void *data);
int game_destroy(t_data *data);
int check_walls_player(t_data *data);
int check_coin_exit(t_data *data);
int check_player(t_data *data);
int check_cube(t_data *data);
#endif