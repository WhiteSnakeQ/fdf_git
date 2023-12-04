/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:08:29 by kreys             #+#    #+#             */
/*   Updated: 2023/11/24 20:18:37 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/all.h"
#include "../headers/mlx.h"

void	print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

void	free_map(t_map **map, int size)
{
	int	i;

	if (!map || !*map)
		return ;
	i = 0;
	if ((*map)->colrs)
	{
		while (size > i)
			free((*map)->colrs[i++]);
		free((*map)->colrs);
	}
	free(*map);
}

void	free_mlx(t_env **env)
{
	if ((*env)->window && (*env)->screen && (*env)->img->img)
	{
		mlx_destroy_image((*env)->window, (*env)->img->img);
		(*env)->window = NULL;
		(*env)->img->img = NULL;
	}
	free((*env)->img);
	if ((*env)->window && (*env)->screen)
	{
		mlx_destroy_window((*env)->window, (*env)->screen);
		(*env)->window = NULL;
		(*env)->screen = NULL;
	}
	if ((*env)->mouse)
		free((*env)->mouse);
	if ((*env)->window)
		free((*env)->window);
	if ((*env)->screen)
		free((*env)->screen);
}

void	free_matrix(t_matrix **mat)
{
	if ((*mat)->mat_big)
		free((*mat)->mat_big);
	if ((*mat)->mat_rotate)
		free((*mat)->mat_rotate);
	if (mat && *mat)
		free(*mat);
}

void	clean_window(t_env **env, char *error)
{
	int	size;

	size = 0;
	if (error)
		print_error(error);
	if (!env || !*env)
		return ;
	while ((*env)->real_length > size)
		free((*env)->coords[size++]);
	size = 0;
	if ((*env)->control)
		free((*env)->control);
	free_map(&(*env)->map, (*env)->real_length);
	free_mlx(env);
	if ((*env)->matrix)
		free_matrix(&(*env)->matrix);
	free((*env)->coords);
	free(*env);
	exit(0);
}
