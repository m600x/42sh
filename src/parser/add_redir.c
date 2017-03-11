/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:39:05 by ariard            #+#    #+#             */
/*   Updated: 2017/03/11 19:57:02 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			isdir_sep(t_btree **ast, t_list **list)
{
	t_token		*token;
	t_astnode	*node;

	token = (*list)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if ((node->type == CMD || node->type == TK_IO_NUMBER
			|| node->type == TK_WHILE || node->type == TK_IF
			|| node->type == TK_FOR || node->type == SUBSHELL
			|| node->type == TK_CASE || node->type == TK_RBRACE
			|| node->type == TK_UNTIL)
			&& (token->type == TK_LESS || token->type == TK_GREAT
			|| token->type == TK_GREATAND || token->type == TK_LESSAND
			|| token->type == TK_DLESS || token->type == TK_DGREAT))
			return (1);
	}
	if (!*ast)
	{
		if (token->type == TK_LESS || token->type == TK_GREAT
			|| token->type == TK_GREATAND || token->type == TK_LESSAND
			|| token->type == TK_DLESS || token->type == TK_DGREAT)
			return (1);
	}
	return (0);
}

int			isdir_word(t_btree **ast, t_list **list)
{
	t_astnode	*node;
	t_token		*token;

	token = (*list)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if (token->type == TK_WORD && node->type == REDIR)
		{
			node->type = node->cache;
			node->cache = 0;
			return (1);
		}
	}
	return (0);
}

int			add_redir_word(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	t_redir		*redir;
	t_redir		*temp;

	token = (*lst)->content;
	node = (*ast)->item;
	if (node->data.cmd.redir)
	{
		redir = (ft_lstlast(node->data.cmd.redir))->content;
		redir->word = ft_strdup(token->data);
		if (redir->type == TK_DLESS)
		{
			temp = ft_lstlast((data_singleton()->heredoc_queue))->content;
			temp->word = redir->word;
		}
	}
	return (0);
}

static int	add_redir_type_number(t_btree **ast, t_list **lst)
{
	t_redir		*temp;
	t_redir		*temp_heredoc;
	t_astnode	*node;
	t_token		*token;

	token = (*lst)->content;
	node = (*ast)->item;
	temp = (ft_lstlast(node->data.cmd.redir))->content;
	temp->type = token->type;
	if (token->type == TK_DLESS)
	{
		temp_heredoc = data_singleton()->heredoc_queue->content;
		temp_heredoc->n = temp->n;
	}
	return (0);
}

int			add_redir_type(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	t_redir		redir;
	t_list		*temp;

	if (!*ast)
		gen_node(ast);
	token = (*lst)->content;
	node = (*ast)->item;
	if (!(node->type == TK_IO_NUMBER))
	{
		redir.n = (token->type == TK_LESS || token->type == TK_DLESS
		|| token->type == TK_LESSAND) ? STDIN : STDOUT;
		redir.type = token->type;
		redir.heredoc_data = NULL;
		redir.word = NULL;
		temp = ft_lstnew(&redir, sizeof(redir));
		DG("adr is %p", temp);
		ft_lsteadd(&node->data.cmd.redir, temp);
		DG("adr is %p", node->data.cmd.redir);
		if (token->type == TK_DLESS)
			ft_lsteadd(&data_singleton()->heredoc_queue, temp);
		DG("adr is %p", data_singleton()->heredoc_queue);
	}
	else
		add_redir_type_number(ast, lst);
	if (!node->cache)
		node->cache = node->type;
	node->type = REDIR;
	return (0);
}
