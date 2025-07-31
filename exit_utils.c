/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-qori <yel-qori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 20:50:21 by yel-qori          #+#    #+#             */
/*   Updated: 2025/07/31 20:51:16 by yel-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_mem(t_tree *root, char **env, char **exported, t_fd *fd)
{
	free_tree(&root);
	free(fd);
	free_array(env);
	free_array(exported);
}

void	exit_error(char **argv)
{
	ft_putstr_fd("exit\n", STDERR_FILENO);
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(argv[1], STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
}

int	many_args(void)
{
	ft_putstr_fd("exit\n", STDERR_FILENO);
	ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	ret_ex_code(char **argv)
{
	int	exit_code;

	if (argv[1])
		exit_code = ft_atoi(argv[1]);
	else
		exit_code = 0;
	return (exit_code);
}

void	clean_exit(t_tree *root, char **env, char **exported, t_fd *fd,
		int exit_status)
{
	free_mem(root, env, exported, fd);
	exit(exit_status);
}
