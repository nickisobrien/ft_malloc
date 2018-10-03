#include <ft_malloc.h>

void sweep(void *ptr)
{
	while (ptr)
	{
		while (!IS_END(ptr))
			ptr += OVERHEAD + GET_SIZE(ptr);
		t_node *node = (t_node*)(ptr + OVERHEAD + GET_SIZE(ptr));
		if (!node->next)
			break;
		if (GET_ALLOC(node->next) == 0 && IS_END(node->next) == 1)
		{
			void *save = node->next;
			void *next = ((t_node*)(save + GET_SIZE(save) + OVERHEAD))->next;
			((t_node*)(ptr + OVERHEAD + GET_SIZE(ptr)))->next = next;
			if (munmap(save, OVERHEAD + GET_SIZE(save) + sizeof(t_node)) == -1)
			{
				perror("Error");
				exit(-1);
			}
		}
		else
			ptr = node->next;
	}
}

void free(void *addr)
{
	if (!addr)
		return ;
	GET_ALLOC(HDRP(addr)) = 0;
	if (GET_ALLOC(NEXT_BLKP(addr)) == 0)
	{
		IS_END(HDRP(addr)) = IS_END(NEXT_BLKP(addr));
		GET_SIZE(HDRP(addr)) += GET_SIZE(NEXT_BLKP(addr)) + OVERHEAD;
	}
	if (IS_END(HDRP(addr)))
	{
		sweep(global.tiny);
		sweep(global.small);
		sweep(global.large);
	}
}
