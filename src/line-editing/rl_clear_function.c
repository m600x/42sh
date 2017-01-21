/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_clear_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:34:29 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/21 22:36:01 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_clear_function(t_line *line, long int input)
{
	int	pos;

	if (RL_IS(line->bitset, RL_SELECT))
		RL_UNSET(line->bitset, RL_SELECT);
	curs_clear(&line->curs);
	rl_put_prompt(line);
	pos = line->pos;
	line->pos = 0;
	if (line->used)
		rl_reset_display_post(line);
	if (pos)
		curs_forward(&line->curs, pos);
	line->pos = pos;
	return (0);
	(void)input;
}
