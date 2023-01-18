/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youel-id <youel-id@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:16:43 by youel-id          #+#    #+#             */
/*   Updated: 2022/12/30 13:16:44 by youel-id         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"so_long.h"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = (char *)ft_calloc(1, sizeof(char));
		return (str);
	}
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && i < len + start)
	{
		str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}
void	*ft_calloc(size_t count, size_t size)
{
	char	*res;

	res = malloc(count * size);
	if (!res)
	{
		return (NULL);
	}
	ft_bzero(res, count * size);
	return (res);
}
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*b;

	b = (char *)s;
	i = 0;
	while (i < n)
	{
		b[i] = '\0';
		i++;
	}
}