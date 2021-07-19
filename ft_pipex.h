/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:05:24 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/07/08 12:15:31 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		ft_strlcat(char *dest, char *src, int max);
void	ft_bzero(void *str, int len);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlcpy(char *dest, char *src, int max);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_str3join(char *s1, char *s2, char *s3);
char	**ft_strsplit(char *s, char c);
char	*path_splitter(char *key, char **env);
int		ft_execve(char *path, char **cmd, char **env);
int		parent_exec(int pfd, char *path, char **argv, char **env);
int		child_exec(int pfd, char *path, char **argv, char **env);
int		ft_pipex(char *path, char *argv[], char **env);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_exit(int code, char *str);

#endif /* FT_PIPEX_H */
