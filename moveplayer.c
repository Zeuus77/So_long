/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:14:06 by youel-id          #+#    #+#             */
/*   Updated: 2023/01/03 16:14:07 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
void exit_game(t_data *data)
{
	int i = 0;
	mlx_destroy_image(data->mlx,data->player1);
	mlx_destroy_image(data->mlx,data->wall);
	mlx_destroy_image(data->mlx,data->grass);
	mlx_destroy_image(data->mlx,data->tower);
	mlx_destroy_image(data->mlx,data->coin);
	mlx_destroy_window(data->mlx,data->win);
	while(data->arr[i])
	{
		free(data->arr[i]);
		i++;
	}
	free(data->arr);
	exit(0);
}
void move(t_data *data, int *no_coin)
{
	if(data->arr[data->yp][data->xp] == 'E' && *no_coin == data->total_number_of_coins )
    {
		printf("GAME OVER");
        exit_game(data);
    }
    if(data->arr[data->yp][data->xp] == 'E' )
        return;
    if(data->arr[data->yp][data->xp] != '1' && data->arr[data->yp][data->xp] != 'E')
       data->arr[data->yp][data->xp] = '0';
	
	mlx_put_image_to_window(data->mlx,data->win,data->player1,data->xp*50,data->yp*50);
}
int key_move(int key,t_data *data)
{
	int no_coin = 0;
	if (key == 13 && data->arr[data->yp - 1][data->xp] != '1')
	{
	//data->arr[data->yp ][data->xp] = '0';
	//data->arr[data->yp - 1 ][data->xp] = 'P';
    data->yp -= 1;
	check_map(data);
    move(data,&no_coin);
    }
	if(key == 1 && data->arr[data->yp + 1][data->xp] != '1'  )
		{
		//data->arr[data->yp][data->xp] = '0';
		//data->arr[data->yp + 1 ][data->xp] = 'P';
		data->yp += 1; 
		check_map(data);
		move(data,&no_coin);
		}
	if(key == 0 && data->arr[data->yp][data->xp - 1] != '1')
	
		{
		//data->arr[data->yp ][data->xp] = '0';
		//data->arr[data->yp ][data->xp - 1] = 'P';
		data->xp -=1;
		check_map(data);
		move(data,&no_coin);
		}
	if(key == 2 && data->arr[data->yp][data->xp + 1] != '1'  )
		{
		//data->arr[data->yp][data->xp] = '0';
		//data->arr[data->yp ][data->xp + 1] = 'P';
		data->xp +=1;
		check_map(data);
		move(data,&no_coin);
		}
	if(key == 53)
		exit_game(data);
	//printf("%d\n",coins_counting);
	return(0);

}
