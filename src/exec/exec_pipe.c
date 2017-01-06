/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:13:23 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 17:15:22 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_pipe(t_btree **ast)
{
	int			fds[2];
	int			start;
	t_data		*data;
	t_process	*p;

	data = data_singleton();
	p = &data_singleton()->exec.process;
	pipe(fds);
	DG("pipe %i->%i", fds[PIPE_WRITE], fds[PIPE_READ]);
	p->fdout = fds[PIPE_WRITE];
	start = IS_PIPESTART(p->attributes);

	p->attributes &= ~PROCESS_PIPEEND;
	ft_exec(&(*ast)->left);
	p->attributes &= ~PROCESS_PIPESTART;

	DG("p->fdout=%i", p->fdout);
	close(p->fdout);
	p->fdout = STDOUT;
	p->fdin = fds[PIPE_READ];

	p->attributes |= PROCESS_PIPEEND;
	ft_exec(&(*ast)->right);
	if (start)
		p->attributes |= PROCESS_PIPESTART;

	close(p->fdin);
	p->fdin = STDIN;
	btree_delone(ast, &ast_free);
	return (0);
}
