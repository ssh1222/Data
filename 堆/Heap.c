#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>

void Test()
{
	int array[] = { 3, 5, 8, 9, 1, 12, 20, 4, 2, 7 };
	int size = sizeof(array) / sizeof(array[0]);
	Heap heap;
	HeapCreateHeap(&heap, array, size);
	HeapInsert(&heap, 0);
	printf("%d\n", HeapTop(&heap));
	HeapPop(&heap);
	printf("%d\n", HeapTop(&heap));
}

int main()
{
	Test();
	system("pause");
	return 0;
}