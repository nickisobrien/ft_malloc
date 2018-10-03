/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 20:43:11 by nobrien           #+#    #+#             */
/*   Updated: 2018/10/03 13:28:28 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

t_global		g_global;

static size_t	show_alloc_mem_helper(void *ptr, char *str)
{
	size_t bytes;

	bytes = 0;
	if (ptr)
	{
		printf("%s %p\n", str, ptr);
		while (1)
		{
			if (GET_ALLOC(ptr) == 1)
			{
				printf("%p - %p : %lu bytes\n", ptr + OVERHEAD,
					ptr + OVERHEAD + GET_SIZE(ptr), GET_SIZE(ptr));
				bytes += GET_SIZE(ptr);
			}
			if (IS_END(ptr))
				if ((*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next)
					ptr = (*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next;
				else
					break ;
			else
				ptr += OVERHEAD + GET_SIZE(ptr);
		}
	}
	return (bytes);
}

void			show_alloc_mem(void)
{
	unsigned int	bytes;

	bytes = 0;
	bytes += show_alloc_mem_helper(g_global.tiny, "TINY:");
	bytes += show_alloc_mem_helper(g_global.small, "SMALL:");
	bytes += show_alloc_mem_helper(g_global.large, "LARGE:");
	printf("Total : %u bytes\n", bytes);
}
