/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_until.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:22:24 by wescande          #+#    #+#             */
/*   Updated: 2017/03/08 14:59:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		set_process_until(t_process *p, t_btree *ast)
{
	p->data.d_while.condition = btree_map(ast->left, &node_copy);
	p->data.d_while.content = btree_map(ast->right, &node_copy);
	p->type = PROCESS_UNTIL;
	return (0);
}
