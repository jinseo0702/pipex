/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:59:09 by jinseo            #+#    #+#             */
/*   Updated: 2024/04/07 14:28:56 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(const char *s)
{
	ssize_t	cnt;

	cnt = 0;
	if (s == NULL)
	{
		cnt += write(1, "(null)", 6);
		return ((int)cnt);
	}
	while (*s)
	{
		cnt += write(1, s, 1);
		s++;
	}
	return ((int)cnt);
}
