/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:49:10 by kreys             #+#    #+#             */
/*   Updated: 2023/11/23 14:56:37 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/window.h"

void	set_up_window(t_env *env)
{
	make_colors(env);
	init_matrix(env);
	button_setub(env);
	draw_all(env);
	mlx_loop(env->window);
}

void	init_window(t_env *env)
{
	env->window = mlx_init();
	env->screen = mlx_new_window(env->window, \
		WIDTH, LENGTH, NAME_WINDOW);
	if (!env->window || !env->screen)
		clean_window(&env, NEMEM);
	env->map->l_coef = (LENGTH - (LENGTH / 4)) / env->length;
	env->map->w_coef = (WIDTH - (WIDTH / 4)) / env->width;
	max_digit(env);
	min_digit(env);
	set_up_window(env);
}
