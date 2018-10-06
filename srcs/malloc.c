/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:18:16 by nobrien           #+#    #+#             */
/*   Updated: 2018/10/04 13:50:09 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

t_global		g_global;

void			init_global()
{
	g_global.tiny = init_memory(TINY * 100);
	GET_ALLOC(g_global.tiny) = 0;
	g_global.small = init_memory(SMALL * 100);
	GET_ALLOC(g_global.small) = 0;
	g_global.large = init_memory(SMALL * 100);
	GET_ALLOC(g_global.large) = 0;
}

void			*helper(void *ptr, size_t size, int type)
{
	void	*new_memory;
	size_t	save;
	int		end;

	if (GET_ALLOC(ptr) || GET_SIZE(ptr) < size + OVERHEAD)
	{
		if ((*(t_node*)(ptr + GET_SIZE(ptr))).next)
			find_spot((*(t_node*)(ptr + GET_SIZE(ptr))).next, size, type);
		else
		{
			new_memory = init_memory(size);
			(*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next = new_memory;
			return (new_memory);
		}
	}
	else
	{
		save = GET_SIZE(ptr);
		end = IS_END(ptr);
		GET_SIZE(ptr) = size;
		GET_ALLOC(ptr) = 1;
		IS_END(ptr) = 0;
		GET_ALLOC(NEXT_BLKP(ptr + OVERHEAD)) = 0;
		GET_SIZE(NEXT_BLKP(ptr + OVERHEAD)) = save - OVERHEAD - size;
		IS_END(NEXT_BLKP(ptr + OVERHEAD)) = end;
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
			ptr = NEXT_BLKP(OVERHEAD + ptr);
	}
	return (helper(ptr, size, type));
}

void			*init_memory(size_t size)
{
	void	*addr;
	size_t	page_total;

	page_total = PAGE_SIZE * ((size + OVERHEAD +
		sizeof(t_node)) / PAGE_SIZE + 1);
	addr = mmap(NULL, page_total, PROT_READ |
		PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (addr == MAP_FAILED)
		return (NULL);
	(*(t_node*)(addr + page_total - sizeof(t_node))).next = NULL;
	GET_SIZE(addr) = size;
	GET_ALLOC(addr) = 1;
	IS_END(addr) = 0;
	GET_SIZE(NEXT_BLKP(addr + OVERHEAD)) = page_total -
	OVERHEAD * 2 - size - sizeof(t_node);
	GET_ALLOC(NEXT_BLKP(addr + OVERHEAD)) = 0;
	IS_END(NEXT_BLKP(addr + OVERHEAD)) = 1;
	return (addr);
}

void			*malloc(size_t size)
{
	void	*addr;
	int		type;

	if (!size)
		return (NULL);
	type = get_type(size);
	if (!((void**)&g_global)[type])
		init_global();
	if (!(addr = find_spot(((void**)&g_global)[type], size, type)))
		addr = init_memory(size);
	if (addr == MAP_FAILED)
		return (NULL);
	return (addr + OVERHEAD);
}
