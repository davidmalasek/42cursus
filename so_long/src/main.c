/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:49:21 by davidmalase       #+#    #+#             */
/*   Updated: 2024/12/13 13:38:31 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(void)
{
	char	*file_content;

	file_content = read_from_file("./maps/map2.ber");
	printf("\nMap loaded from file:\n\n");
	printf("%s", file_content);
	printf("\n\n---\n\n");
	is_map_valid(file_content);
	printf("\n");
	init_map(file_content);
}
