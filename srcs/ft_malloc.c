#include <ft_malloc.h>

void free(void *addr)
{
	// if there is nothing in the block, munmap the entire block, else just memset it to 0 and set GET_ALLOC to 0?
	// if memory infront of it isn't allocated, can just combine the two to make a bigger segment
	// set this as unallocated
	if (!addr)
		return ;
	GET_ALLOC(HDRP(addr)) = 0;
	if (GET_ALLOC(NEXT_BLKP(addr)) == 0)
	{
		// size of next chunk
		IS_END(HDRP(addr)) = IS_END(NEXT_BLKP(addr));
		GET_SIZE(HDRP(addr)) += GET_SIZE(NEXT_BLKP(addr)) + OVERHEAD;
	}
}

void *realloc(void *ptr, size_t size)
{(void)ptr;(void)size;
	return (NULL);
}

void	show_alloc_mem()
{
	// void *trav;
	// if (global.tiny)
	// {
	// 	trav = global.tiny;
	// 	printf("TINY: %p\n", global.tiny);
	// 	while (ptr)
	// 	{
	// 		printf("%p - %p", ptr + OVERHEAD, ptr + OVERHEAD + GET_SIZE(ptr));
	// 		ptr = ptr + OVERHEAD + GET_SIZE(ptr);
	// 	}
	// }

	// if (global.small)
	// 	printf("SMALL: %p\n", global.small);

	// if (global.large)
	// 	printf("LARGE: %p\n", global.large);
}

int		main(void)
{
	// void *ptr = malloc(sizeof(char) * 3000);
	// printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr)), GET_ALLOC(HDRP(ptr)), ((char*)ptr)[0], GET_SIZE(NEXT_BLKP(ptr)));
	// void *ptr2 = malloc(sizeof(char) * 1000);
	// printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr2)), GET_ALLOC(HDRP(ptr2)), ((char*)ptr2)[0], GET_SIZE(NEXT_BLKP(ptr2)));
	// void *ptr3 = malloc(sizeof(char) * 1000);
	// printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr3)), GET_ALLOC(HDRP(ptr3)), ((char*)ptr3)[0], GET_SIZE(NEXT_BLKP(ptr3)));
	// void *ptr4 = malloc(sizeof(char) * 1000);
	// printf("%lu, %d, %c, %lu, %d\n", GET_SIZE(HDRP(ptr4)), GET_ALLOC(HDRP(ptr4)), ((char*)ptr4)[0], GET_SIZE(NEXT_BLKP(ptr4)), IS_END(NEXT_BLKP(ptr4)));
	// free(ptr4);
	// free(ptr3);
	// ptr3 = malloc(sizeof(char) * 500); // need to figure out how to ensure that this next_blkp isn't end because it's getting slipped into front of 2nd alloc
	// printf("%lu, %d, %c, %lu, %d\n", GET_SIZE(HDRP(ptr3)), GET_ALLOC(HDRP(ptr3)), ((char*)ptr3)[0], GET_SIZE(NEXT_BLKP(ptr3)), IS_END(NEXT_BLKP(ptr3)));
	// void *ptr5 = malloc(sizeof(char) * 1000); // need to figure out how to ensure that this next_blkp isn't end because it's getting slipped into front of 2nd alloc
	// printf("%lu, %d, %c, %lu, %d\n", GET_SIZE(HDRP(ptr5)), GET_ALLOC(HDRP(ptr5)), ((char*)ptr5)[0], GET_SIZE(NEXT_BLKP(ptr5)), IS_END(NEXT_BLKP(ptr5)));
	// show_alloc_mem();

	void *ptr = malloc(sizeof(char) * 10000);
	printf("%zu %d\n", GET_SIZE(NEXT_BLKP(ptr)), IS_END(NEXT_BLKP(ptr)));
	void *ptr2 = malloc(sizeof(char) * 10000);
	printf("%zu %d %d\n", GET_SIZE(NEXT_BLKP(ptr)), IS_END(NEXT_BLKP(ptr)), IS_END(NEXT_BLKP(ptr2)));
	free(ptr2);
	printf("%zu %d\n", GET_SIZE(NEXT_BLKP(ptr)), IS_END(NEXT_BLKP(ptr)));
}