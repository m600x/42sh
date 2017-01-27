/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:09:57 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/26 14:58:02 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_stof g_builtin[] = {
	{"echo", &builtin_echo},
	{"cd", &builtin_cd},
	{"setenv", &builtin_setenv},
	{"unsetenv", &builtin_unsetenv},
	{"env", &builtin_env},
	{"exit", &builtin_exit},
	{"jobs", &builtin_jobs},
	{"fg", &builtin_fg},
	{"bg", &builtin_bg},
	{"history", &builtin_history},
	{NULL, NULL},
};

t_execf		*is_builtin(t_process *p)
{
	int		i;

	i = -1;
	while (g_builtin[++i].name)
		if (ft_strcmp(g_builtin[i].name, p->av[0]) == 0)
			return (g_builtin[i].f);
	return (NULL);
}
