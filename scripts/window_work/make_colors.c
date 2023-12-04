/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:54:07 by kreys             #+#    #+#             */
/*   Updated: 2023/11/24 18:38:12 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/window.h"

int	map(float value, float max, float min)
{
	float	coef;
	float	to_ret;

	coef = value / (max - min);
	to_ret = 8 * coef;
	return (to_ret);
}

int	ch_col(int value, int max, int min)
{
	int	index_color;

	index_color = map(value, max, min);
	if (index_color == 8)
		return (WHITE);
	else if (index_color == 7)
		return (RED);
	else if (index_color == 6)
		return (BLACKYELLOW);
	else if (index_color == 5)
		return (YELLOW);
	else if (index_color == 4)
		return (BLACKGREEN);
	else if (index_color == 3 || value >= 0)
		return (GREEN);
	else if (index_color == 2)
		return (GREENWHITE);
	else if (index_color == 1)
		return (BLACKBLUE);
	else
		return (BLUE);
}

void	make_colors(t_env *env)
{
	int		x;
	int		y;
	int		**colrs;

	y = 0;
	env->map->point_count = env->length * env->width;
	colrs = malloc(env->length * sizeof(int *));
	if (!colrs)
		clean_window(&env, NEMEM);
	while (y < env->length)
		colrs[y++] = malloc(env->width * sizeof(int));
	y = 0;
	while (env->length > y)
	{
		x = 0;
		while (env->width > x)
		{
			colrs[y][x] = \
				ch_col(env->coords[y][x], env->map->max_h, env->map->min_h);
			x++;
		}
		y++;
	}
	env->map->colrs = colrs;
}
