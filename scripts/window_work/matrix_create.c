/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:35:19 by kreys             #+#    #+#             */
/*   Updated: 2023/11/24 20:05:05 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/window.h"

void	fill_mat_big(t_env *env)
{
	if (!env->matrix->mat_big)
		env->matrix->mat_big = malloc(sizeof(float) * 9);
	env->matrix->mat_big[0] = env->control->zoom;
	env->matrix->mat_big[1] = 0;
	env->matrix->mat_big[2] = 0;
	env->matrix->mat_big[3] = 0;
	env->matrix->mat_big[4] = env->control->zoom;
	env->matrix->mat_big[5] = 0;
	env->matrix->mat_big[6] = 0;
	env->matrix->mat_big[7] = 0;
	env->matrix->mat_big[8] = env->control->zoom;
}

float	norm(float angle)
{
	if (angle > 3.14)
		return (-3.14);
	else if (angle < -6.28)
		return (3.14);
	return (angle);
}

void	fill_mat_rotate(t_env *env)
{
	float	x;
	float	y;
	float	z;

	x = env->control->rotate_x + env->control->rotate_x_s;
	y = env->control->rotate_y + env->control->rotate_y_s;
	z = env->control->rotate_z + env->control->rotate_z_s;
	if (!env->matrix->mat_rotate)
		env->matrix->mat_rotate = malloc(sizeof(float) * 9);
	env->matrix->mat_rotate[0] = cos(y) * cos(z);
	env->matrix->mat_rotate[1] = (cos(z) * sin(y) * sin(x)) - (sin(z) * cos(x));
	env->matrix->mat_rotate[2] = (cos(z) * sin(y) * sin(x)) + (sin(y) * cos(x));
	env->matrix->mat_rotate[3] = sin(z) * cos(y);
	env->matrix->mat_rotate[4] = (sin(z) * sin(y) * sin(x)) + (cos(z) * cos(x));
	env->matrix->mat_rotate[5] = (sin(z) * sin(y) * cos(x)) - (cos(z) * sin(x));
	env->matrix->mat_rotate[6] = -(sin(y));
	env->matrix->mat_rotate[7] = cos(y) * sin(x);
	env->matrix->mat_rotate[8] = cos(y) * cos(x);
}

void	fill_all_matrix(t_env *env)
{
	fill_mat_rotate(env);
	fill_mat_big(env);
}

void	init_matrix(t_env *env)
{
	env->matrix = malloc(sizeof(t_matrix));
	if (!env->matrix)
		clean_window(&env, NEMEM);
	env->matrix->mat_big = NULL;
	env->matrix->mat_rotate = NULL;
	change_proj(env);
}
