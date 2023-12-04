/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:42:21 by kreys             #+#    #+#             */
/*   Updated: 2023/11/24 19:41:21 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/window.h"

void	printf_line(t_cor *start, t_cor *end, t_env *env)
{
	int			length;
	int			i;
	float		move_x;
	float		move_y;

	i = 0;
	length = sqrt(pow(end->x - start->x, 2) + pow(end->y - start->y, 2));
	move_x = (end->x - start->x) / abc(length);
	move_y = (end->y - start->y) / abc(length);
	while (length / 2 > i)
	{
		put_pix_img(env, start->x + \
			(move_x * i) + env->control->move_x, start->y + (move_y * i) \
				+ env->control->move_y, start->color);
		i++;
	}
	while (length > i)
	{
		put_pix_img(env, start->x + \
			(move_x * i) + env->control->move_x, start->y + (move_y * i) \
				+ env->control->move_y, end->color);
		i++;
	}
	free(end);
}

t_cor	*create_coord(t_env *env, float *matrix, int x, int y)
{
	t_cor	*cor;

	cor = malloc(sizeof(t_cor));
	cor->color = env->map->colrs[y][x];
	cor->x = (x * env->map->w_coef);
	cor->y = (y * env->map->l_coef);
	cor->z = env->coords[y][x] * HG_MOD;
	mult_matr(cor, matrix);
	return (cor);
}

void	draw_lines(t_env *env, float *matrix, int x, int y)
{
	t_cor	*start;

	start = create_coord(env, matrix, x, y);
	if (y + 1 < env->length)
		printf_line(start, create_coord(env, matrix, x, y + 1), env);
	if (y - 1 >= 0)
		printf_line(start, create_coord(env, matrix, x, y - 1), env);
	if (x - 1 >= 0)
		printf_line(start, create_coord(env, matrix, x - 1, y), env);
	if (x + 1 < env->width)
		printf_line(start, create_coord(env, matrix, x + 1, y), env);
	free(start);
}

void	put_strs(t_env *env)
{
	int	i;

	i = 0;
	mlx_string_put(env->window, env->screen, 20, 20 * i++, 0xFFFFFF, EXIT);
	mlx_string_put(env->window, env->screen, 20, 20 * i++, 0xFFFFFF, MOVE);
	mlx_string_put(env->window, env->screen, 20, 20 * i++, 0xFFFFFF, ROTATE);
	mlx_string_put(env->window, env->screen, 20, 20 * i++, 0xFFFFFF, ZOOM);
	mlx_string_put(env->window, env->screen, 20, 20 * i++, 0xFFFFFF, MODS);
	mlx_string_put(env->window, env->screen, 20, 20 * i++, 0xFFFFFF, \
		env->img->message);
}

void	draw_all(t_env *env)
{
	fill_all_matrix(env);
	mlx_clear_window(env->window, env->screen);
	create_image(env);
	calculate_matrix(env);
	mlx_put_image_to_window(env->window, env->screen, env->img->img, 0, 0);
	put_strs(env);
}
