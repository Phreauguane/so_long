/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:19:56 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/24 17:00:28 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_st_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*str_addc(char *str, char c)
{
	char	*temp;
	size_t	len;

	len = 0;
	if (str)
		len = ft_st_strlen(str);
	temp = (char *)malloc(sizeof(char) * (len + (int)(c != '\0') + 1));
	if (temp == NULL)
		return (NULL);
	if (str)
		ft_memcpy(temp, str, len);
	temp[len] = c;
	if (c != '\0')
		temp[len + 1] = '\0';
	if (str)
		free(str);
	return (temp);
}

char	*str_adds(char *str, char *s, size_t src_len)
{
	char	*out;
	size_t	i;

	out = str;
	i = 0;
	while (s[i] && i < src_len)
	{
		out = str_addc(out, s[i]);
		i++;
	}
	return (out);
}

int	stchr(char *s, char c)
{
	while (s && (*s || *s == c))
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}
