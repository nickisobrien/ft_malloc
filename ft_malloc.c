/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:18:16 by nobrien           #+#    #+#             */
/*   Updated: 2018/10/04 13:49:29 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_malloc.h"

// might be error memory is being left unremoved because realloc can't
// free what was pointed to before if it's passing something else with realloc
// and if im reallocating from something else, should i free that ?
int		main(void)
{
	// void *ptr = malloc(0);
	// void *ptr = NULL;
	// ptr = realloc(ptr, 100);
	// ptr = realloc(ptr, 0);
	// free(ptr);
	// (void)ptr;

// check for when realloc is smaller than malloc
	// char *pptr = (char *)malloc(5000);
	// char *pptr2 = (char *)malloc(5500);
	// char *pptr3 = (char *)malloc(6000);
	// // ptr = (char *)realloc((void *)ptr, sizeof(char) * 7000); // this messes printing memory up but 70000 doesn't
	// for (int i = 0; i < 5000; i++)
		// pptr[i] = 'b';
	// // this should move to smaller memory
	// // pptr = realloc(pptr,7000);
	// (void)pptr3;
	// (void)pptr;
	// (void)pptr2;
	// free(pptr3);

	// printf("%d\n", IS_END(NEXT_BLKP(pptr2)));
	// free(pptr2);
	// pptr2 = (char *)realloc((void*)pptr2, sizeof(char) * 3000);
	// ptr = (char *)realloc((void*)ptr, sizeof(char) * 2000);
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

	// void *ptr = malloc(40);
	// void *ptr4 = malloc(3000);
	// void *ptr2 = malloc(550);
	// void *ptr3 = malloc(3000);
	// void *ptr5 = malloc(110);
	// free(ptr);
	// free(ptr3);
	// // free(ptr5);
	// (void)ptr;(void)ptr2;(void)ptr3; (void)ptr4; (void)ptr5;

	// void *r = malloc(500);
	// void *ptr3 = malloc(2100);
	// void *ptr4 = malloc(2500);


	// ptr = realloc(ptr, 4000);
	// printf("TEST\n");
	// printf("TEST\n");
	// printf("%c\n", ((char*)tr)[1]);
	// show_alloc_mem();
	// printf("\n");
	// free(r);
	// free(tr);
	// free(ptr2);
	// free(ptr4);
	// free(ptr3);
	// free(ptr);
	// free(ptr5);

	// void *ptr = malloc(1024*1024*1024);
	printf("Pre memory\n");
	show_alloc_mem();
	printf("\n");
	// free(ptr);
	// void *ptr1 = malloc(10000);
	// ptr1 = realloc(ptr1,10000);
	// void *apr1 = malloc(00010);
	// apr1 = realloc(apr1,00010);
	// void *apt1 = malloc(00444);
	// apt1 = realloc(apt1,00444);
	// void *atr1 = malloc(01000);
	// atr1 = realloc(atr1,01000);
	// void *aar1 = malloc(10000);
	// aar1 = realloc(aar1,10000);
	// void *aat1 = malloc(00555);
	// aat1 = realloc(aat1,00555);
	// void *ptr2 = malloc(10000);
	// ptr2 = realloc(ptr2,10000);
	// void *apr2 = malloc(00010);
	// apr2 = realloc(apr2,00010);
	// void *apt2 = malloc(00444);
	// apt2 = realloc(apt2,00444);
	// void *atr2 = malloc(01000);
	// atr2 = realloc(atr2,01000);
	// void *aar2 = malloc(10000);
	// aar2 = realloc(aar2,10000);
	// void *aat2 = malloc(00555);
	// aat2 = realloc(aat2,00555);
	// void *ptr3 = malloc(10000);
	// ptr3 = realloc(ptr3,10000);
	// void *apr3 = malloc(00010);
	// apr3 = realloc(apr3,00010);
	// void *apt3 = malloc(00444);
	// apt3 = realloc(apt3,00444);
	// void *atr3 = malloc(01000);
	// atr3 = realloc(atr3,01000);
	// void *aar3 = malloc(10000);
	// aar3 = realloc(aar3,10000);
	// void *aat3 = malloc(00555);
	// aat3 = realloc(aat3,00555);
	// printf("Mid memory\n");
	// show_alloc_mem();
	// printf("\n");
	// void *ptr4 = malloc(10000);
	// ptr4 = realloc(ptr4,10000);
	// void *apr4 = malloc(00010);
	// apr4 = realloc(apr4,00010);
	// void *apt4 = malloc(00444);
	// apt4 = realloc(apt4,00444);
	// void *atr4 = malloc(01000);
	// atr4 = realloc(atr4,01000);
	// void *aar4 = malloc(10000);
	// aar4 = realloc(aar4,10000);
	// void *aat4 = malloc(00555);
	// aat4 = realloc(aat4,00555);
	// void *ptr5 = malloc(10000);
	// ptr5 = realloc(ptr5,10000);
	// void *apr5 = malloc(00010);
	// apr5 = realloc(apr5,00010);
	// void *apt5 = malloc(00444);
	// apt5 = realloc(apt5,00444);
	// void *atr5 = malloc(01000);
	// atr5 = realloc(atr5,01000);
	// void *aar5 = malloc(10000);
	// aar5 = realloc(aar5,10000);
	// void *aat5 = malloc(00555);
	// aat5 = realloc(aat5,00555);
	// void *ptr6 = malloc(10000);
	// ptr6 = realloc(ptr6,10000);
	// void *apr6 = malloc(00010);
	// apr6 = realloc(apr6,00010);
	// void *apt6 = malloc(00444);
	// apt6 = realloc(apt6,00444);
	// void *atr6 = malloc(01000);
	// atr6 = realloc(atr6,01000);
	// void *aar6 = malloc(10000);
	// aar6 = realloc(aar6,10000);
	// void *aat6 = malloc(00555);
	// aat6 = realloc(aat6,00555);
	// void *ptr7 = malloc(10000);
	// ptr7 = realloc(ptr7,10000);
	// void *apr7 = malloc(00010);
	// apr7 = realloc(apr7,00010);
	// void *apt7 = malloc(00444);
	// apt7 = realloc(apt7,00444);
	// void *atr7 = malloc(01000);
	// atr7 = realloc(atr7,01000);
	// void *aar7 = malloc(10000);
	// aar7 = realloc(aar7,10000);
	// void *aat7 = malloc(00555);
	// aat7 = realloc(aat7,00555);
	// printf("Pre alloc\n");
	// show_alloc_mem();
	// printf("\n");
	// ptr1 = realloc(ptr1,10000);
	// apr1 = realloc(apr1,0005100);
	// apt1 = realloc(apt1,0045440);
	// atr1 = realloc(atr1,0105000);
	// aar1 = realloc(aar1,1005000);
	// aat1 = realloc(aat1,0055550);
	// ptr2 = realloc(ptr2,1005000);
	// apr2 = realloc(apr2,0005100);
	// apt2 = realloc(apt2,0045440);
	// atr2 = realloc(atr2,0105000);
	// aar2 = realloc(aar2,1005000);
	// aat2 = realloc(aat2,0055550);
	// ptr3 = realloc(ptr3,1005000);
	// apr3 = realloc(apr3,0005100);
	// apt3 = realloc(apt3,0045440);
	// atr3 = realloc(atr3,0105000);
	// aar3 = realloc(aar3,1005000);
	// aat3 = realloc(aat3,0055550);
	// ptr4 = realloc(ptr4,1005000);
	// apr4 = realloc(apr4,0005100);
	// apt4 = realloc(apt4,0045440);
	// atr4 = realloc(atr4,0105000);
	// aar4 = realloc(aar4,1005000);
	// aat4 = realloc(aat4,0055550);
	// ptr5 = realloc(ptr5,1005000);
	// apr5 = realloc(apr5,0005100);
	// apt5 = realloc(apt5,0045440);
	// atr5 = realloc(atr5,0105000);
	// aar5 = realloc(aar5,1005000);
	// aat5 = realloc(aat5,0055550);
	// ptr6 = realloc(ptr6,1005000);
	// apr6 = realloc(apr6,0005100);
	// apt6 = realloc(apt6,0045440);
	// atr6 = realloc(atr6,0105000);
	// aar6 = realloc(aar6,1005000);
	// aat6 = realloc(aat6,0055550);
	// ptr7 = realloc(ptr7,1005000);
	// apr7 = realloc(apr7,0005100);
	// apt7 = realloc(apt7,0045440);
	// atr7 = realloc(atr7,0105000);
	// aar7 = realloc(aar7,1005000);
	// aat7 = realloc(aat7,0055550);
	// printf("Pre free\n");
	// show_alloc_mem();
	// printf("\n");
	// free(apr4);
	// free(apt4);
	// free(atr4);
	// free(aar4);
	// free(aat4);
	// free(ptr5);
	// free(apr5);
	// free(apt5);
	// free(apr2);
	// free(apt2);
	// free(atr2);
	// free(aat2);
	// free(aar2);
	// free(ptr3);
	// free(apr3);
	// free(ptr7);
	// free(apr7);
	// free(apt7);
	// free(atr7);
	// free(aar7);
	// free(aat7);
	// printf("Mid free\n");
	// show_alloc_mem();
	// printf("\n");
	// free(atr5);
	// free(aar5);
	// free(aat5);
	// free(ptr6);
	// free(apr6);
	// free(apt6);
	// free(atr6);
	// free(aat6);
	// free(aar6);
	// free(ptr1);
	// free(apr1);
	// free(apt1);
	// free(atr1);
	// free(aar1);
	// free(aat1);
	// free(ptr2);
	// free(apt3);
	// free(atr3);
	// free(aar3);
	// free(aat3);
	// free(ptr4);
	














































	// void *ptr = NULL;
	// ptr = realloc(ptr, 100);
	// free(ptr);

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
	// 	free(ptr);
	// }
	// for (int i = 0; i < 4; i++)
	// {
	// 	ptr = malloc(sizeof(char) * 200);
	// 	// printf("%zu %d\mn", GET_SIZE(NEXT_BLKP(ptr)), IS_END(NEXT_BLKP(ptr)));
	// 	(void)ptr;
	// 	free(ptr);
	// }
	// for (int i = 0; i < 2; i++)
	// {
	// 	ptr = malloc(sizeof(char) * 8000);
	// 	// printf("%zu %d\mn", GET_SIZE(NEXT_BLKP(ptr)), IS_END(NEXT_BLKP(ptr)));
	// 	(void)ptr;
	// 	free(ptr);
	// }
	// sleep(10);
	show_alloc_mem();
	printf("\n");
}
