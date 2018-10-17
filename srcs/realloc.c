/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:18:16 by nobrien           #+#    #+#             */
/*   Updated: 2018/10/04 14:08:50 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

int				get_type(size_t num)
{
	if (num <= (size_t)TINY)
		return (0);
	if (num <= (size_t)SMALL)
		return (1);
	return (2);
}

void		*realloc(void *ptr, size_t size)
{
	void	*ptr2;
	size_t	smaller;

	if (ptr && get_type(size) == get_type(GET_SIZE(HDRP(ptr))) &&
		GET_ALLOC(NEXT_BLKP(ptr)) == 0 && GET_SIZE(HDRP(ptr)) +
		GET_SIZE(NEXT_BLKP(ptr)) > size + OVERHEAD)
	{
		IS_END(ptr + size) = IS_END(NEXT_BLKP(ptr));
		GET_SIZE(ptr + size) = GET_SIZE(HDRP(ptr)) +
		GET_SIZE(NEXT_BLKP(ptr)) - size;
		GET_ALLOC(ptr + size) = 0;
		GET_SIZE(HDRP(ptr)) = size;
		return (ptr);
	}
	else
	{
		if (ptr)
			smaller = size < GET_SIZE(HDRP(ptr)) ? size : GET_SIZE(HDRP(ptr));
		ptr2 = malloc(size);
		if (ptr && ptr2)
			ft_memcpy(ptr2, ptr, smaller);
		free(ptr);
		return (ptr2);
	}
}
