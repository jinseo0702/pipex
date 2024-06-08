/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:57:03 by jinseo            #+#    #+#             */
/*   Updated: 2024/06/06 16:57:05 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int argc, char **argv, char **envp)
{
    if (argc == 5)
    {
        char *str = ft_re_path(envp, argv[2]);
        printf("%s\n", str);
        free(str);
    }
    else
    {
        perror("NOT form plz modify");
        exit(1);
    }
    // printf("%s\n", ft_re_path(envp));

    return (0);
}
