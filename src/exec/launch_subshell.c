/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:11:44 by wescande          #+#    #+#             */
/*   Updated: 2017/03/13 13:27:48 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		do_subshell(t_process *p)
{
	int			ret;

	ft_exec(&p->data.subshell.content);
	ret = ft_atoi(ft_getenv(data_singleton()->env, "?"));
	DG("CHECK, ret=[%i]", ret);
	/* p = ft_lstlast(j->first_process)->content; */
	/* ret = p->status */
	/* DG("CHECK, ret=[%i]", ret); */
	return (ret);
}

int				launch_subshell(t_process *p)
{
	pid_t	pid;

	if (SH_IS_INTERACTIVE(data_singleton()->opts))
	{
		pid = fork();
		if (pid == 0)
		{
			data_singleton()->opts &= ~SH_INTERACTIVE;
			data_singleton()->opts &= ~SH_OPTS_JOBC;
			if (process_redirect(p))
				exit (1);
			process_setgroup(p, 0);
			process_setsig();
			exec_reset();
			exit(do_subshell(p));
		}
		else if (pid > 0)
			return (pid);
	}
	else
		do_subshell(p);
	return (0);
}
