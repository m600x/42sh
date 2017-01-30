/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_semi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:52:05 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/30 17:34:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_semi(t_btree **ast)
{
	ft_exec(&(*ast)->left);
	ft_exec(&(*ast)->right);
	btree_delone(ast, &ast_free);
	return (0);
}
