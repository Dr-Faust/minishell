/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:10:03 by opodolia          #+#    #+#             */
/*   Updated: 2017/07/01 13:11:08 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clean_up(char ***args)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (args[++i])
	{
		while (args[i][++j])
			ft_memdel((void **)&(args[i][j]));
		ft_memdel((void **)&(args[i]));
		j = -1;
	}
	ft_memdel((void **)&(args));
}

static char	***parse_line(char *line, t_env **env_info)
{
	int		i;
	char	***args;

	i = -1;
	while (line[++i])
		if (line[i] == '$' && line[i + 1] && ft_isalnum(line[i + 1]))
			line = parse_dollar(line, i, *env_info);
	args = split_line(line);
	ft_memdel((void **)&line);
	return (args);
}

static void	init_term(t_env **env_info)
{
	char	*line;
	char	***args;
	int	status;
	int		i;

	status = 1;
	while (status)
	{
		i = -1;
		write_prompt();
		line = read_line();
		args = parse_line(&(line[0]), env_info);
		while (args[++i] && status)
			status = execute(args[i], env_info);
		clean_up(args);
	}
}

int			main(void)
{
	extern char	**environ;
	t_env		*env_info;

	env_info = get_env_info(environ);
	init_term(&env_info);
	return (EXIT_SUCCESS);
}
