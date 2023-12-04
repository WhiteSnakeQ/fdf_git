/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_mat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:43:20 by kreys             #+#    #+#             */
/*   Updated: 2023/11/24 19:31:07 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/window.h"

void	mult_matr(t_cor *cor, float *mat)
{
	int	x;
	int	y;
	int	z;

	x = cor->x;
	y = cor->y;
	z = cor->z;
	cor->x = (x * mat[0] + y * mat[3] + z * mat[6]);
	cor->y = (x * mat[1] + y * mat[4] + z * mat[7]);
	cor->z = (x * mat[2] + y * mat[5] + z * mat[8]);
}

float	*copy_matr(float *arr)
{
	float	*to_ret;

	to_ret = malloc(sizeof(float) * 9);
	to_ret[0] = arr[0];
	to_ret[1] = arr[1];
	to_ret[2] = arr[2];
	to_ret[3] = arr[3];
	to_ret[4] = arr[4];
	to_ret[5] = arr[5];
	to_ret[6] = arr[6];
	to_ret[7] = arr[7];
	to_ret[8] = arr[8];
	return (to_ret);
}

float	*multiplay_matrix(float *mat1, float *mat2)
{
	float	*to_ret;

	to_ret = malloc(sizeof(float) * 9);
	to_ret[0] = mat1[0] * mat2[0] + mat1[1] * mat2[3] + mat1[2] * mat2[6];
	to_ret[1] = mat1[3] * mat2[0] + mat1[4] * mat2[3] + mat1[5] * mat2[6];
	to_ret[2] = mat1[6] * mat2[0] + mat1[7] * mat2[3] + mat1[8] * mat2[6];
	to_ret[3] = mat1[0] * mat2[1] + mat1[1] * mat2[4] + mat1[2] * mat2[7];
	to_ret[4] = mat1[3] * mat2[1] + mat1[4] * mat2[4] + mat1[5] * mat2[7];
	to_ret[5] = mat1[6] * mat2[1] + mat1[7] * mat2[4] + mat1[8] * mat2[7];
	to_ret[6] = mat1[0] * mat2[2] + mat1[1] * mat2[5] + mat1[2] * mat2[8];
	to_ret[7] = mat1[3] * mat2[2] + mat1[4] * mat2[5] + mat1[5] * mat2[8];
	to_ret[8] = mat1[6] * mat2[2] + mat1[7] * mat2[5] + mat1[8] * mat2[8];
	return (to_ret);
}

void	calculate_matrix(t_env *env)
{
	int			y;
	int			x;
	float		*matrix;

	y = -1;
	matrix = multiplay_matrix(env->matrix->mat_big, env->matrix->mat_rotate);
	while (env->length > ++y)
	{
		x = -1;
		while (env->width > ++x)
			if ((y + x) % 2 == 0)
				draw_lines(env, matrix, x, y);
	}
	free(matrix);
}
