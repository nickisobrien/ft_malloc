/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 20:43:11 by nobrien           #+#    #+#             */
/*   Updated: 2018/10/02 20:40:07 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

static void	show_alloc_mem_helper(void *ptr, char *str)
{
	if (ptr)
	{
		printf("%s %p\n", str, ptr);
		while (1)
		{
			if (GET_ALLOC(ptr) == 1)
				printf("%p - %p : %lu bytes\n", ptr + OVERHEAD,
					ptr + OVERHEAD + GET_SIZE(ptr), GET_SIZE(ptr));
			if (IS_END(ptr))
			{
				if ((*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next)
					ptr = (*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next;
				else
					break ;
			}
			else
				ptr += OVERHEAD + GET_SIZE(ptr);
		}
	}
}

void		show_alloc_mem(void)
{
	show_alloc_mem_helper(global.tiny, "TINY:");
	show_alloc_mem_helper(global.small, "SMALL:");
	show_alloc_mem_helper(global.large, "LARGE:");
}
