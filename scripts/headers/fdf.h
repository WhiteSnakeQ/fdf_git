/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:11:26 by kreys             #+#    #+#             */
/*   Updated: 2023/11/24 18:36:44 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

typedef struct s_cor
{
	float	x;
	float	y;
	float	z;
	int		color;
}		t_cor;

typedef struct s_matrix
{
	float	*mat_big;
	float	*mat_rotate;
}		t_matrix;

typedef struct s_map
{
	int			l_coef;
	int			w_coef;
	int			max_h;
	int			min_h;
	int			**colrs;
	int			point_count;
}		t_map;

typedef struct s_control
{
	float	move_x;
	float	move_y;
	float	move_z;
	float	rotate_x;
	float	rotate_y;
	float	rotate_z;
	float	rotate_x_s;
	float	rotate_y_s;
	float	rotate_z_s;
	float	zoom;
}		t_control;

typedef struct s_mouse
{
	int		mouse_x;
	int		mouse_y;
	int		mouse;
}		t_mouse;

typedef struct s_img
{
	int			bits_pix;
	int			line_size;
	int			endian;
	char		*message;
	void		*img;
	char		*buff_img;
}		t_img;

typedef struct s_env
{
	int			width;
	int			length;
	int			real_length;
	int			error;
	int			**coords;
	void		*window;
	void		*screen;
	t_map		*map;
	t_control	*control;
	t_matrix	*matrix;
	t_mouse		*mouse;
	t_img		*img;
}		t_env;

//			Modole
t_env		*manahe_window(char *str);
void		init_window(t_env *window);

#endif
