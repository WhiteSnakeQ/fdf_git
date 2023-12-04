/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_prepair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:51:32 by kreys             #+#    #+#             */
/*   Updated: 2023/11/23 14:52:58 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parse.h"

void	add_back_digit(t_digit **list, int digit)
{
	if ((*list)->next)
		add_back_digit(&(*list)->next, digit);
	else
	{
		(*list)->digit = digit;
		init_list_digit(&(*list)->next);
	}
}

void	get_one_digit(char *str, int *i, t_digit **list_digit, int *minus)
{
	long	num_to_ret;

	num_to_ret = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num_to_ret *= 10;
		num_to_ret += str[*i] - '0';
		*i += 1;
	}
	if (*minus == 1)
		num_to_ret *= -1;
	if (num_to_ret >= 2147483647 || num_to_ret <= -2147483648)
	{
		free_digit_list(list_digit);
		while (str[*i])
			*i += 1;
		return ;
	}
	*i -= 1;
	*minus = 0;
	add_back_digit(list_digit, (int)num_to_ret);
}

int	*creat_arr(t_digit **list)
{
	t_digit	*list_check;
	int		*arr;
	int		size;
	int		i;

	list_check = *list;
	size = 0;
	while (list_check->next)
	{
		size++;
		list_check = list_check->next;
	}
	arr = malloc(sizeof(int) * size);
	list_check = *list;
	i = 0;
	while (size > i)
	{
		arr[i++] = list_check->digit;
		list_check = list_check->next;
	}
	free_digit_list(list);
	return (arr);
}

int	*create_int_size(char *str, t_env *window, int minus, int i)
{
	t_digit		*list_digit;
	int			num_digit;

	num_digit = 0;
	init_list_digit(&list_digit);
	while (str[++i])
	{
		if (str[i] == '-' && minus == 0 && str[i + 1])
			minus = 1;
		else if (str[i] == '+' && minus == 0 && str[i + 1])
			minus = 2;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			get_one_digit(str, &i, &list_digit, &minus);
			num_digit++;
		}
		else if (str[i] == ' ' || str[i] == '\n')
			continue ;
		else
			window->error = 1;
	}
	if (!list_digit || (num_digit != window->width && window->width != 0))
		window->error = 1;
	window->width = num_digit;
	return (creat_arr(&list_digit));
}

t_env	*make_int_arr(char **strs)
{
	t_env	*window;
	int		i;

	if (!strs || !*strs)
		return (NULL);
	window = malloc(sizeof(t_env));
	if (!window)
	{
		print_error(NEMEM);
		return (NULL);
	}
	window->length = arr_size(strs);
	create_window(&window);
	if (!window->coords)
		free(window);
	i = -1;
	while (window && window->length > ++i)
	{
		window->coords[i] = create_int_size(strs[i], window, 0, -1);
		window->real_length++;
		if (window->error == 1)
			clean_window(&window, FORMF);
	}
	return (window);
}
