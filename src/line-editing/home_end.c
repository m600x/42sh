/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:13:24 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/16 17:14:07 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_end(void)
{
	if (!STR)
		return (1);
	if (POS)
	{
		--POS;
		ft_get_beggin_with_curs(STR, &POS);
	}
	ft_puttermcaps("cd");
	while (STR[POS])
		++POS;
	ft_get_beggin(STR, &POS);
	ft_current_str(STR, POS);
	ft_get_next_str(STR, &POS);
	return (1);
}

int			ft_home(void)
{
	if (!STR)
		return (1);
	if (POS)
	{
		--POS;
		ft_get_beggin_with_curs(STR, &POS);
		if (STR[POS + 1] == '\n')
			ft_puttermcaps("nd");
	}
	ft_puttermcaps("cd");
	POS = 0;
	ft_current_str(STR, POS);
	ft_get_next_str(STR, &POS);
	ft_check_end_of_line(STR, POS);
	if (!STR[POS])
		--POS;
	ft_get_beggin_with_curs(STR, &POS);
	return (1);
}
