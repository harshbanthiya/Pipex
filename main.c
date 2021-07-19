/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:04:03 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/07/08 12:13:35 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

void 	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	ft_exit(int code, char *str)
{
	if (code < 0)
	{
		ft_putstr_fd("PERMISSION DENIED:", 2);
		ft_putendl_fd(str, 2);
		exit(1);
	}
}

int 	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	main(int argc, char *argv[])
{
	char			*path;
	extern char		**environ;

	if (argc < 4)
		ft_exit(-1, ": usage: ./pipex file1 cmd1 cmd2 file2");
	path = path_splitter("PATH", environ);
	if (path == NULL)
		ft_exit(-1, "error: can't get PATH environment variable");
	signal(SIGPIPE, SIG_IGN);
	ft_pipex(path, argv, environ);
	return (0);
}
