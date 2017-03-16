/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surch_in_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 10:43:16 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/16 17:12:05 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_clear_prompt(size_t *pos, size_t srch_pos)
{
	if (*pos)
	{
		ft_putnc('\b', *pos);
		(*pos) = 0;
	}
	ft_putnc('\b', data_singleton()->line.prompt_size + srch_pos + 1);
	ft_puttermcaps("cd");
}

static int	ft_surch_and_realloc(char **str, char **str_srch,
			int ret, size_t *srch_pos)
{
	if (!(*str_srch = ft_realloc_imput(*str_srch, ret, *srch_pos)))
		return (-1);
	++(*srch_pos);
	*str = ft_strget_history(*str_srch);
	return (1);
}

static void	ft_give_new_prompt(char *str_srch, size_t srch_pos)
{
	ft_clear_prompt(&POS, srch_pos);
	data_singleton()->line.prompt_size = 21;
	if (str_srch)
		ft_printf("\033[35m(reverse-i-search)`\033[32m%s\033[35m': \033[37m",
		str_srch);
	else
		ft_putstr("\033[35m(reverse-i-search)`': \033[37m");
	if (STR)
	{
		ft_current_str(STR, POS);
		ft_get_next_str(STR, &POS);
	}
}

static void	ft_modify_str(char *str_srch, size_t srch_pos)
{
	ft_clear_prompt(&POS, srch_pos);
	data_singleton()->line.is_prompt ? ft_prompt() : ft_putstr("> ");
	if (STR)
	{
		STR = ft_strdup(STR);
		ft_current_str(STR, POS);
		ft_get_next_str(STR, &POS);
	}
	free(str_srch);
}

int			ft_surch_in_history(void)
{
	char	*str_srch;
	int		ret;
	size_t	srch_pos;

	srch_pos = 0;
	str_srch = NULL;
	(STR) ? ft_strdel(&STR) : 0;
	while (42)
	{
		ft_give_new_prompt(str_srch, srch_pos);
		ret = 0;
		read(0, &ret, sizeof(int));
		if (ft_isprint(ret))
		{
			if (ft_surch_and_realloc(&STR, &str_srch, ret, &srch_pos) < 0)
				return (-1);
		}
		else if (ret == 127 && srch_pos)
		{
			--srch_pos;
			str_srch = ft_remove_imput(str_srch, srch_pos);
			ft_puttermcaps("le");
			STR = (!*str_srch) ? NULL : ft_strget_history(str_srch);
		}
		else if (ret != 127)
			break ;
	}
	ft_modify_str(str_srch, srch_pos);
	return (1);
}
