/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lexer_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:45:46 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/19 23:46:48 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexstate		get_lexer_state(char *str)
{
	if (ft_is_delim(*str))
		return (DELIM);
	else if (*str == '$')
		return (VAR);
	else if (*str == '&' || *str == ';' || *str == '|')
		return (SEP);
	else if (*str == '\\')
		return (BACKSLASH);
	else if (*str == '\'')
		return (QUOTE);
	else if (*str == '\"')
		return (DQUOTE);
	else if (*str == '(' || *str == ')' || *str == '`')
		return (SPECIAL);
	return (0);
}
