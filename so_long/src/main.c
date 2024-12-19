/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:49:21 by davidmalase       #+#    #+#             */
/*   Updated: 2024/12/19 15:56:43 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int	main(void)
// {
// 	char	*file_content;

// 	file_content = read_from_file("./maps/map1.ber");
// 	printf("\nMap loaded from file:\n\n");
// 	printf("%s", file_content);
// 	printf("\n\n---\n\n");
// 	is_map_valid(file_content);
// 	printf("\n");
// 	init_map(file_content);
// 	mlx_init(300, 300, "Hello World", false);
// }

void	close_window(void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	mlx_terminate(mlx);
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	mlx_t *mlx = mlx_init(800, 600, "Hello World", true);
	if (!mlx)
		return (1);

	mlx_close_hook(mlx, close_window, mlx); // Set up close event

	mlx_loop(mlx); // Enter main rendering loop

	return (0);
}