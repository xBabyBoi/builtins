/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-qori <yel-qori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:21:18 by rhafidi           #+#    #+#             */
/*   Updated: 2025/07/31 20:51:58 by yel-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"






int handle_builtins(t_tree *root, t_fd *fd, char ***env, char ***exported, int *exit_status)
{
    int exit_code;

    exit_code = *exit_status;
    if (!ft_strcmp(root->command[0], "echo"))
        exit_code = ft_echo(root->command, env, exit_status);
    else if (!ft_strcmp(root->command[0], "cd"))
        exit_code = ft_cd(root->command, env);
    else if (!ft_strcmp(root->command[0], "pwd"))
        exit_code = ft_pwd(root->command);
    else if (!ft_strcmp(root->command[0], "export"))
        exit_code = ft_export(root->command,env, exported, exit_status);
    else if (!ft_strcmp(root->command[0], "unset"))
        exit_code = ft_unset(root->command, env, exported);
    else if (!ft_strcmp(root->command[0], "env"))
        exit_code = ft_env(root->command, env[0]);
    else if (!ft_strcmp(root->command[0], "exit"))
        exit_code = ft_exit(root, *env, *exported, fd, exit_status);
    return (exit_code);
    
}
