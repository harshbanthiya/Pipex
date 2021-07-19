/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:20:15 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/07/07 13:02:18 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int 	ft_strlcat(char *dest, char *src, int max)
{
	int		i;

	i = 0;
	while (*dest && i < max)
	{
		i++;
		dest++;
	}
	while (*src && i + 1 < max)
	{
		*dest++ = *src++;
		i++;
	}
	if (i < max)
		*dest = 0;
	while (*src++)
		i++;
	return (i);
}

void 	ft_bzero(void *str, int len)
{
	while (len--)
		*(char *)str++ = 0;
}

int 	ft_strncmp(char *s1, char *s2, int n)
{
	int		index;

	index = 0;
	if (n == 0)
		return (index);
	while (*s1 && *s2 && index < n)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		index++;
	}
	if (index == n)
	{
		s1--;
		s2--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int 	ft_strlcpy(char *dest, char *src, int max)
{
	int		i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (src[i] && i + 1 < max)
	{
		dest[i] = src[i];
		i++;
	}
	if (max != 0)
		dest[i] = 0;
	while (src[i])
		i++;
	return (i);
}

char 	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*ptr;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(len);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, len);
	ft_strlcat(ptr, s2, len);
	return (ptr);
}
