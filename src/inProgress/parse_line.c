/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:47:21 by jbernard          #+#    #+#             */
/*   Updated: 2022/04/22 11:23:50 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*

	DUMMY RESPONSE IN FIRST TIME

	# things to know:

	# Options
	
	# Faire des test de la vrai fonction:


	cmd < filein | cmd args opt |  cmd args "o'ts |  cmd args op | cmd > fileout
	# Workflow:
		[ ] quotes
		[ ] heredoc << dans STDIN
		[ ] isole les pipes, créer un process / pipe
			[ ] ouverture de tous les fichier < (suivante ecrase le precedent, dup2(stdin))
			[ ] ouverture de tous les fichiers > >> (suivante ecrase le precendent, dup2(stdout))
			[ ] fait la commande

	# Edge case:

	# Errors:
		[ ]  

*/




// cmd < filein | cmd args opt |  cmd args $opts |  'cmd' args op | cmd > fileout
// cmd < filein | cmd args opt |  cmd args "opts |  'cmd' args op | cmd > fileout
// cmd < filein | cmd args opt |  cmd "args $opts |  'cmd' args op" | cmd > fileout
// cmd < filein | cmd args opt |  cmd args "opts |  < < <'cmd' args op | cmd > fileout

int	parse_line(t_mnshl *vars, char *line)
{
	WHOAMI

	// function to append each cmds in tab
		// setup_cmds(vars, line);
	// function to open here_doc
		// open_heredoc(t_mnshl *vars)
	// function to launch cmds (execve)
		//execute_all_blocks(vars, )
	// Function to clean up cmds
		//clean_up();
	return (EXIT_SUCCESS);
}