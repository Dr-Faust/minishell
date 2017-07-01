/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:56:13 by opodolia          #+#    #+#             */
/*   Updated: 2017/06/22 16:03:32 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand_buffer(int position, int *bufsize, char **buffer)
{
	if (position >= *bufsize)
	{
		*bufsize += READ_LINE_BUFSIZE;
		free(buffer);
		if (!(*buffer = (char *)malloc(sizeof(char) * (*bufsize))))
			exit(EXIT_FAILURE);
	}
}

char		*read_line(void)
{
	int		bufsize;
	int		position;
	char	*buffer;
	int		c;

	bufsize = READ_LINE_BUFSIZE;
	position = 0;
	if (!(buffer = (char *)malloc(sizeof(char) * bufsize)))
		exit(EXIT_FAILURE);
	while (42)
	{
		c = ft_getchar();
		if (c == EOF)
			exit(EXIT_SUCCESS);
		else if (c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
			buffer[position] = (char)c;
		position++;
		expand_buffer(position, &bufsize, &buffer);
	}
}
