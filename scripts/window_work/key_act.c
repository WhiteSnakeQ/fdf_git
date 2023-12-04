/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_act.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:05:14 by kreys             #+#    #+#             */
/*   Updated: 2023/11/24 19:54:16 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/window.h"

int	close_program(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	clean_window(&env, NULL);
	return (0);
}

int	rotate_y(int key, t_env *env)
{
	if (key == Z_BUTTON)
		env->control->rotate_y += 0.01744444;
	else if (key == X_BUTTON)
		env->control->rotate_y -= 0.01744444;
	env->control->rotate_y = norm(env->control->rotate_y);
	return (1);
}

int	rotate_z(int key, t_env *env)
{
	if (key == T_BUTTON)
		env->control->rotate_z += 0.01744444;
	else if (key == G_BUTTON)
		env->control->rotate_z -= 0.01744444;
	env->control->rotate_z = norm(env->control->rotate_z);
	return (1);
}

void	button_setub(t_env *env)
{
	mlx_hook(env->screen, 2, 0, &modify_points, env);
	mlx_hook(env->screen, 4, 0, &mouse_down, env);
	mlx_hook(env->screen, 5, 0, &mouse_up, env);
	mlx_hook(env->screen, 6, 0, &mouse_move, env);
	mlx_hook(env->screen, 17, 0, &close_program, env);
}
