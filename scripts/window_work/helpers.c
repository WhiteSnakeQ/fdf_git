/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:17:07 by kreys             #+#    #+#             */
/*   Updated: 2023/11/24 19:23:20 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/window.h"

void	max_digit(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	env->map->max_h = env->coords[0][0];
	while (env->length > y)
	{
		x = 0;
		while (env->width > x)
		{
			if (env->coords[y][x] > env->map->max_h)
				env->map->max_h = env->coords[y][x];
			x++;
		}
		y++;
	}
}

void	min_digit(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	env->map->min_h = env->coords[0][0];
	while (env->length > y)
	{
		x = 0;
		while (env->width > x)
		{
			if (env->coords[y][x] < env->map->min_h)
				env->map->min_h = env->coords[y][x];
			x++;
		}
		y++;
	}
}

void	*ft_bzero(void *b, size_t len)
{
	unsigned char	*str;
	int				size;

	size = 0;
	str = (unsigned char *)b;
	while (len-- > 0)
		str[size++] = '\0';
	return (b);
}

float	abc(float a)
{
	if (a <= 0)
		return (-a);
	return (a);
}
