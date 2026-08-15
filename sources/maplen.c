/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maplen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:34:14 by iskaraag          #+#    #+#             */
/*   Updated: 2024/09/06 17:34:15 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	mapwidth(t_map *map)
{
	return (ft_strlen(map->mtxt));
}

int	mapheight(t_map *map)
{
	int	i;

	i = 1;
	while (map->nxt != NULL)
	{
		map = map->nxt;
		i++;
	}
	return (i);
}
