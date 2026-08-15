/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:33:24 by iskaraag          #+#    #+#             */
/*   Updated: 2024/09/06 17:33:26 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_notreachable(t_map **nodes)
{
	error_main(nodes, 0);
	ft_printf("The collectible, exit and start should be reachable!\n");
	exit(1);
}

void	map_error_wrong_char(t_map **map)
{
	error_main(map, 0);
	ft_printf("There are not allowed characters in a map!\n");
	exit(1);
}

void	map_error_collectives(t_map **map)
{
	error_main(map, 0);
	ft_printf("There should be one P, one E and C's a map!\n");
	exit(1);
}

void	map_notrectangle(t_map **nodes)
{
	error_main(nodes, 0);
	ft_printf("The shape of the map must be rectangular!\n");
	exit(1);
}

void	map_notsurrounded(t_map **nodes)
{
	error_main(nodes, 0);
	ft_printf("The map must be surrounded by walls!\n");
	exit(1);
}
