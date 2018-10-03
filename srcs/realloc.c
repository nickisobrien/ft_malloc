/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:18:16 by nobrien           #+#    #+#             */
/*   Updated: 2018/10/03 13:00:31 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

t_global	g_global;

void		*realloc(void *ptr, size_t size)
{
	void	*ptr2;
	int		realloc_size;

	if (ptr && get_type(size) == get_type(GET_SIZE(HDRP(ptr))) &&
		GET_ALLOC(NEXT_BLKP(ptr)) == 0 && GET_SIZE(HDRP(ptr)) +
		GET_SIZE(NEXT_BLKP(ptr)) > size + OVERHEAD)
	{
		(*(t_block*)(ptr + size)).is_end = IS_END(NEXT_BLKP(ptr));
		(*(t_block*)(ptr + size)).size = GET_SIZE(
			HDRP(ptr)) + GET_SIZE(NEXT_BLKP(ptr)) - size;
		(*(t_block*)(ptr + size)).allocated = 0;
		GET_SIZE(HDRP(ptr)) = size;
		return (ptr);
	}
	else
	{
		realloc_size = ptr && GET_SIZE(HDRP(ptr)) < size
		? GET_SIZE(HDRP(ptr)) : size;
		ptr2 = malloc(size);
		if (ptr && ptr2)
			ft_memcpy(ptr2, ptr, realloc_size);
		free(ptr);
		return (ptr2);
	}
}
