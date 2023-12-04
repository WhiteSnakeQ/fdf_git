/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_modif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:49:10 by kreys             #+#    #+#             */
/*   Updated: 2023/11/24 18:45:33 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/window.h"

void	put_pix_img(t_env *env, int x, int y, int color)
{
	if (x >= WIDTH || x <= 0)
		return ;
	if (y >= LENGTH || y <= 0)
		return ;
	if (env->img->buff_img[(x + (y * WIDTH)) * 4])
		return ;
	env->img->buff_img[(x + (y * WIDTH)) * 4] = (color) & 0xFF;
	env->img->buff_img[((x + (y * WIDTH)) * 4) + 1] = (color >> 8) & 0xFF;
	env->img->buff_img[((x + (y * WIDTH)) * 4) + 2] = (color >> 16) & 0xFF;
	env->img->buff_img[((x + (y * WIDTH)) * 4) + 3] = (color >> 24);
}

void	create_image(t_env *env)
{
	if (!env->img->img)
		env->img->img = mlx_new_image(env->window, WIDTH, LENGTH);
	if (!env->img->buff_img)
		env->img->buff_img = mlx_get_data_addr(env->img->img, \
			&env->img->bits_pix, &env->img->line_size, &env->img->endian);
	else
		ft_bzero(env->img->buff_img, WIDTH * LENGTH * 4);
}

int	modify_points(int key, t_env *env)
{
	if (key == W_BUTTON || key == S_BUTTON)
		move_y(key, env);
	else if (key == A_BUTTON || key == D_BUTTON)
		move_x(key, env);
	else if (key == Q_BUTTON || key == E_BUTTON)
		rotate_x(key, env);
	else if (key == Z_BUTTON || key == X_BUTTON)
		rotate_y(key, env);
	else if (key == T_BUTTON || key == G_BUTTON)
		rotate_z(key, env);
	else if (key == F_BUTTON)
		change_proj(env);
	else if (key == ESC)
		close_program(env);
	draw_all(env);
	return (0);
}
