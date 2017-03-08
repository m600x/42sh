/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:41:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 03:26:28 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_itof	g_freemap[] =
{
	{PROCESS_FUNCTION, process_free_subshell},
	{PROCESS_BUILTIN, NULL},
	{PROCESS_FILE, process_free_cmd},
	{PROCESS_SUBSHELL, process_free_subshell},
	{PROCESS_WHILE, process_free_cond},
	{PROCESS_UNTIL, process_free_cond},
	{PROCESS_IF, process_free_cond},
	{PROCESS_FOR, process_free_list},
	{PROCESS_CASE, process_free_list},
	{0, NULL}
};

void	process_free(void *content, size_t content_size)
{
	t_process	*p;

	p = content;
	(void)content_size;
	if (p->type >= PROCESS_MAX)
		return ;
	if (g_freemap[p->type].f)
		(g_freemap[p->type].f)(p);
	ft_lstdel(&p->redirs, ft_lst_cfree);
	free(p);
}
