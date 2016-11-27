/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:30:32 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/27 23:07:42 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_exec	g_exec[] =
{
	{TK_SEMI, &exec_semi},
	{TK_PIPE, &exec_pipe},
	{TK_LESS, &exec_less},
	{TK_GREAT, &exec_great},
	{TK_COMMAND, &exec_command},
	{0, 0},
};

int		ft_exec(t_btree *ast, t_data *data)
{
	t_astnode	*item;
	int			i;

	i = 0;
	item = ast->item;
	if(!ast)
		return (0);
	while (g_exec[i].type)
	{
		if (item->type == g_exec[i].type)
			return ((*g_exec[i].f)(ast, data));
		i++;
	}
	return (0);
}