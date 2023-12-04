/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 06:49:19 by kreys             #+#    #+#             */
/*   Updated: 2023/11/24 18:35:26 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/window.h"

void	izo_proj(t_env *env)
{
	env->control->rotate_x_s = (35.264) * 0.017444;
	env->control->rotate_y_s = 0;
	env->control->rotate_z_s = (45) * 0.017444;
	env->control->move_x = WIDTH / 2 - (env->map->w_coef * env->width) / 4;
	env->control->move_y = LENGTH / 2 - (env->map->w_coef * env->width) / 4;
	env->control->move_z = 0;
	env->control->zoom = 0.6;
	env->img->message = IAOP;
}

void	cylindre(t_env *env)
{
	env->control->rotate_x_s = 0;
	env->control->rotate_y_s = 0;
	env->control->rotate_z_s = 0;
	env->control->move_x = WIDTH / 2 - (env->map->w_coef * env->width) / 2;
	env->control->move_y = LENGTH / 2 - (env->map->l_coef * env->length) / 2;
	env->control->move_z = 0;
	env->control->zoom = 0.9;
	env->img->message = CYLYD;
}

void	paralel_proj(t_env *env)
{
	env->control->rotate_x_s = -0.334111;
	env->control->rotate_y_s = -0.68333;
	env->control->rotate_z_s = 0.30889;
	env->control->move_x = WIDTH / 2 - (env->map->w_coef * env->width) / 4;
	env->control->move_y = LENGTH / 2 - (env->map->l_coef * env->length) / 4;
	env->control->move_z = 0;
	env->control->zoom = 0.5;
	env->img->message = PARALEL;
}

void	free_proj(t_env *env)
{
	env->control->rotate_x_s = 45 * 0.017444;
	env->control->rotate_y_s = 45 * 0.017444;
	env->control->rotate_z_s = 45 * 0.017444;
	env->control->move_x = WIDTH / 2 - (env->map->w_coef * env->width) / 4;
	env->control->move_y = LENGTH / 2 - (env->map->l_coef * env->length) / 4;
	env->control->move_z = 0;
	env->control->zoom = 0.5;
	env->img->message = FREEOJ;
}

void	change_proj(t_env *env)
{
	static int	i = 0;

	env->img->message = "";
	if (i == 0 && ++i == 1)
		izo_proj(env);
	else if (i == 1 && ++i == 2)
		cylindre(env);
	else if (i == 2 && ++i == 3)
		paralel_proj(env);
	else if (i == 3 && ++i == 4)
	{
		free_proj(env);
		i = 0;
	}
	env->control->rotate_x = 0;
	env->control->rotate_y = 0;
	env->control->rotate_z = 0;
	fill_all_matrix(env);
}
