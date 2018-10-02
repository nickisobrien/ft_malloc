#include <ft_malloc.h>

int		main(void)
{// check for when realloc is smaller than malloc
	char *ptr = (char *)malloc(sizeof(char) * 5000);
	for (int i = 0; i < 5000; i++)
		ptr[i] = 'a';
	char *ptr2 = (char *)malloc(sizeof(char) * 6000);
	ptr = (char *)realloc((void *)ptr, sizeof(char) * 7000); // this messes printing memory up but 70000 doesn't
	for (int i = 5000; i < 7000; i++)
		ptr[i] = 'b';
	(void)ptr2;
	// printf("%zu %d\n", GET_SIZE(NEXT_BLKP(OVERHEAD+NEXT_BLKP(ptr))), IS_END(NEXT_BLKP(ptr)));
	// printf("%c %c\n", ptr[3400], ptr[6500]);

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

	// void *ptr = malloc(40000);
	// void *ptr2 = malloc(25000);
	// void *ptr3 = malloc(30000);
	// free(ptr);
	// (void)ptr;(void)ptr2;(void)ptr3;

	// void *ptr;
	// for (int i = 0; i < 6; i++)
	// {
	// 	ptr = malloc(sizeof(char) * 20);
	// 	// printf("%zu %d\mn", GET_SIZE(NEXT_BLKP(ptr)), IS_END(NEXT_BLKP(ptr)));
	// 	(void)ptr;
	// }
	// for (int i = 0; i < 4; i++)
	// {
	// 	ptr = malloc(sizeof(char) * 200);
	// 	// printf("%zu %d\mn", GET_SIZE(NEXT_BLKP(ptr)), IS_END(NEXT_BLKP(ptr)));
	// 	(void)ptr;
	// }
	// for (int i = 0; i < 2; i++)
	// {
	// 	ptr = malloc(sizeof(char) * 8000);
	// 	// printf("%zu %d\mn", GET_SIZE(NEXT_BLKP(ptr)), IS_END(NEXT_BLKP(ptr)));
	// 	(void)ptr;
	// }
	show_alloc_mem();
}
