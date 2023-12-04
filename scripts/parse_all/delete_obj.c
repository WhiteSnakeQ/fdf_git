/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:52:37 by kreys             #+#    #+#             */
/*   Updated: 2023/11/20 20:10:07 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parse.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	if (!strs || !*strs)
		return ;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	strs = NULL;
}

void	free_digit_list(t_digit **list)
{
	if (!list || !*list)
		return ;
	if ((*list)->next)
		free_digit_list(&(*list)->next);
	free((*list));
	(*list) = NULL;
}
