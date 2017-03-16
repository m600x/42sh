/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:15:35 by ariard            #+#    #+#             */
/*   Updated: 2017/03/16 15:52:35 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_errormatch	g_errormatch[] =
{
	{TK_NEWLINE, "newline"},
	{TK_SEMI, ";"},
	{TK_DSEMI, ";;"},
	{TK_PIPE, "|"},
	{TK_AMP, "&"},
	{TK_LESS, "<"},
	{TK_GREAT, ">"},
	{TK_DGREAT, ">>"},
	{TK_LESSAND, "<&"},
	{TK_GREATAND, ">&"},
	{TK_LESSGREAT, "<>"},
	{TK_CLOBBER, ">|"},
	{TK_DLESS, "<<"},
	{TK_DLESSDASH, "<<-"},
	{TK_AND_IF, "&&"},
	{TK_OR_IF, "||"},
	{TK_IF, "if"},
	{TK_THEN, "then"},
	{TK_ELSE, "else"},
	{TK_ELIF, "elif"},
	{TK_FI, "fi"},
	{TK_DO, "do"},
	{TK_DONE, "done"},
	{TK_CASE, "case"},
	{TK_ESAC, "esac"},
	{TK_WHILE, "while"},
	{TK_UNTIL, "until"},
	{TK_FOR, "for"},
	{TK_LBRACE, "{"},
	{TK_RBRACE, "}"},
	{TK_PAREN_OPEN, "("},
	{TK_PAREN_CLOSE, ")"},
	{TK_BANG, "!"},
	{TK_IN, "in"},
	{0, NULL},
};

int				error_syntax(t_list **lst, t_parser *parser,
				t_btree **ast)
{
	t_token		*token;
	int			i;

	if (!*lst)
		return (0);
	token = (*lst)->content;
	i = 0;
	while (g_errormatch[i].token)
	{
		if (g_errormatch[i].token == token->type)
		{
			ft_dprintf(2, "syntax error near unexpected token « %s »\n",
					g_errormatch[i].error);
			instruction_free(lst, parser, ast);
			return (0);
		}
		i++;
	}
	ft_dprintf(2, "syntax error near unexpected token « %s »\n", token->data);
	instruction_free(lst, parser, ast);
	return (0);
}

int				error_eof(t_list **lst, t_parser *parser, t_btree **ast)
{
	ft_putstr_fd("syntax error near unexpected EOF", 2);
	instruction_free(lst, parser, ast);
	return (0);
}
