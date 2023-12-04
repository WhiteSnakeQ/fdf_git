/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:11:26 by kreys             #+#    #+#             */
/*   Updated: 2023/11/23 14:51:52 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H

# define ALL_H

# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "fdf.h"

# define NEMEM "FDF:  NotEnfMemory\n"
# define FILEERR "FDF:  Incorect File or Permition\n"
# define FORMF "FDF:  Incorect Format of Input\n"

void	clean_window(t_env **window, char *error);
void	print_error(char *str);

#endif