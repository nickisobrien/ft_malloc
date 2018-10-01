#include <ft_malloc.h>

int		main(void)
{
	// void *ptr = malloc(sizeof(char) * 500);
	// printf("%lu, %d, %lu\n", GET_SIZE(HDRP(ptr)), GET_ALLOC(HDRP(ptr)), GET_SIZE(NEXT_BLKP(ptr)));
	// void *ptr2 = malloc(sizeof(char) * 600);
	// printf("%lu, %d, %lu\n", GET_SIZE(HDRP(ptr2)), GET_ALLOC(HDRP(ptr2)), GET_SIZE(NEXT_BLKP(ptr2)));
	// ptr = realloc(ptr, sizeof(char) * 700);
	// printf("%lu, %d, %lu\n", GET_SIZE(HDRP(ptr)), GET_ALLOC(HDRP(ptr)), GET_SIZE(NEXT_BLKP(ptr)));

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

	void *ptr;
	for (int i = 0; i < 6; i++)
	{
		ptr = malloc(sizeof(char) * 20);
		// printf("%zu %d\mn", GET_SIZE(NEXT_BLKP(ptr)), IS_END(NEXT_BLKP(ptr)));
		(void)ptr;
	}
	for (int i = 0; i < 4; i++)
	{
		ptr = malloc(sizeof(char) * 200);
		// printf("%zu %d\mn", GET_SIZE(NEXT_BLKP(ptr)), IS_END(NEXT_BLKP(ptr)));
		(void)ptr;
	}
	for (int i = 0; i < 2; i++)
	{
		ptr = malloc(sizeof(char) * 8000);
		// printf("%zu %d\mn", GET_SIZE(NEXT_BLKP(ptr)), IS_END(NEXT_BLKP(ptr)));
		(void)ptr;
	}
	show_alloc_mem();
}