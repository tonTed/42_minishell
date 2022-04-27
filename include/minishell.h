/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:37:36 by tonted            #+#    #+#             */
/*   Updated: 2022/04/27 00:46:09 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <signal.h>
# include "../libraries/libft/include/libft.h"
# include "../libraries/readline/includes/readline.h"
# include "../libraries/readline/includes/history.h"

# define PROMPT "cryptoShell> "
# define DQ '\"'
# define Q '\''
# define PIPE '|'

extern int g_status;

// # define WHOAMI printf(GRN"Function "BMAG"%s"GRN" ran "BGRN"SUCCESSFULLY\n"RESET, __func__);
# define WHOAMI ;

/*
	cmd: 		block command in string
	cmd_split:	splited block command
	flag:
		0x1 -> here_doc
*/
typedef struct s_heredoc
{
    int     index;
    char    *eof;
}   t_heredoc;

typedef	char* str;

typedef struct s_tab_cmds
{
	char		**cmd_split;	//cmd splitted with split_custom()
	char		*cmd;           // Full block of command
	char		*filein;
	char		flag; 		//Bitwise flags (See *)
	t_heredoc	*tab_heredoc;	//Index of command with heredoc
}			t_cmd_block;

typedef struct s_mnshl
{
	char 			**envp;
	int				last_errno;
    t_cmd_block 	*cmds_tab;
}			t_mnshl;

// prompt.c //
char	*prompt_DUMMY();

// ft_execute_line.c //
int	parse_line(t_mnshl *vars, char *line);

// init_vars.c //
void	init_vars(t_mnshl *vars, char **envp);
void	free_exit(t_mnshl *vars);

// heredoc.c //
int heredoc(t_mnshl *vars);

int	execute_all_blocks(t_mnshl *vars);
int	execute(t_mnshl *vars);

int	clean_up(t_mnshl *vars, char *line);

/*
--- * ---
0x1  -> quote
		0x2  -> dquote
		0x4  -> quote_end
		0x8  -> dquote_end
		0x16 -> $ and quote closed then pas interpreter
		0x32 -> heredoc
		0x64 -> 
		0x128 ->  
---------
*/