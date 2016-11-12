/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:31:42 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/11 20:44:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "libft.h"

# define TK_LESS		0x0001
# define TK_GREAT		0x0002
# define TK_DLESS		0x0004
# define TK_DGREAT		0x0008
# define TK_LESSAND		0x0010
# define TK_GREATAND	0x0020
# define TK_SEMI		0x0040
# define TK_PIPE		0x0080
# define TK_WORD		0x0100

typedef long long			t_type;
typedef struct s_token		t_token;

struct s_token
{
	t_type	type;
	char	*data;
	int		size;
};

t_token	*token_init();
t_token	*token_getnext(int *pos,char *line);
int		ft_tokenize(t_list **alst, char *str);
int		token_append(t_token *token, char c);
void	token_free(void *data, size_t size);
void	token_print(t_list *lst);

#endif
