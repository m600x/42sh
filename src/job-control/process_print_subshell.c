/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_print_subshell.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:06:06 by wescande          #+#    #+#             */
/*   Updated: 2017/03/08 19:14:54 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		process_print_subshell(t_process *p)
{
	(void)p;
	ft_putstr("SUBSHELL GROUP");
	return (0);
}