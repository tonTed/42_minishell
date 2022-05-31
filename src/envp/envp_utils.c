/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:23:27 by jbernard          #+#    #+#             */
/*   Updated: 2022/05/31 12:43:53 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_name_in_line(char *envline, char *name)
{
	int	len;

	len = ft_strlen(name);
	if (!ft_strncmp(envline, name, len) && envline[len] == '=')
	{
		return (1);
	}
	return (0);
}

int	is_name_in_envp(char **envp, char *name)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (is_name_in_line(envp[i], name))
			return (i);
		i++;
	}
	return (-1);
}

char	*build_envp_line(char *name, char *value)
{
	char	*line;

	line = ft_strjoin(name, "=");
	line = ft_strjoin(line, value);
	return (line);
}

/* _____________________________________________________________________________________________*/

/* Remove line from vars.envp
 *
 *	Arguments : 
 *		{t_mnshl}	{*vars}	: pointer to main struct of the program
 *		{char}		{*name} : name of environnement variable to remove.
 *
 *	Returns : 
 *		-- NOTHING --
 */
// TODO check is case sensitive
void	envp_remove_line(char **envp, char *name)
{
	int		i_old;
	int		i_new;
	char	**n_envp;
	if (is_name_in_envp(envp, name) >= 0)
	{
		n_envp = (char **)malloc(sizeof(char *) * (ft_strtablen(envp)));
		if (!n_envp)
			return ;
		i_old = 0;
		i_new = 0;
		while (envp[i_old])
		{
			if (!is_name_in_line(envp[i_old], name))
				n_envp[i_new++] = envp[i_old];
			else
			{
				free(envp[i_old]);
				envp[i_old] = NULL;
			}
			i_old++;
		}
		n_envp[i_new] = NULL;
		free(envp);
		envp = n_envp;
	}
}

/* Set line in envp from main structure of program. If not exists the
 * environement variables is create.
 *
 *	Arguments : 
 *		{t_mnshl *}	{vars}	: pointer to main struct of the program
 *		{char *}	{*name} : name of environnement variable to set.
 *
 *	Returns : 
 *		-- NOTHING --
 */
// TODO check is case sensitive
void	envp_set_line(char **envp, char *name, char *value)
{
	int		i;
	char	*n_line;
	char	**n_envp;
	
	n_line = build_envp_line(name, value);
	i = is_name_in_envp(envp, name);
	if (i >= 0)
	{
		free(envp[i]);
		envp[i] = n_line;
	}
	if (i < 0)
	{
		i = 0;
		n_envp = (char **)malloc(sizeof(char *) * (ft_strtablen(envp) + 2));
		if (!n_envp)
			return ;
		while (envp[i])
		{
			n_envp[i] = envp[i];
			i++;
		}
		n_envp[i++] = n_line;
		n_envp[i] = NULL;
		free(envp);
		envp = n_envp;
	}
}

/* Set line in envp from main structure of program. If not exists the
 * environement variables is create.
 *
 *	Arguments : 
 *		{t_mnshl *}	{vars}	: pointer to main struct of the program
 *		{char *}	{*name} : name of environnement variable to set.
 *
 *	Returns : 
 *		{char *} : pointeur to the value start in vars.envp
 */
// TODO check is case sensitive
char	*envp_get_value_line(char **envp, char *name)
{
	char	*ret;
	int		i;

	ret = NULL;
	i = is_name_in_envp(envp, name);
	if (i >= 0)
	{
		ret = &envp[i][ft_strlen(name) + 1];
		return (ret);
	}
	return (ret);
}
