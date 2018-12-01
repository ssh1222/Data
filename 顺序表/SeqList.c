#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SeqList.h"

//初始化（函数设计）
void SeqListInit(SeqList* pSeq)
{
	//1.初始化 size
	//2.可能需要去把容器空间清空下
	assert(pSeq != NULL);
	//2.if(SeqList == NULL)
	//{}
	pSeq->capacity = INIT_CAPACITY;
	pSeq->array = (DataType*)malloc(sizeof(DataType)* pSeq->capacity);
	pSeq->size = 0;
}

//销毁
void SeqListDestroy(SeqList* pSeq)
{
	free(pSeq->array);
	pSeq->capacity = 0;
	pSeq->size = 0;
	pSeq->array = NULL;
}

//扩容
static void ExpandIfRequired(SeqList* pSeq)
{
	//扩容条件
	if (pSeq->size < pSeq->capacity)
	{
		//没满
		return;
	}
	pSeq->capacity *= 2;
	//1.申请新空间
	DataType* newArray = (DataType*)malloc(sizeof(DataType)*pSeq->capacity);
	//2.数据搬移
	for (int i = 0; i < pSeq->size; ++i)
	{
		newArray[i] = pSeq->array[i];
	}
	//3.释放老空间,关联新空间
	free(pSeq->array);
	pSeq->array = newArray;
}

//增
//尾插（尽量和C++的 STL统一）
void SeqListPushBack(SeqList* pSeq, DataType data)
{
	assert(pSeq != NULL);
	//特殊情况
	ExpandIfRequired(pSeq);
	//通常情况
	pSeq->array[pSeq->size] = data;
	++pSeq->size;
}

//头插
void SeqListPushFront(SeqList* pSeq, DataType data)
{
	assert(pSeq != NULL);
	//特殊情况
	ExpandIfRequired(pSeq);
	//通常情况
	//i代表位置
	for (int i = pSeq->size; i > 0; --i)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	/*
	//i代表数据
	for (int i = pSeq->size - 1; i >= 0; --i)
	{
	pSeq->array[i + 1] = pSeq->array[i];
	}
	*/
	//插入
	pSeq->array[0] = data;
	++pSeq->size;
}

//中间插入
void SeqListInsert(SeqList* pSeq, int pos, DataType data)
{
	assert(pSeq != NULL);
	assert(pos >= 0 && pos <= pSeq->size);
	//特殊情况
	ExpandIfRequired(pSeq);
	//通常情况
	for (int i = pSeq->size; i > pos; --i)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	//插入
	pSeq->array[pos] = data;
	++pSeq->size;
}

//删
//尾删
void SeqListPopBack(SeqList* pSeq)
{
	assert(pSeq != NULL);
	//特殊情况
	if (pSeq->size <= 0)
	{
		printf("没有数据");
		return;
	}
	//通常情况
	--pSeq->size;
}

//头删
void SeqListTopFront(SeqList* pSeq)
{
	assert(pSeq != NULL);
	//特殊情况
	if (pSeq->size <= 0)
	{
		printf("没有数据\n");
		return;
	}
	//通常情况
	for (int i = 1; i < pSeq->size; ++i)
	{
		pSeq->array[i - 1] = pSeq->array[i];
	}
	--pSeq->size;
}

//中间删
void SeqListErase(SeqList* pSeq, int pos)
{
	assert(pSeq != NULL);
	assert(pos >= 0 && pos < pSeq->size);
	//特殊情况
	ExpandIfRequired(pSeq);
	//数据搬移
	for (int i = pos; i < pSeq->size - 1; ++i)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	--pSeq->size;
}

//查找,找到了返回下标，没找到返回-1；
int SeqListFind(SeqList* pSeq, DataType data)
{
	assert(pSeq != NULL);
	for (int i = 0; i < pSeq->size; ++i)
	{
		if (pSeq->array[i] == data)
		{
			return i;
		}
	}
	return -1;
}

//删除所有遇到的data
void SeqListRemoveAll(SeqList* pSeq, DataType data)
{
	assert(pSeq!=NULL);
#if 0
	//简单方法时间复杂度位O(n^2)
	int pos;
	while ((pos = SeqListFind(pSeq, data)) != -1)
	{
		SeqListErase(pSeq, pos);
	}
	//开辟空间存储空间复杂度位O(n)
	DataType* tempArray = (DataType*)malloc(
		sizeof(DataType)*pSeq->size);
	assert(tempArray != NULL);
	int j = 0;
	//将不是data的数存放在新开辟的空间里
	for (int i = 0; i < pSeq->size; ++i)
	{
		if (pSeq->array[i] != data)
		{
			tempArray[j++] = pSeq->array[i];
		}
	}
	for (int i = 0; i < j; ++i)
	{
		pSeq->array[i] = tempArray[i];
	}
	pSeq->size = j;
#endif
	//时间复杂度和空间复杂度都为O(n)
	int j = 0;
	for (int i = 0; i < pSeq->size; ++i)
	{
		if (pSeq->array[i] != data)
		{
			pSeq->array[j++] = pSeq->array[i];
		}
	}
	pSeq->size = j;
}

//修改
void SeqListRevise(SeqList* pSeq, int pos, DataType data)
{
	assert(pSeq != NULL);
	assert(pos >= 0 && pos <= pSeq->size - 1);
	pSeq->array[pos] = data;
}

//传指针减少空间，不改变值
void SeqListPrint(const SeqList* pSeq)
{
	assert(pSeq != NULL);

	for (int i = 0; i < pSeq->size; ++i)
	{
		printf("%d", pSeq->array[i]);
	}
	printf("\n");
}

static Swap(DataType* x,DataType* y)
{
	DataType tmp = *x;
	*x = *y;
	*y = tmp;
}

//冒泡排序
void SeqListBubbleSort(SeqList* pSeq)
{
	assert(pSeq != NULL);
	for (int i = 0; i < pSeq->size; ++i)
	{
		int count = 0;
		for (int j = 0; j < pSeq->size - 1 - i; ++j)
		{
			if (pSeq->array[j] > pSeq->array[j + 1])
			{
				Swap(pSeq->array + j, pSeq->array + j + 1);
				count = 1;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
}

//选择排序
void SeqListSelectSort(SeqList* pSeq)
{
	assert(pSeq != NULL);
	int min = 0;
	int max = pSeq->size-1;
	while (min < max)
	{
		int minSpace = min;
		int maxSpace = max;
		for (int i = min; i < max; ++i)
		{
			if (pSeq->array[i] < pSeq->array[min])
			{
				min = i;
			}
			if (pSeq->array[i]>pSeq->array[max])
			{
				max = i;
			}
		}
		Swap(pSeq->array + min, pSeq->array + minSpace);
		Swap(pSeq->array + max, pSeq->array + maxSpace);
		++min;
		--max;
	}
}

//二分查找
int SeqListTwoPoint(SeqList* pSeq,DataType data)
{
	assert(pSeq!= NULL);
	int left = 0;
	int right = pSeq->size;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (pSeq->array[mid] == data)
		{
			return mid;
		}
		else if (pSeq->array[mid] < data)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return -1;
}