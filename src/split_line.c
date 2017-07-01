/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 20:33:41 by opodolia          #+#    #+#             */
/*   Updated: 2017/07/01 18:37:26 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		count_commands(char *str)
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

char			***split_line(char *line)
{
	char			***args;
	int				i;
	int				numb;
	unsigned int	start;
	char			**tmp;

	i = 0;
	numb = 0;
	if (!(args = ft_memalloc(sizeof(char **) * (count_commands(line) + 1))) ||
		!(tmp = ft_memalloc(sizeof(char *) * (count_commands(line) + 1))))
		error_exit(mem_alloc_err);
	while (numb < count_commands(line))
	{
		while (line[i] && line[i] == ';')
			i++;
		start = (unsigned int)i;
		while (line[i] && line[i] != ';')
			i++;
		tmp[numb] = ft_strsub(line, start, (size_t)(i - start));
		args[numb] = split_commands(tmp[numb]);
		ft_memdel((void **)&(tmp[numb]));
		numb++;
	}
	ft_memdel((void **)&tmp);
	return (args);
}
