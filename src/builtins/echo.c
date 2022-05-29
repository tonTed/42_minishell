/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:38:35 by tonted            #+#    #+#             */
/*   Updated: 2022/05/29 11:04:29 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	# Options
		-n
	
	# Faire des test de la vrai fonction:
	Exemples:
				echo : prints empty newline
				echo x : prints "x\n"
				echo bonjour x : prints "bonjour x\n"
				echo -n : Prints nothing
				echo -n bonjour : prints "bonjour" (No newline)
				echo "Bonjour" "Allo" : prints "Bonjour Allo" (With space in between each args)
 	# Process

	# Edge case:

	# Errors:
		[ ]  

	# COMPILE :
	 	gcc echo.c -o echo
*/



void	ft_echo(char **args, char **env, int fd_out)
{
	int	argc;
	int	i;
	int nl;
	
	nl = 1;
	if (!ft_strncmp(args[0], "-n", 2))
	{
		nl = 0;
		args++;
	}
	argc = ft_strtablen(args);
	i = 0;
	while (i < argc)
	{
		ft_putstr_fd(args[i], fd_out);
		if (i != argc - 1)
			ft_putchar_fd(' ', fd_out);
		i++;
	}
	if (nl)
		ft_putchar_fd('\n', fd_out);
}

// int	main(int argc, char **argv)
// {
// 	char **d_envp = NULL;

// 	argc--;
// 	argv++;
// 	ft_echo(argv, d_envp, 1);
// 	return (0);
// }