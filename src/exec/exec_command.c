/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:28:14 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/01 16:32:26 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char			**token_to_argv(t_astnode *node)
{
	char	**my_tab;
	int		index;
	char	**expand;
	char	**content;
	t_ld	*ld;

	if (node->type == TK_WORD || node->type == TK_ASSIGNEMENT_WORD)
	{
		ld = NULL;
//		ld = node->data.cmd.token;
		my_tab = NULL;
		while (ld)
		{
			content = ld->content;
			if ((expand = glob(content[0], (unsigned char *)content[1], (unsigned char *)content[2])))
			{
				index = -1;
				while (expand[++index])
					my_tab = ft_sstradd(my_tab, expand[index]);
				ft_tabdel(&expand);
			}
			ld = ld->next;
		}
		return (my_tab);
	}
	else if (node->type == TK_SUBSHELL)
		return (ft_sstrdup(node->data.sstr));
	return (NULL);
}

int				exec_command(t_btree **ast)
{
	t_astnode	*node;
	t_process	*p;
	t_job		*job;

	node = (*ast)->item;
	p = &data_singleton()->exec.process;
	job = &data_singleton()->exec.job;
	p->av = token_to_argv(node);
	process_setexec(node->type, p);
	if (!(launch_process(p)))
	{
		job_addprocess(p);
		if (IS_PIPEEND(p->attributes))
		{
			JOB_IS_FG(job->attributes) ?
				put_job_in_foreground(job, 0):
				put_job_in_background(job, 0);
			job->pgid = 0;
		}
	}
	process_reset(p);
//	btree_delone(ast, &ast_free);
	return (0);
}
