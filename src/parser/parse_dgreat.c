/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dgreat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:49:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/03 16:35:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_dgreat(t_btree **ast, t_list **start, t_list **lst)
{
	t_astnode	*node;
	t_token		*tok;
	t_token		*next_tok;

	node = (*ast)->item;
	node->type = TK_DGREAT;
	if (!(*lst)->next)
		return (1);
	tok = (*lst)->content;
	next_tok = (*lst)->next->content;
	if (!(next_tok->type & TK_WORD))
		return (1);
	node->data.redir.n = ft_atoi(tok->data);
	node->data.redir.word.word = ft_strdup(next_tok->data);
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	ft_lst_delif(start, (*lst)->next->content, &ft_addrcmp, &token_free);
	ft_parse(&(*ast)->left, start);
	return (0);
}
