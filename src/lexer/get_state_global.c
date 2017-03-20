/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_state_global.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:39:06 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 10:02:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexstate		get_state_global(t_lexer *lexer)
{
	char	c;
	char	cn;
	char	cl;
	int		ret;

	c = lexer->str[lexer->pos];
	cn = lexer->str[lexer->pos + 1];
	cl = lexer->str[lexer->pos ? lexer->pos - 1 : 0];
	ret = 0;
	if ((ft_is_delim(c) && (ret = DELIM))
		|| ((c == '&' || c == ';' || c == '|' || c == '!') && (ret = SEP))
		|| ((c == '\\') && (ret = BACKSLASH))
		|| ((c == '\'') && (ret = QUOTE))
		|| ((c == '\"') && (ret = DQUOTE))
		|| ((c == '`') && (ret = BQUOTE))
		|| ((c == '(' || c == ')') && (ret = PAREN))
		|| (((c == '{' && cn == ' ') || (c == '}' && cl == ' '))
			&& (ret = CURLY_BRACKETS))
		|| ((c == 0) && (ret = END)))
		;
	return (ret);
}
