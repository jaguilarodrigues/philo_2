/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:32:51 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/10 20:33:06 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*copydest;
	char	*copysrc;

	i = 0;
	copydest = (char *)dest;
	copysrc = (char *)src;
	if ((!(dest) && !(src)) && (n > 0))
		return (NULL);
	while (i < n)
	{
		copydest[i] = copysrc[i];
		i++;
	}
	return (copydest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (!dest || !src)
		return (0);
	while (src[len] != '\0')
		++len;
	if (len + 1 < size)
		ft_memcpy(dest, (char *)src, len + 1);
	else if (size != 0)
	{
		ft_memcpy(dest, (char *)src, size - 1);
		dest[size - 1] = '\0';
	}
	return (len);
}
