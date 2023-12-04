/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_act2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:05:14 by kreys             #+#    #+#             */
/*   Updated: 2023/11/24 19:54:27 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/window.h"

int	move_x(int key, t_env *env)
{
	if (key == D_BUTTON)
		env->control->move_x += WIDTH / 40;
	if (key == A_BUTTON)
		env->control->move_x -= WIDTH / 20;
	return (0);
}

int	move_y(int key, t_env *env)
{
	if (key == W_BUTTON)
		env->control->move_y -= LENGTH / 20;
	if (key == S_BUTTON)
		env->control->move_y += LENGTH / 20;
	return (0);
}

int	rotate_x(int key, t_env *env)
{
	if (key == E_BUTTON)
		env->control->rotate_x += 0.01744444;
	else if (key == Q_BUTTON)
		env->control->rotate_x -= 0.01744444;
	env->control->rotate_x = norm(env->control->rotate_x);
	return (0);
}

int	zoom(int key, t_env *env)
{
	if (key == 126 || key == WHEEL_DOWN)
		env->control->zoom += 0.1;
	else if ((key == 125 || key == WHEEL_UP) && env->control->zoom > 0.4)
		env->control->zoom -= 0.1;
	return (1);
}
