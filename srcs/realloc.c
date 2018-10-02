#include <ft_malloc.h>

void *realloc(void *ptr, size_t size)
{
	// need to make it so malloc is called if it's a different type than it was before
	// if (GET_SIZE(HDRP(ptr)) )
	if (get_type(size) == get_type(GET_SIZE(HDRP(ptr))) && 
		GET_ALLOC(NEXT_BLKP(ptr)) == 0 && GET_SIZE(HDRP(ptr)) + GET_SIZE(NEXT_BLKP(ptr)) > size + OVERHEAD)
	{
		block_header newHeader;
		newHeader.isEnd = IS_END(NEXT_BLKP(ptr));
		newHeader.size = GET_SIZE(HDRP(ptr)) + GET_SIZE(NEXT_BLKP(ptr)) - size;
		newHeader.allocated = 0;
		*(block_header*)(ptr + size) = newHeader;
		GET_SIZE(HDRP(ptr)) = size;
		return (ptr);
	}
	else
	{
		int reallocSize = GET_SIZE(HDRP(ptr)) < size ? GET_SIZE(HDRP(ptr)) : size;
		void *ptr2 = malloc(size);
		if (ptr2) // need to do check here to check if ptr is bigger than ptr2
			ft_memcpy(ptr2, ptr, reallocSize);
		printf("Freeing...\n");
		free(ptr);
		printf("Free'd\n");
		return (ptr2);
	}
	return (NULL);
}