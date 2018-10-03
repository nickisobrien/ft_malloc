/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:18:16 by nobrien           #+#    #+#             */
/*   Updated: 2018/10/02 21:09:40 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

void	*realloc(void *ptr, size_t size)
{
	void			*ptr2;
	int				realloc_size;

	if (ptr && get_type(size) == get_type(GET_SIZE(HDRP(ptr))) &&
		GET_ALLOC(NEXT_BLKP(ptr)) == 0 && GET_SIZE(HDRP(ptr)) +
		GET_SIZE(NEXT_BLKP(ptr)) > size + OVERHEAD)
	{
		(*(block*)(ptr + size)).isEnd = IS_END(NEXT_BLKP(ptr));
		(*(block*)(ptr + size)).size = GET_SIZE(
			HDRP(ptr)) + GET_SIZE(NEXT_BLKP(ptr)) - size;
		(*(block*)(ptr + size)).allocated = 0;
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
