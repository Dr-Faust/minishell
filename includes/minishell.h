/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:09:50 by opodolia          #+#    #+#             */
/*   Updated: 2017/07/01 20:04:48 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft_printf/includes/ft_printf.h"
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <pwd.h>
# include <sys/stat.h>
# include <stdbool.h>

# define READ_LINE_BUFSIZE 1024

typedef struct		s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}					t_env;

typedef struct		s_var
{
	int				numb;
	int				flag;
	unsigned int	start;
}					t_var;

typedef enum
{
	mem_alloc_err,
}	t_err_exit;

typedef	enum
{
	cd_home_not_set,
	cd_oldpwd_not_set,
	cd_no_s_f_or_dir,
	cd_perm_denied,
	min_no_s_f_or_dir,
	min_perm_denied,
}	t_err_return;

t_env				*get_env_info(char **arr);
void				write_prompt(void);
char				*read_line(void);
char				***split_line(char *line);
char				**split_commands(char *line);
void				error_exit(int index);
int					error_return(int index, char *arg);
char				*parse_dollar(char *line, int i, t_env *env_info);
char				*get_env_var(char *var, t_env *env_info);
int					count_args(char *str);
int					execute(char **args, t_env **env_info);
char				**env_to_arr(t_env *env_info);
char				*verif_access(char *command, t_env *env_info);
int					lsh_num_builtins();
int					ft_echo(char **args);
int					ft_cd(char **args, t_env **env_info);
int					ft_env(t_env *env_info);
int					ft_setenv(t_env **env_info, char *var, char *value,
					char **args);
int					ft_unsetenv(t_env *env_info, char *var);
int					ft_help(void);

#endif
