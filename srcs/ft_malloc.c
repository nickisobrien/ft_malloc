#include <ft_malloc.h>

t_global global;

void free(void *addr)
{(void)addr;
	// if there is nothing in the block, munmap the entire block, else just memset it to 0 and set GET_ALLOC to 0?
	// if memory infront of it isn't allocated, can just combine the two to make a bigger segment
	munmap(addr, 5); // void*, size
	void *ptrToHead = HDRP(addr);
	GET_ALLOC(ptrToHead) = 0; 
}

void *realloc(void *ptr, size_t size)
{(void)ptr;(void)size;
	return (NULL);
}

void *find_spot(size_t size, int type)
{
	if (!((void**)&global)[type])
		return (NULL);
	void *ptr = ((void**)&global)[type];
	while (GET_ALLOC(ptr) || GET_SIZE(ptr) < size + sizeof(void*)) // need to save room for a void * at the end
		ptr += OVERHEAD + GET_SIZE(ptr);
	if (GET_ALLOC(ptr) || GET_SIZE(ptr) >= size + sizeof(void*))
	{
		// need to do another mmap but need to link it to the end of the most recent mmap
	}
	return (ptr);
}

void	*init_memory(int size, int type)
{
	void *addr;

	((void**)&global)[type] = mmap(0, size + OVERHEAD, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	addr = ((void**)&global)[type];
	// set current head
	block_header head;
	head.size = size;
	head.allocated = 1;
	*(block_header*)addr = head;
	// set next header at end of current header
	block_header next_head;
	next_head.size = PAGE_SIZE*(size/PAGE_SIZE+1) - OVERHEAD*2 - size;
	next_head.allocated = 0;
	*(block_header*)(addr + OVERHEAD + size) = next_head;
	return (addr);
}

void *malloc(size_t size)
{
	void *addr;
	int type;
	if (size <= TINY)
		type = 0;
	else if (size <= SMALL)
		type = 1;
	else
		type = 2;

	if (!(addr = find_spot(size + OVERHEAD, type)))
	{
		addr = init_memory(size, type);
	}
	else // is spot in memory already allocated
	{
		int save = GET_SIZE(addr);
		(*(block_header*)addr).size = size;
		(*(block_header*)addr).allocated = 1;
		// set next header at end of current header, need to change to check if there is room
		block_header next_head;
		next_head.size = save - OVERHEAD - size;
		next_head.allocated = 0;
		*(block_header*)(addr + OVERHEAD + size) = next_head;
	}
	if (addr == MAP_FAILED)
		return (NULL);

	return (addr + OVERHEAD);
}

int		main(void)
{
	void *ptr = malloc(sizeof(char) * 70);
	void *ptr2 = malloc(sizeof(char) * 300);
	void *ptr3 = malloc(sizeof(char) * 500);
	void *ptr4 = malloc(sizeof(char) * 30);
	void *ptr5 = malloc(sizeof(char) * 5000);

	for (int i = 0; i < 5; i++)
		((char*)ptr)[i] = 'a';
	for (int i = 0; i < 5; i++)
		((char*)ptr2)[i] = 'b';
	for (int i = 0; i < 5; i++)
		((char*)ptr3)[i] = 'c';
	for (int i = 0; i < 5; i++)
		((char*)ptr4)[i] = 'd';
	for (int i = 0; i < 5000; i++)
		((char*)ptr5)[i] = 'e';


	printf("%lu, %d, %c\n", GET_SIZE(HDRP(ptr)), GET_ALLOC(HDRP(ptr)), ((char*)ptr)[0]);
	free(ptr);
	printf("%lu, %d, %c\n", GET_SIZE(HDRP(ptr)), GET_ALLOC(HDRP(ptr)), ((char*)ptr)[0]);

	printf("%lu, %d, %c\n", GET_SIZE(HDRP(ptr2)), GET_ALLOC(HDRP(ptr2)), ((char*)ptr2)[0]);
	free(ptr2);
	printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr2)), GET_ALLOC(HDRP(ptr2)), ((char*)ptr2)[0], GET_SIZE(NEXT_BLKP(ptr2)));

	printf("%lu, %d, %c\n", GET_SIZE(HDRP(ptr3)), GET_ALLOC(HDRP(ptr3)), ((char*)ptr3)[0]);
	free(ptr3);
	printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr3)), GET_ALLOC(HDRP(ptr3)), ((char*)ptr3)[0], GET_SIZE(NEXT_BLKP(ptr3)));

	printf("%lu, %d, %c\n", GET_SIZE(HDRP(ptr4)), GET_ALLOC(HDRP(ptr4)), ((char*)ptr4)[0]);
	free(ptr4);
	printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr4)), GET_ALLOC(HDRP(ptr4)), ((char*)ptr4)[0], GET_SIZE(NEXT_BLKP(ptr4)));

	printf("%lu, %d, %c\n", GET_SIZE(HDRP(ptr5)), GET_ALLOC(HDRP(ptr5)), ((char*)ptr5)[0]);
	free(ptr5);
	printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr5)), GET_ALLOC(HDRP(ptr5)), ((char*)ptr5)[0], GET_SIZE(NEXT_BLKP(ptr5)));
}