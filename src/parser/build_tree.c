/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:32:59 by ariard            #+#    #+#             */
/*   Updated: 2017/02/15 20:51:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_treematch			g_treematch[] =
{
	{TK_N_WORD, &add_cmd},
	{TK_PIPE, &add_sep},
	{0, NULL},
};

int		build_tree(t_btree **ast, t_list **lst)
{
	int		i;
	t_token	*token;

	i = 0;
	token = (*lst)->content;
	while (g_treematch[i].type)
	{
		DG("func TK : '%s' TK : '%s'",
		read_state(g_treematch[i].type) ,read_state(token->type));
		if (g_treematch[i].type == token->type)
		   return (g_treematch[i].add(ast, lst));	
		i++;
	}
	return (0);
}
