#include <ft_malloc.h>

void free(void *addr)
{(void)addr;

	munmap(addr, 5); // void*, size
}

void *realloc(void *ptr, size_t size)
{(void)ptr;(void)size;
	return (NULL);
}

// void	add_to_list(void *ptr, int size)
// {
// 	(void)ptr;(void)size;
// }

void *malloc(size_t size)
{
	void *addr = mmap(0, size,
		PROT_READ | PROT_WRITE | PROT_EXEC,
		MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (addr == MAP_FAILED)
		return (NULL);
	// add_to_list(addr, size);

	return (addr);
}

int		main(void)
{
	char *str = (char *)malloc(sizeof(char) * 5);
	for (int i = 0; i < 4; i++)
	{
		str[i] = 'a' + i;
	}
	str[4] = '\0';
	printf("Test %s\n", str);
	free(str);
	printf("Test %s\n", str);
}
