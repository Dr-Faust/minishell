/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 18:19:55 by opodolia          #+#    #+#             */
/*   Updated: 2017/07/01 20:04:46 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_exit(int index)
{
	char	*error[1];

	error[0] = "minishell: allocation error";
	ft_printf("%s\n", error[index]);
	exit(EXIT_FAILURE);
}

int		error_return(int index, char *arg)
{
	char	*error[6];

	error[0] = "cd: HOME not set\n";
	error[1] = "cd: OLDPWD not set\n";
	error[2] = "cd: no such file or directory: ";
	error[3] = "cd: permission denied: ";
	error[4] = "minishell: no such file or directory: ";
	error[5] = "minishell: permission denied: ";
	ft_printf("%s", error[index]);
	if (arg)
		ft_printf("%s\n", arg);
	return (1);
}
