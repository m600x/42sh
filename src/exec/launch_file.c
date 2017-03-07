/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:53:31 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 16:39:33 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		launch_file(t_process *p)
{
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		if (!p->stat)
		{
			ft_dprintf(2, "{red}%s: command not found: %s{eoc}\n", SHELL_NAME, p->av[0]);
			exit(127);
		}
		else if (IS_DIR(p->stat.st_mode))
		{
			ft_dprintf(2, "{red}%s: %s: Is a directory{eoc}\n", SHELL_NAME, p->av[0]);
			exit(126);
		}
		else if (access(p->path, X_OK) == -1)
		{
			ft_dprintf(2, "{red}%s: permission denied: %s{eoc}\n", SHELL_NAME, p->av[0]);
			exit(126);
		}
		process_setgroup(p, 0);
		process_setsig();
		if (process_redirect(p))
			exit (1);
		(*p->execf)(p->path, p->av, data_singleton()->env);
		ft_dprintf(2, "{red}%s: internal execve error on %s{eoc}\n", SHELL_NAME, p->av[0]);
	}
	else if (pid > 0)
		return (0);
	else if (pid == -1)
		ft_dprintf(2, "{red}%s: internal fork error{eoc}\n", SHELL_NAME);
	return (1);
}
