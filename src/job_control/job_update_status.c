/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_update_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:56:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 03:07:57 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	job_update_status(void)
{
	int		status;
	pid_t	pid;

	while (1)
	{
		if ((pid = waitpid(WAIT_ANY, &status, WUNTRACED | WNOHANG)) == -1
				&& errno != ECHILD)
			SH_ERR("waitpid(): %s", strerror(errno));
		DG("wait trigger pid=%i", pid);
		if (pid <= 1 || mark_process_status(pid, status))
			break ;
	}
}
