/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:36:56 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/04 17:37:44 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	str_addchar(char *str, char c)
{
	while (*str)
		str++;
	str[0] = c;
	str[1] = '\0';
}

static void	itoa_proc(char *str, int n)
{
	long int	nb;

	nb = (long int)n;
	if (nb < 0)
	{
		str_addchar(str, '-');
		nb *= -1;
	}
	if (nb >= 10)
		itoa_proc(str, nb / 10);
	str_addchar(str, '0' + nb % 10);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = (char *)malloc(13 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	itoa_proc(str, n);
	return (str);
}
