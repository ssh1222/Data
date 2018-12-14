#pragma once
#include <stdlib.h>
#include <assert.h>

//���µ���
//array[size]��ʾ���鼰��С
//root��ʾҪ�����Ľ����±�
//ǰ����[root]���ڽ�����������Ѿ�����ѵ�����
void AdjustDown(int array[], int size, int root)
{
	//int left = 2 * root + 1;
	//int right = 2 * root + 2;
	int min = 2 * root + 1;
	if (min >= size)
	{
		//Խ��
		return;
	}
	//ȷ���Ǹ�����С�ĺ���
	if (min+1 < size && array[min+1] < array[min])
	{
		min = min+1;
	}
	if (array[root] <= array[min])
	{
		return;
	}
	//����ֵ
	int tmp = array[root];
	array[root] = array[min];
	array[min] = tmp;
	AdjustDown(array, size, min);
}

//����
void CreateHeap(int array[], int size)
{
	//�����һ����Ҷ�ӽ�㿪ʼ��������0����
	//���һ����Ҷ�ӽ��������һ������˫�׽��
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(array, size, i);
	}
}

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* array;
	int size;
	int capacity;
}	Heap;

//��ʼ��
void HeapCreateHeap(Heap* heap, int array[], int size)
{
	heap->capacity = size * 2;
	heap->size = size;
	heap->array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	for (int i = 0; i < size; ++i)
	{
		heap->array[i] = array[i];
	}

	//����
	CreateHeap(heap->array, heap->size);
}

//С��
void AdjustUp(int array[], int size, int child)
{
	while (child != 0)
	{
		int parent = (child - 1) / 2;
		if (array[child] >= array[parent])
		{
			return;
		}
		int tmp = array[parent];
		array[parent] = array[child];
		array[child] = tmp;
		child = parent;
	}
}

//����
void HeapInsert(Heap* heap, int val)
{
	heap->array[heap->size] = val;
	++heap->size;
	AdjustUp(heap->array, heap->size, heap->size - 1);
}

//ɾ��(ֻ��ɾ���Ѷ�Ԫ��)
void HeapPop(Heap* heap)
{
	assert(heap->size > 0);
	heap->array[0] = heap->array[heap->size - 1];
	--heap->size;
	AdjustDown(heap->array, heap->size, 0);
}

//���ضѶ�Ԫ�أ�������ֵ
HPDataType HeapTop(Heap* heap)
{
	assert(heap->size > 0);
	return heap->array[0];
}