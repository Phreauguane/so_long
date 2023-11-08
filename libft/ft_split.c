/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:42 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/31 00:32:43 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_getnext(int *i, char const *s, char c)
{
	char	*str;
	int		len;
	int		j;

	while (s[*i] == c && s[*i])
		*i = *i + 1;
	len = 0;
	while (s[*i + len] != c && s[*i + len])
		len++;
	if (len == 0)
		return (NULL);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (j < len)
	{
		str[j] = s[*i + j];
		j++;
	}
	str[j] = '\0';
	*i += len;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		words;
	int		i;
	int		j;

	i = 0;
	j = 0;
	words = ft_strlen(s);
	out = (char **)malloc((words + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	while (1)
	{
		out[j] = ft_getnext(&i, s, c);
		if (!out[j])
			return (out);
		j++;
	}
	return (out);
}

void	ft_free_split(char **tab)
{
	char	**p;

	p = tab;
	while (p && *p)
	{
		free(*p);
		p++;
	}
	if (tab)
		free(tab);
}
