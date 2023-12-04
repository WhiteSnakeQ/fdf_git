# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 15:29:11 by kreys             #+#    #+#              #
#    Updated: 2023/11/24 19:13:07 by kreys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= fdf.c helpers.c
PARSSRC		= read_file.c helpers.c window_prepair.c init_obj.c parse_all.c delete_obj.c
GNLSRC		= get_next_line.c get_next_line_utils.c
MINLSRC		= -framework OpenGL -framework AppKit ./scripts/minilibx/libmlx.a
WINDSRS		= init_window.c key_act.c make_colors.c draw.c draw_modif.c key_act2.c \
			  calculate_mat.c matrix_create.c helpers.c init_projection.c \
			  mouse.c

PSRC		= ./scripts/fdf/
PPARS		= ./scripts/parse_all/
PGNL		= ./scripts/get_next_line/
PWIND		= ./scripts/window_work/

OBJ			= ${addprefix ${PSRC}, ${SRC:.c=.o}} \
				${addprefix ${PPARS}, ${PARSSRC:.c=.o}} \
				${addprefix ${PWIND}, ${WINDSRS:.c=.o}} \
				${addprefix ${PGNL}, ${GNLSRC:.c=.o}}
NAME_F		= fdf

CC		= cc 
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address,undefined -g3

${NAME_F}:	${MAKEMLX} ${OBJ} 
			@$(MAKE) -C scripts/minilibx/
			@${CC} ${CFLAGS} ${OBJ} ${MINLSRC} -o ${NAME_F}

clean:		
			@rm -f ${OBJ}

fclean:		clean
			@rm -f ${NAME_F}

re:			fclean ${NAME_F}