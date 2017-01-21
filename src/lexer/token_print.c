/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:39:01 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/19 23:44:34 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	token_print(t_list *lst)
{
	t_token		*token;
	int			i;
	t_type		type;

	while (lst)
	{
		i = -1;
		token = lst->content;
		type = token->type;
		while (type >> (i++ + 2))
			;
		DG("%02i '%s'", i, token->data);
		lst = lst->next;
	}
}
