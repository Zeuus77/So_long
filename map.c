/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:30:12 by youel-id          #+#    #+#             */
/*   Updated: 2022/12/24 15:30:13 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
void check_map(t_data *data)
{
	data->total_number_of_coins = 0;
	int x = 0;
	int y = 0;
	data->tower = mlx_xpm_file_to_image(data->mlx, "NightBorne_idle/tower2.xpm", &x, &y);
	data->wall = mlx_xpm_file_to_image(data->mlx, "NightBorne_idle/wall.xpm", &x, &y);
	data->grass = mlx_xpm_file_to_image(data->mlx, "NightBorne_idle/grass.xpm", &x, &y);
	data->player1 = mlx_xpm_file_to_image(data->mlx, "NightBorne_idle/player1.xpm", &x, &y);
	data->coin = mlx_xpm_file_to_image(data->mlx, "NightBorne_idle/coin.xpm", &x, &y);
	int i;
	int j;
	i=-1;
	while(data->arr[++i])
	{
		j=-1;
		while(data->arr[i][++j])
		{
			if (data->arr[i][j] == '1')
			{
				mlx_put_image_to_window(data->mlx,data->win,data->grass, j*50,i*50);
				mlx_put_image_to_window(data->mlx, data->win, data->wall, j*50,i*50);
			}
			if(data->arr[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx,data->win,data->grass, j*50,i*50);
				mlx_put_image_to_window(data->mlx,data->win,data->tower, j*50,i*50);
			}
			if(data->arr[i][j] == '0')
				mlx_put_image_to_window(data->mlx,data->win,data->grass, j*50,i*50);
			if(data->arr[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx,data->win,data->grass, j*50,i*50);
				mlx_put_image_to_window(data->mlx,data->win,data->player1, j*50,i*50);
				data->xp = j ;
				data->yp = i ;
				data->number_of_player++;

			}
			if(data->arr[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx,data->win,data->grass, j*50,i*50);
				mlx_put_image_to_window(data->mlx,data->win,data->coin,j*50,i*50);
				data->cx = j;
				data->cy = i;
				data->total_number_of_coins++;
			} 
			
		}
	}
	printf("%d\n",data->total_number_of_coins);
}
int main(int ac,char **av)
{
	t_data data;
	int fd;
	int key;
	int i = 0;
	//int line_counter;
	//line_counter =0;
	if(ac == 2)
	{
		fd =open(av[1],O_RDONLY);
		if(fd < 1)
		{
			printf("%s","Error\n");
			return 0;
		}
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, 34*50, 9*50, "so_long");
		char *total;
		total = NULL;
		while(1)
		{
			char *tmp = get_next_line(fd);
			if(!tmp)
				break;
			//line_counter++;
			total = ft_strjoin(total,tmp);
		}
		
		data.arr = ft_split(total,'\n');		
		i=-1;
		while(data.arr[++i])
			//printf("%s\n",data.arr[i]);
		
		if(!check_coin_exit(&data) || !check_walls_player(&data) || check_player(&data))
			exit(0);
		if(!check_cube(&data))
			exit(0);
		check_map(&data);
		mlx_key_hook(data.win, key_move, &data);
		mlx_loop(data.mlx);
	}
}


