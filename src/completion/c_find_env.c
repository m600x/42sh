/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_find_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:50:24 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/16 08:28:19 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Create a new list node and add it by calling c_add_to_lst.
*/

static int	c_addnode(t_comp *c, char *value)
{
	t_clst	*tmp;

	if (!(tmp = (t_clst *)malloc(sizeof(t_clst))))
		return (-1);
	tmp->name = value;
	tmp->len = ft_strlen(tmp->name);
	tmp->type = 10;
	tmp->cursor = 0;
	c_add_to_lst(c, tmp);
	return (0);
}

/*
** Search in the env for matching element and add them to the list if matched.
*/

int			c_seek_env(t_comp *c, char *current_word)
{
	char	**env;
	int		i;

	i = 0;
	env = data_singleton()->env;
	c->match = ft_strdupi_w(current_word + 1);
	while (env[i])
	{
		if (!ft_strncmp(c->match, env[i], ft_strlen(c->match)) &&
				env[i][ft_strlen(c->match)] != '=')
			c_addnode(c, ft_strndup(env[i], ft_strchr(env[i], '=') - env[i]));
		++i;
	}
	return (0);
}