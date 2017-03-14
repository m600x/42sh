/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pset_while.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:38:10 by wescande          #+#    #+#             */
/*   Updated: 2017/03/13 20:31:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pset_while(t_process *p, t_btree *ast)
{
	p->data.d_while.condition = btree_map(ast->left, &node_copy);
	p->data.d_while.content = btree_map(ast->right, &node_copy);
	p->type = PROCESS_WHILE;
	return (0);
}