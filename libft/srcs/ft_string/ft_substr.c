/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:01:16 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/21 18:33:34 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Alloue avec malloc et Retourne une chaine de caratères
**	issue de la chaine (*s).
**	Cette nouvelle chaine commence à l'index (start)
**	et a pour taille maximale (len).
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		++i;
	if (i < start || i == 0)
		len = 0;
	res = (char *)malloc((sizeof(*res)) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		++i;
	}
	res[len] = '\0';
	return (res);
}
