/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:32:26 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/24 19:09:44 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			fd_replace(int fd1, int fd2)
{
	DG("%i ----> %i", fd2, fd1);
	if (fd1 != fd2)
		return (dup2_close(fd1, fd2));
	return (0);
}
