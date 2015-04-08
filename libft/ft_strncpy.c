/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:33:18 by rbusseti          #+#    #+#             */
/*   Updated: 2014/01/25 13:03:34 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, char const *s2, size_t n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (n > 0)
	{
		if (s2[j] == '\0')
			s1[i] = '\0';
		else
		{
			s1[i] = s2[i];
			j++;
		}
		i++;
		n--;
	}
	return (s1);
}