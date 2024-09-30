/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:43:00 by dmalasek          #+#    #+#             */
/*   Updated: 2024/09/30 16:18:11 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_lstadd_front
** Adds a new element to the beginning of a linked list
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
