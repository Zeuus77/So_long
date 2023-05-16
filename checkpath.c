/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 05:25:52 by youel-id          #+#    #+#             */
/*   Updated: 2023/01/16 05:25:53 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
int check_cube(t_data *data)
{
	int i;
	i = 0;
	int j;
	j = 0;
	data->Length = 9;
	data->width = 34;

	while(data->arr[i][j])
	{
		if(data->arr[i][j] != '1'|| data->arr[data->Length - 1][j] != '1')
		{
			printf("ERROR: Missing WALLS");
			return(0);
		}
		j++;
	}
	while(i < data->Length - 1 )
	{
		if(data->arr[i][0] != '1' || data->arr[i][data->width - 1] != '1')
		{
			printf("ERRPR: Missing WALLsS");
			return(0);
		}
		i++;
	}
	return(1);

}

//int valid_path(t_data *data)
//{
//	if (data->total_number_of_coins == 0)
//		return (0);
//	if(data->arr[data->yp][data->xp] != '1')
//		data->total_number_of_coins--;
//	data->arr[data->yp][data->xp] = 'P';
//	if(data->arr[data->yp -1][data->xp] != 'P' || data->arr[data->yp - 1][data->xp] != '1')
//		{
//			data->arr[data->yp] -=1;
//			valid_path(data);
//		}
//	if(data->arr[data->yp + 1][data->xp] != 'P' || data->arr[data->yp + 1][data->xp] != '1')
//		{
//			data->arr[data->yp] += 1;
//			valid_path(data);
//		}
//	if(data->arr[data->yp][data->xp - 1] != 'P' || data->arr[data->yp][data->xp - 1] != '1')
//		{
//			data->arr[data->xp] -= 1;
//			valid_path(data);
//		}
//	if(data->arr[data->yp][data->xp + 1] != 'P' || data->arr[data->yp][data->xp + 1] != '1')
//		{
//			data->arr[data->xp] += 1;
//			valid_path(data);
//		}
//	return(1);
//	printf("%d\n",data->total_number_of_coins);

//}
int valid_path(t_data *data,int i, int j)
{
	if (data->total_number_of_coins == 0)
		return (0);
	if(data->arr[i][j] != '1')
		data->total_number_of_coins--;
	data->arr[i][j] = 'P';
	if(data->arr[i -1][j] != 'P' || data->arr[i - 1][j] != '1')
			valid_path(data,i-1,j);
	if(data->arr[i + 1][j] != 'P' || data->arr[i + 1][j] != '1')
			valid_path(data,i+1,j);
	if(data->arr[i][j - 1] != 'P' || data->arr[i][j - 1] != '1')
			valid_path(data,i,j-1);
	if(data->arr[i][j + 1] != 'P' || data->arr[i][j + 1] != '1')
		valid_path(data,i,j+1);
	return(1);
	

	printf("%d\n",data->total_number_of_coins);

}