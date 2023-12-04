/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:51:32 by kreys             #+#    #+#             */
/*   Updated: 2023/11/23 15:19:18 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parse.h"

void	create_window(t_env **window)
{
	(*window)->coords = malloc(sizeof(int *) * ((*window)->length));
	(*window)->error = 0;
	(*window)->width = 0;
	(*window)->real_length = 0;
	(*window)->window = NULL;
	(*window)->screen = NULL;
	(*window)->map = NULL;
	(*window)->img = NULL;
	(*window)->mouse = NULL;
	(*window)->matrix = malloc(sizeof(t_matrix));
}

void	init_list_digit(t_digit **list)
{
	*list = malloc(sizeof(t_digit));
	if (!*list)
		return ;
	(*list)->digit = 0;
	(*list)->next = NULL;
}
