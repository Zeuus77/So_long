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