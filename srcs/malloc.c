#include <ft_malloc.h>

void *helper(void *ptr, size_t size, int type)
{
	if (GET_ALLOC(ptr) || GET_SIZE(ptr) < size + OVERHEAD*2)
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
		int end = IS_END(ptr);
		size_t save = GET_SIZE(ptr);
		(*(block_header*)ptr).size = size;
		(*(block_header*)ptr).allocated = 1;
		(*(block_header*)ptr).isEnd = 0;
		block_header next_head;
		next_head.size = save - OVERHEAD - size;
		next_head.allocated = 0;
		next_head.isEnd = end;
		*(block_header*)(ptr + OVERHEAD + size) = next_head;
	}
	return (ptr);
}

void *find_spot(void *ptr, size_t size, int type)
{
	if (!ptr)
		return (NULL);
	while ((GET_ALLOC(ptr) || GET_SIZE(ptr) < size + OVERHEAD*2))
	{
		if (IS_END(ptr))
		{
			if ((*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next)
				ptr = (*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next;
			else
				break;
		}
		else
			ptr += OVERHEAD + GET_SIZE(ptr);
	}
	
	return (helper(ptr, size, type));
}

void	*init_memory(size_t size, int type)
{
	void *addr;

	addr = mmap(0, (PAGE_SIZE*(size/PAGE_SIZE+1)), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if ((int)addr == -1)
	{
		perror("Error");
		exit(-1);
	}
	if (!((void**)&global)[type])
		((void**)&global)[type] = addr;
	t_node node;
	node.next = NULL;
	*(t_node*)(addr + (PAGE_SIZE*(size/PAGE_SIZE+1)) - sizeof(t_node)) = node;
	block_header head;
	head.size = size;
	head.allocated = 1;
	head.isEnd = 0;
	*(block_header*)addr = head;
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
	if (!size)
		return (NULL);
	int type = get_type(size);

	if (!(addr = find_spot(((void**)&global)[type], size, type)))
		addr = init_memory(size, type);
	if (addr == MAP_FAILED)
		return (NULL);
	return (addr + OVERHEAD);
}
