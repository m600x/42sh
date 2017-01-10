/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_getrank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:38:31 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 10:30:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_getrank(int (*rank)[2])
{
	t_job	*job;
	t_jobc	*jobc;
	t_list	*jlist;
	int		i;

	i = 0;
	jobc = &data_singleton()->jobc;
	jlist = jobc->first_job;
	(*rank)[0] = 0;
	(*rank)[1] = 0;
	while (jlist && i < 2)
	{
		job = jlist->content;
		if (job_is_stopped(job->id))
			(*rank)[i++] = job->id;
		jlist = jlist->next;
	}
}