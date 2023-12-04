/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:22:55 by kreys             #+#    #+#             */
/*   Updated: 2023/11/20 18:37:29 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parse.h"

t_env	*manahe_window(char *str)
{
	char		**strs;
	t_env		*window;

	strs = read_file_map(str);
	if (!strs || !*strs)
		return (NULL);
	window = make_int_arr(strs);
	free_strs(strs);
	return (window);
}
