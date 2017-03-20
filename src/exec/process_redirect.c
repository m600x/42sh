/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:04:18 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 15:57:02 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_itof		g_redirmap[] =
{
	{TK_LESS, redirect_less},
	{TK_GREAT, redirect_great},
	{TK_DLESS, redirect_dless},
	{TK_DGREAT, redirect_dgreat},
	{TK_LESSAND, redirect_lessand},
	{TK_GREATAND, redirect_greatand},
	{0, NULL},
};

static void	process_close(int fd1, int fd2)
{
	if (fd1 != fd2)
		close(fd1);
}

int			process_redirect(t_process *p)
{
	t_list	*redirs;
	t_redir	*redir;
	int		i;

	redirs = p->redirs;
	process_close(p->to_close, STDIN);
	while (redirs)
	{
		redir = redirs->content;
		if (redir->n > 9)
			return (bad_fd(redir->n));
		i = -1;
		while (g_redirmap[++i].id)
			if (g_redirmap[i].id == redir->type)
			{
				if ((g_redirmap[i].f)(redir))
					return (1);
				break ;
			}
		redirs = redirs->next;
	}
	process_close(p->fdin, STDIN);
	process_close(p->fdout, STDOUT);
	return (0);
}
