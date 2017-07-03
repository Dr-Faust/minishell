/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 20:33:41 by opodolia          #+#    #+#             */
/*   Updated: 2017/07/03 20:29:12 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clean_up(char **args, char *cmd)
{
	int		i;

	i = -1;
	while (args[++i])
		ft_memdel((void **)&(args[i]));
	ft_memdel((void **)&(args));
	ft_memdel((void **)&cmd);
}

int			count_commands(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ';')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ';')
			i++;
	}
	return (count);
}

int			split_line(char *line, t_env **env_info, int status, char ***args)
{
	char			*cmd;
	int				i;
	int				numb;
	unsigned int	start;
	int				j;

	i = 0;
	numb = -1;
	while (++numb < count_commands(line))
	{
		while (line[i] && line[i] == ';')
			i++;
		start = (unsigned int)i;
		while (line[i] && line[i] != ';')
			i++;
		cmd = ft_strsub(line, start, (size_t)(i - start));
		j = -1;
		while (cmd[++j])
			if (cmd[j] == '$' && cmd[j + 1] && ft_isalnum(cmd[j + 1]))
				cmd = parse_dollar(cmd, j, *env_info);
		args[numb] = split_command(cmd);
		status = execute(args[numb], env_info);
		clean_up(args[numb], cmd);
	}
	return (status);
}
