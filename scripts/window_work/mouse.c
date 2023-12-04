/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:32:31 by kreys             #+#    #+#             */
/*   Updated: 2023/11/24 19:55:04 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/window.h"

int	mouse_move(int x, int y, t_env *env)
{
	if (env->mouse->mouse == MOUSE_LEFT)
	{
		env->control->move_x += (x - env->mouse->mouse_x);
		env->control->move_y += (y - env->mouse->mouse_y);
	}
	else if (env->mouse->mouse == MOUSE_RIGHT)
	{
		env->control->rotate_y += (x - env->mouse->mouse_x) * 0.001;
		env->control->rotate_x -= (y - env->mouse->mouse_y) * 0.001;
		env->control->rotate_y = norm(env->control->rotate_y);
		env->control->rotate_x = norm(env->control->rotate_x);
	}
	else if (env->mouse->mouse == MOUSE_MIDDLE)
	{
		env->control->rotate_z += (x - env->mouse->mouse_x + y \
			- env->mouse->mouse_y) * 0.001;
		env->control->rotate_z = norm(env->control->rotate_z);
	}
	if (env->mouse->mouse >= 1 && env->mouse->mouse <= 3)
		draw_all(env);
	env->mouse->mouse_x = x;
	env->mouse->mouse_y = y;
	return (0);
}

int	mouse_down(int key, int x, int y, t_env *env)
{
	if (key == MOUSE_LEFT || key == MOUSE_MIDDLE || key == MOUSE_RIGHT)
	{
		env->mouse->mouse = key;
		env->mouse->mouse_x = x;
		env->mouse->mouse_y = y;
	}
	else if (key == WHEEL_DOWN || key == WHEEL_UP)
	{
		zoom(key, env);
		draw_all(env);
	}
	return (1);
}

int	mouse_up(int key, int x, int y, t_env *env)
{
	if (key == MOUSE_LEFT || key == MOUSE_MIDDLE || key == MOUSE_RIGHT)
	{
		env->mouse->mouse = 0;
		env->mouse->mouse_x = x;
		env->mouse->mouse_y = y;
	}
	return (0);
}
