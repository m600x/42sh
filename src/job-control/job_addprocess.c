/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_addprocess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:54:51 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/03 18:16:00 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		job_addprocess(t_process *p)
{
	t_jobc	*jobc;
	t_job	*job;

	jobc = &data_singleton()->jobc;
	job = &data_singleton()->exec.job;
	DG("check; attr=%b", p->attributes);
	if (IS_PIPESTART(p->attributes))
	{
		DG("check");
		job_update_id();
		job->id = jobc->current_id;
		ft_lstadd(&jobc->first_job, ft_lstnew(job, sizeof(*job)));
		DG("added new job [%i]", job->id);
	}
	job = jobc->first_job->content;
	if (p->pid > 0)
	{
		ft_lstadd(&job->first_process, ft_lstnew(p, sizeof(*p)));
		DG("added process to first_job : %i", p->pid);
	}
	if (JOB_IS_BG(job->attributes) && IS_PIPEEND(p->attributes))
		job_notify_new(job);
	return(0);
}
