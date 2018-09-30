#include <ft_malloc.h>
void	*init_memory(size_t size, int type);
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

void *find_spot(void *ptr, size_t size, int type)
{(void)type;
	if (!ptr)
		return (NULL);
	while ((GET_ALLOC(ptr) || GET_SIZE(ptr) < size + OVERHEAD))
	{
		printf("%d %zu\n", GET_ALLOC(ptr), GET_SIZE(ptr));
		if (IS_END(ptr))
		{
			if ((*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next)
			{
				printf("TEST\n");
				ptr = (*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next;
			}
			else
			{
				printf("BREAKING\n");
				break;
			}
		}
		else
			ptr += OVERHEAD + GET_SIZE(ptr);
	}
	if (GET_ALLOC(ptr) || GET_SIZE(ptr) < size + OVERHEAD) // ptr is at the last header and it is too small (i think)
	{
		if ((*(t_node*)(ptr + GET_SIZE(ptr))).next)
			find_spot((*(t_node*)(ptr + GET_SIZE(ptr))).next, size, type);
		else
		{
			void *newMemory = init_memory(size, type);
			(*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next = newMemory;
			return (newMemory);
		}
	}
	else
	{
		size_t save = GET_SIZE(ptr);
		(*(block_header*)ptr).size = size;
		(*(block_header*)ptr).allocated = 1;
		(*(block_header*)ptr).isEnd = 0;
		block_header next_head;
		next_head.size = save - OVERHEAD - size;
		next_head.allocated = 0;
		// NEED TO FIGURE THIS OUT vv
		next_head.isEnd = 1;//IS_END(ptr + save + OVERHEAD); // check if the header infront of it before was the last one
		*(block_header*)(ptr + OVERHEAD + size) = next_head;
	}
	return (ptr);
}

void	*init_memory(size_t size, int type)
{
	void *addr;

	addr = mmap(0, size + OVERHEAD + sizeof(t_node), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (!((void**)&global)[type])
		((void**)&global)[type] = addr;
	t_node node;
	node.next = NULL;
	*(t_node*)(addr + (PAGE_SIZE*(size/PAGE_SIZE+1)) - sizeof(t_node)) = node;
	// set current head
	block_header head;
	head.size = size;
	head.allocated = 1;
	head.isEnd = 0;
	*(block_header*)addr = head;
	// set next header at end of current header
	block_header next_head;
	next_head.size = PAGE_SIZE*(size/PAGE_SIZE+1) - OVERHEAD*2 - size - sizeof(t_node);
	next_head.allocated = 0;
	next_head.isEnd = 1;
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

	if (!(addr = find_spot(((void**)&global)[type], size, type)))
	{
		addr = init_memory(size, type);
	}
	if (addr == MAP_FAILED)
		return (NULL);

	return (addr + OVERHEAD);
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
	void *ptr = malloc(sizeof(char) * 3000);
	printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr)), GET_ALLOC(HDRP(ptr)), ((char*)ptr)[0], GET_SIZE(NEXT_BLKP(ptr)));
	void *ptr2 = malloc(sizeof(char) * 1001);
	printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr2)), GET_ALLOC(HDRP(ptr2)), ((char*)ptr2)[0], GET_SIZE(NEXT_BLKP(ptr2)));
	void *ptr3 = malloc(sizeof(char) * 1002);
	printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr3)), GET_ALLOC(HDRP(ptr3)), ((char*)ptr3)[0], GET_SIZE(NEXT_BLKP(ptr3)));
	void *ptr4 = malloc(sizeof(char) * 1003);
	printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr4)), GET_ALLOC(HDRP(ptr4)), ((char*)ptr4)[0], GET_SIZE(NEXT_BLKP(ptr4)));
	free(ptr3);
	ptr3 = malloc(sizeof(char) * 500); // need to figure out how to ensure that this next_blkp isn't end because it's getting slipped into front of 2nd alloc
	printf("%lu, %d, %c, %lu, %d\n", GET_SIZE(HDRP(ptr3)), GET_ALLOC(HDRP(ptr3)), ((char*)ptr3)[0], GET_SIZE(NEXT_BLKP(ptr3)), IS_END(NEXT_BLKP(ptr3)));

	// void *ptr5 = malloc(sizeof(char) * 3000);

	// for (int i = 0; i < 5; i++)
	// 	((char*)ptr)[i] = 'a';
	// for (int i = 0; i < 5; i++)
	// 	((char*)ptr2)[i] = 'b';
	// for (int i = 0; i < 5; i++)
	// 	((char*)ptr3)[i] = 'c';
	// for (int i = 0; i < 5; i++)
	// 	((char*)ptr4)[i] = 'd';
	// for (int i = 0; i < 5000; i++)
	// 	((char*)ptr5)[i] = 'e';

	// printf("%lu, %d, %c\n", GET_SIZE(HDRP(ptr)), GET_ALLOC(HDRP(ptr)), ((char*)ptr)[0]);
	// free(ptr);
	// printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr)), GET_ALLOC(HDRP(ptr)), ((char*)ptr)[0], GET_SIZE(NEXT_BLKP(ptr)));

	// printf("%lu, %d, %c\n", GET_SIZE(HDRP(ptr2)), GET_ALLOC(HDRP(ptr2)), ((char*)ptr2)[0]);
	// free(ptr2);
	// printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr2)), GET_ALLOC(HDRP(ptr2)), ((char*)ptr2)[0], GET_SIZE(NEXT_BLKP(ptr2)));

	// printf("%lu, %d, %c\n", GET_SIZE(HDRP(ptr3)), GET_ALLOC(HDRP(ptr3)), ((char*)ptr3)[0]);
	// free(ptr3);
	// printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr3)), GET_ALLOC(HDRP(ptr3)), ((char*)ptr3)[0], GET_SIZE(NEXT_BLKP(ptr3)));

	// printf("%lu, %d, %c\n", GET_SIZE(HDRP(ptr4)), GET_ALLOC(HDRP(ptr4)), ((char*)ptr4)[0]);
	// free(ptr4);
	// printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr4)), GET_ALLOC(HDRP(ptr4)), ((char*)ptr4)[0], GET_SIZE(NEXT_BLKP(ptr4)));

	// printf("%lu, %d, %c\n", GET_SIZE(HDRP(ptr5)), GET_ALLOC(HDRP(ptr5)), ((char*)ptr5)[0]);
	// free(ptr5);
	// printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr5)), GET_ALLOC(HDRP(ptr5)), ((char*)ptr5)[0], GET_SIZE(NEXT_BLKP(ptr5)));

	show_alloc_mem();
}