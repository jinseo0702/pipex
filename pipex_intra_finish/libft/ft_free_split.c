/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:37:43 by jinseo            #+#    #+#             */
/*   Updated: 2024/06/17 13:55:31 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **split)
{
	int	zero;

	zero = 0;
	while (split[zero])
	{
		free(split[zero]);
		split[zero] = NULL;
		zero++;
	}
	free(split);
	split = NULL;
}
