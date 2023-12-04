/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:11:26 by kreys             #+#    #+#             */
/*   Updated: 2023/11/23 14:55:38 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

# include "all.h"

typedef struct s_text
{
	char			*str;
	struct s_text	*next;
}		t_text;

typedef struct s_digit
{
	int				digit;
	struct s_digit	*next;
}		t_digit;

//			Modole
char		**read_file_map(char *file);
t_env		*make_int_arr(char **strs);

//			Helpers
int			arr_size(char **strs);

//			Init_&&_delete_obj
void		create_window(t_env **window);
void		free_digit_list(t_digit **list);
void		init_list_digit(t_digit **list);
void		free_strs(char **strs);

#endif
