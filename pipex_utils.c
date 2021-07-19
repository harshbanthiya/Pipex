/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:17:25 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/07/07 12:53:14 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*ft_str3join(char *s1, char *s2, char *s3)
{
	int		size;
	int		i;
	char	*str;

	if (s1 == 0 || s2 == 0 || s3 == 0)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	str = (char *)malloc((size + 1) * sizeof(*str));
	i = -1;
	while (*s1)
		str[++i] = *s1++;
	while (*s2)
		str[++i] = *s2++;
	while (*s3)
		str[++i] = *s3++;
	str[++i] = 0;
	return (str);
}

char	**ft_malloc_words(char const *s, char c)
{
	char	**str;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			size++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	str = (char **)malloc((size + 1) * sizeof(str));
	if (str == 0)
		return (0);
	str[size] = 0;
	return (str);
}

void	ft_malloc_letters(char const *s, char c, char **str)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			size = 0;
			while (s[i] != c && s[i])
			{
				size++;
				i++;
			}
			str[j] = (char *)malloc((size + 1) * sizeof(*str));
			if (str[j] == 0)
				return ;
			ft_bzero(str[j], size);
			j++;
		}
		else
			i++;
	}
}

char	**ft_strsplit(char *s, char c)
{
	int		size;
	int		i;
	int		j;
	char	**str;

	size = 0;
	i = 0;
	if (s == 0)
		return (0);
	str = ft_malloc_words(s, c);
	ft_malloc_letters(s, c, str);
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i] != c && s[i])
				str[size][j++] = s[i++];
			str[size][j] = 0;
			size++;
		}
		else
			i++;
	}
	return (str);
}
