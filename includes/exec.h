/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:29:56 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/27 22:57:06 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# define PIPE_READ		0
# define PIPE_WRITE		1
# define STDIN			0
# define STDOUT			1

typedef long long		t_type;
typedef struct s_exec	t_exec;

struct s_exec
{
	t_type	type;
	int		(*f)(t_btree *ast, t_data *data);
};

extern t_exec	g_exec[];

int		ft_exec(t_btree *ast, t_data *data);

int		exec_semi(t_btree *ast, t_data *data);
int		exec_pipe(t_btree *ast, t_data *data);
int		exec_less(t_btree *ast, t_data *data);
int		exec_great(t_btree *ast, t_data *data);
int		exec_command(t_btree *ast, t_data *data);

#endif