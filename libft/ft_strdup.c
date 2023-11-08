/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:15:10 by nbiron            #+#    #+#             */
/*   Updated: 2023/10/02 20:32:42 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = ft_strlen(src);
	dest = (char *) malloc(sizeof(char *) * (i + 1));
	if (dest == NULL)
		return (NULL);
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
	return (dest);
}
