#include "minishell.h"

int	instruction_free(t_list **token, t_parser *parser, t_btree **ast)
{	
	ft_lstdel(token, &token_free);
	token = NULL;
	ft_lstdel(&parser->stack, NULL);
	btree_del(ast, &ast_free);
	return (0);
}