#include <ft_malloc.h>

void *realloc(void *ptr, size_t size)
{
	if (GET_ALLOC(NEXT_BLKP(ptr)) == 0 && GET_SIZE(HDRP(ptr)) + GET_SIZE(NEXT_BLKP(ptr)) > size + OVERHEAD)
	{
		block_header newHeader;
		newHeader.size = GET_SIZE(HDRP(ptr)) + GET_SIZE(NEXT_BLKP(ptr)) - size - OVERHEAD;
		newHeader.allocated = 0;
		newHeader.isEnd = 0;
		*(block_header*)(ptr + size) = newHeader;
		GET_SIZE(HDRP(ptr)) = size;
		return (ptr);
	}
	else
	{
		void *ptr2 = malloc(size);
		if (ptr2)
			ft_memcpy(ptr2, ptr, GET_SIZE(HDRP(ptr)));
		free(ptr);
		return (ptr2);
	}
	return (NULL);
}