/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:11:26 by kreys             #+#    #+#             */
/*   Updated: 2023/11/24 19:53:39 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H

# define WINDOW_H

# include "all.h"
# include "mlx.h"
# include <math.h>

# define NAME_WINDOW "FDF_KREYS"
# define LENGTH 1240
# define WIDTH	1940

# define ESC 53
# define T_BUTTON 17
# define E_BUTTON 14
# define W_BUTTON 13
# define Q_BUTTON 12
# define Z_BUTTON 6
# define X_BUTTON 7
# define G_BUTTON 5
# define F_BUTTON 3
# define D_BUTTON 2
# define S_BUTTON 1
# define A_BUTTON 0

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_MIDDLE 3
# define WHEEL_UP 4
# define WHEEL_DOWN 5

# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define BLACKYELLOW 0xC2B306
# define YELLOW 0xF8E71C
# define BLACKGREEN 0x04D00
# define GREEN 0x007300
# define GREENWHITE 0x00BC00
# define BLUE 0x5097A4
# define BLACKBLUE 0x0000FF

# define MOVE "Use W A S D and mouse to move object"
# define ROTATE "Use Q E Z X T G and mouse to rotate object"
# define ZOOM "Use mouse wheel to zoom"
# define MODS "Press F to change Projection"
# define EXIT "Press ESC to exit"
# define IAOP "Current projection {Izometric}"
# define CYLYD "Current projection {Cylindrical}"
# define PARALEL "Current projection {Paralel}"
# define FREEOJ "Current projection {Free}"

# define HG_MOD 25

//			Modole
int			modify_points(int key, t_env *env);
void		button_setub(t_env *env);
void		draw_all(t_env *env);
void		draw_lines(t_env *env, float *matrix, int x, int y);
void		create_image(t_env *env);
void		put_pix_img(t_env *env, int x, int y, int color);

//			Buttons
int			close_program(void *param);
int			move_x(int key, t_env *env);
int			move_y(int key, t_env *env);
int			rotate_x(int key, t_env *env);
int			rotate_y(int key, t_env *env);
int			rotate_z(int key, t_env *env);
int			zoom(int key, t_env *env);

//			Mouse
int			mouse_move(int x, int y, t_env *env);
int			mouse_down(int key, int x, int y, t_env *env);
int			mouse_up(int key, int x, int y, t_env *env);

//			Matrix
void		fill_all_matrix(t_env *env);
void		mult_matr(t_cor *cor, float *mat);
void		change_proj(t_env *env);
void		init_matrix(t_env *env);

//			Init_&&_delete_obj
void		make_colors(t_env *env);
void		calculate_matrix(t_env *env);

//			Helpers
void		max_digit(t_env *env);
void		min_digit(t_env *env);
void		*ft_bzero(void *b, size_t len);
float		norm(float angle);
float		abc(float a);

#endif
