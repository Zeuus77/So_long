/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_coin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:12:52 by youel-id          #+#    #+#             */
/*   Updated: 2023/01/13 18:12:54 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
int check_coin_exit(t_data *data) 
{
    int x = 0;
	int y = 0;
    int i = -1;
    while (data->arr[++i]) 
	{
        int j = -1;
        while (data->arr[i][++j]) 
		{
            if (data->arr[i][j] == 'E') 
			{
                x = j;
                y = i;
            }
			if (data->arr[i][j] == 'C')
			{
				data->cx= j;
				data->cy = i;
			}
		}
    }
    if (data->arr[y][x] != 'E') 
	{
        printf("Error: No End point\n");
        return 0;
    }
	if (data->arr[data->cy][data->cx] != 'C') 
	{
        printf("Error: No coin\n");
        return 0;
	}
	return (1);
}

int check_walls_player(t_data *data)
{
	int x;
	int y;
	int j;
	int i;
	i = -1;
	while(data->arr[++i])
	{
		j = -1;
		while(data->arr[i][++j])
		{
			if(data->arr[i][j] == '1')
			{
			x = j;
			y = i;
			break;
			}
		}
	}
	if(data->arr[y][x] != '1')
	{
		printf("Error: NO Walls");
		return 0;
	}
	return(1);
} 
int check_player(t_data *data)
{
	int i;
	int j;
	i = -1;
	while(data->arr[++i])
	{
		j = -1;
		while (data->arr[i][j++])
		{
			if(data->arr[i][j] == 'p')
			{
				data->xp = j;
				data->yp = i;
			}
		}
		
	}
	if(data->arr[data->yp][data->xp] != 'P')
	{
		printf("Error: PLAYER");
		return 0;
	}
	return(1);
}