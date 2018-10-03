/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:18:16 by nobrien           #+#    #+#             */
/*   Updated: 2018/10/03 13:11:52 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

t_global		g_global;

int				get_type(size_t num)
{
	if (num <= TINY)
		return (0);
	if (num <= SMALL)
		return (1);
	return (2);
}

void			*helper(void *ptr, size_t size, int type)
{
	void	*new_memory;

	if (GET_ALLOC(ptr) || GET_SIZE(ptr) < size + OVERHEAD * 2)
	{
		if ((*(t_node*)(ptr + GET_SIZE(ptr))).next)
			find_spot((*(t_node*)(ptr + GET_SIZE(ptr))).next, size, type);
		else
		{
			new_memory = init_memory(size, type);
			(*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next = new_memory;
			return (new_memory);
		}
	}
	else
	{
		new_memory = ptr;
		(*(t_block*)ptr).size = size;
		(*(t_block*)ptr).allocated = 1;
		(*(t_block*)ptr).is_end = 0;
		(*(t_block*)(ptr + OVERHEAD +
			size)).size = GET_SIZE(new_memory) - OVERHEAD - size;
		(*(t_block*)(ptr + OVERHEAD + size)).allocated = 0;
		(*(t_block*)(ptr + OVERHEAD + size)).is_end = IS_END(new_memory);
	}
	return (ptr);
}

void			*find_spot(void *ptr, size_t size, int type)
{
	if (!ptr)
		return (NULL);
	while ((GET_ALLOC(ptr) || GET_SIZE(ptr) < size + OVERHEAD * 2))
	{
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
	return (helper(ptr, size, type));
}

void			*init_memory(size_t size, int type)
{
	void	*addr;
	int		page_total;

	page_total = PAGE_SIZE * (size / PAGE_SIZE + 1);
	addr = mmap(NULL, page_total, PROT_READ |
		PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if ((int)addr == -1)
		return (NULL);
	if (!((void**)&g_global)[type])
		((void**)&g_global)[type] = addr;
	(*(t_node*)(addr + page_total - sizeof(t_node))).next = NULL;
	(*(t_block*)addr).size = size;
	(*(t_block*)addr).allocated = 1;
	(*(t_block*)addr).is_end = 0;
	(*(t_block*)(addr + OVERHEAD +
		size)).size = page_total - OVERHEAD * 2 - size - sizeof(t_node);
	(*(t_block*)(addr + OVERHEAD + size)).allocated = 0;
	(*(t_block*)(addr + OVERHEAD + size)).is_end = 1;
	return (addr);
}

void			*malloc(size_t size)
{
	void	*addr;
	int		type;

	if (!size)
		return (NULL);
	type = get_type(size);
	if (!(addr = find_spot(((void**)&g_global)[type], size, type)))
		addr = init_memory(size, type);
	if (addr == MAP_FAILED)
		return (NULL);
	return (addr + OVERHEAD);
}
