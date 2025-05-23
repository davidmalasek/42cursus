/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidmalasek <davidmalasek@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:39:26 by davidmalase       #+#    #+#             */
/*   Updated: 2025/04/09 22:01:49 by davidmalase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * argv[0] / ./philo
 * argv[1] - number_of_philosophers
 * argv[2] - time_to_die
 * argv[3] - time_to_eat
 * argv[4] - time_to_sleep
 * argv[5] - number_of_times_each_philosopher_must_eat (optional)
 */
int	main(int argc, char **argv)
{
	t_simulation	*sim;

	if (argc < 5 || argc > 6)
		return (0);
	if ((argc == 5 || argc == 6) && check_arguments(argc, argv))
	{
		sim = init(argc, argv);
		//free(sim);
	}
}

/*
TODO:
- no ft_*, libft not allowed
*/
