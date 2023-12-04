/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:10:33 by kreys             #+#    #+#             */
/*   Updated: 2023/11/23 15:21:17 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"
#include "../headers/all.h"

void	init_control(t_control *cont)
{
	cont->zoom = 1;
	cont->move_x = 0;
	cont->move_y = 0;
	cont->move_z = 0;
	cont->rotate_x = 0;
	cont->rotate_y = 0;
	cont->rotate_z = 0;
}

void	init__env(t_env *env)
{
	if (!env)
		return ;
	env->map = malloc(sizeof(t_map));
	if (!env->map || !env->control)
		clean_window(&env, NEMEM);
	env->control = malloc(sizeof(t_control));
	if (!env->control)
		clean_window(&env, NEMEM);
	init_control(env->control);
	env->img = malloc(sizeof(t_img));
	if (!env->img)
		clean_window(&env, NEMEM);
	env->mouse = malloc(sizeof(t_mouse));
	if (!env->mouse)
		clean_window(&env, NEMEM);
	env->img->img = NULL;
	env->img->buff_img = NULL;
	env->img->bits_pix = 32;
	env->img->line_size = 120;
	env->img->endian = 1;
}

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc <= 1 || argc > 2)
		return (0);
	env = manahe_window(argv[1]);
	init__env(env);
	if (!env)
		return (0);
	init_window(env);
}
