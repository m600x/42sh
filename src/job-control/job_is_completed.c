/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_is_completed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:10:20 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 15:24:25 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		job_is_completed(t_job *job)
{
	t_list		*lst;
	t_process	*p;

	lst = job->first_process;
	while (lst)
	{
		p = lst->content;
		if (!(p->attributes & PROCESS_COMPLETED))
		{
			DG("process %i is not completed", p->pid);
			return (0);
		}
		lst = lst->next;
	}
	return (1);
}
