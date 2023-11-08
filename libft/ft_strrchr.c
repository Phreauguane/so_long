/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:18:06 by nbiron            #+#    #+#             */
/*   Updated: 2023/10/11 13:36:37 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*t;
	char	*out;

	t = (char *)s;
	out = NULL;
	while (*t)
	{
		if (*t == (unsigned char)c)
			out = t;
		t++;
	}
	if ((unsigned char)c == '\0')
		return (t);
	return (out);
}
