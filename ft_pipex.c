/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:09:59 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/07/08 12:13:11 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"ft_pipex.h"

char	*path_splitter(char *key, char **env)
{
	int		i;
	int		key_len;

	i = 0;
	key = ft_strjoin(key, "=");
	key_len = ft_strlen(key);
	while (env[i] != 0)
	{
		if (ft_strncmp(env[i], key, key_len) == 0)
			return (env[i] + key_len);
		i++;
	}
	return (0);
}

int	ft_execve(char *path, char **cmd, char **env)
{
	char		**tab;
	char		*tmp;
	int			i;

	i = 0;
	tab = ft_strsplit(path, ':');
	while (tab[i])
	{
		if (cmd[0][0] != '/')
			tmp = ft_str3join(tab[i], "/", cmd[0]);
		else
			tmp = cmd[0];
		execve(tmp, cmd, env);
		tmp = 0;
		++i;
	}
	return (0);
}

int	parent_exec(int pipefd, char *path, char **argv, char **env)
{
	int		fd;
	char	**cmd;
	char	*str;

	cmd = ft_strsplit(argv[2], ' ');
	if (!cmd[0])
		ft_exit(-1, "Empty command");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		str = ft_str3join(": ", argv[1], "no such file");
		ft_exit(access(argv[1], F_OK), str);
		str = ft_str3join(": ", argv[1], "permission denied");
		ft_exit(access(argv[1], R_OK), str);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pipefd, STDOUT_FILENO);
	close(pipefd);
	ft_execve(path, cmd, env);
	ft_exit(-1, "Command not found");
	return (0);
}

int	child_exec(int pipefd, char *path, char **argv, char **env)
{
	int		fd;
	char	**cmd;
	char	*str;

	cmd = ft_strsplit(argv[3], ' ');
	if (!cmd[0])
		ft_exit(-1, "Empty command");
	fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU | S_IRGRP
			  | S_IROTH);
	if (argv[4] && fd == -1)
	{
		str = ft_str3join(": ", argv[4], "permission denied");
		ft_exit(access(argv[4], R_OK), str);
		ft_exit(-1, ft_str3join(": ", argv[4], "no such file"));
	}
	dup2(pipefd, STDIN_FILENO);
	close(pipefd);
	if (argv[4])
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	ft_execve(path, cmd, env);
	ft_exit(-1, "Command not found");
	return (0);
}

int	ft_pipex(char *path, char *argv[], char **env)
{
	pid_t	pid;
	int		fd[2];
	int		i;

	i = 0;
	ft_exit(pipe(fd), "pipe error");
	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		child_exec(fd[0], path, argv, env);
	}
	else
	{
		close(fd[0]);
		parent_exec(fd[1], path, argv, env);
	}
	return (0);
}
