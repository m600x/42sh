/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:25:17 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/15 10:47:33 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_setenv(const char *path, char *const av[], char *const envp[])
{
	char	*str;
	char	***env;
	int		i;

	(void)envp;
	(void)path;
	i = 0;
	if (ft_strcmp(av[0], "local") == 0)
	{
		env = &data_singleton()->local_var;
		av++;
	}
	else
		env = &data_singleton()->env;
	av++;
	if (!av[0])
	{
		ft_sstrprint(*env, '\n');
		ft_putchar('\n');
	}
	else if (!av[1])
		ft_putendl_fd("usage : name [space] value", 2);
	else
	{
		str = ft_str3join(av[0], "=", av[1]);
		while ((*env) && (*env)[i])
		{
			if (ft_strcmp((*env)[i], av[0]) == '=')
			{
				ft_strdel(&(*env)[i]);
				(*env)[i] = str;
				return (0);
			}
			i++;
		}
		*env = ft_sstradd(*env, str);
		ft_strdel(&str);
	}
	return (0);
}
