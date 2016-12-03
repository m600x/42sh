/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lessand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:58:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 11:58:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_lessand(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_LESSAND;
	if (ft_isdigit(*str))
	{
		token_append(token, *str);
		return (lexer_lessand(alst, str + 1));
	}
	else if (*str == '-')
	{
		token_append(token, *str);
		return (ft_tokenize(&(*alst)->next, str + 1, DEFAULT));
	}
	return (ft_tokenize(alst, str, DEFAULT));
}
