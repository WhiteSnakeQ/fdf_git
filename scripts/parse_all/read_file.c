/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:10:33 by kreys             #+#    #+#             */
/*   Updated: 2023/11/23 14:49:18 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parse.h"
#include "../get_next_line/get_next_line.h"

void	clean_list(t_text **text)
{
	if (!text || !*text)
		return ;
	if (*text)
		clean_list(&(*text)->next);
	free(*text);
}

char	**make_strs(t_text **text, int size)
{
	t_text	*to_clean;
	char	**strs;
	int		i;

	i = 0;
	to_clean = *text;
	strs = malloc(sizeof(char *) * (size + 1));
	if (!strs)
	{
		clean_list(&to_clean);
		return (NULL);
	}
	strs[size] = NULL;
	while (size > i)
	{
		strs[i++] = (*text)->str;
		(*text) = (*text)->next;
	}
	clean_list(&to_clean);
	return (strs);
}

t_text	*init_text(char *str)
{
	t_text	*list;

	list = malloc(sizeof(t_text));
	list->str = str;
	list->next = NULL;
	return (list);
}

char	**read_file_map(char *file)
{
	t_text	*text;
	t_text	*start_text;
	int		fd;
	int		size;

	size = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error(FILEERR);
		return (NULL);
	}
	start_text = init_text(get_next_line(fd));
	text = start_text;
	while (text->str)
	{
		text->next = init_text(get_next_line(fd));
		text = text->next;
		size++;
	}
	close(fd);
	return (make_strs(&start_text, size));
}
