#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SeqList.h"

//��ʼ����������ƣ�
void SeqListInit(SeqList* pSeq)
{
	//1.��ʼ�� size
	//2.������Ҫȥ�������ռ������
	assert(pSeq != NULL);
	//2.if(SeqList == NULL)
	//{}
	pSeq->capacity = INIT_CAPACITY;
	pSeq->array = (DataType*)malloc(sizeof(DataType)* pSeq->capacity);
	pSeq->size = 0;
}

//����
void SeqListDestroy(SeqList* pSeq)
{
	free(pSeq->array);
	pSeq->capacity = 0;
	pSeq->size = 0;
	pSeq->array = NULL;
}

//����
static void ExpandIfRequired(SeqList* pSeq)
{
	//��������
	if (pSeq->size < pSeq->capacity)
	{
		//û��
		return;
	}
	pSeq->capacity *= 2;
	//1.�����¿ռ�
	DataType* newArray = (DataType*)malloc(sizeof(DataType)*pSeq->capacity);
	//2.���ݰ���
	for (int i = 0; i < pSeq->size; ++i)
	{
		newArray[i] = pSeq->array[i];
	}
	//3.�ͷ��Ͽռ�,�����¿ռ�
	free(pSeq->array);
	pSeq->array = newArray;
}

//��
//β�壨������C++�� STLͳһ��
void SeqListPushBack(SeqList* pSeq, DataType data)
{
	assert(pSeq != NULL);
	//�������
	ExpandIfRequired(pSeq);
	//ͨ�����
	pSeq->array[pSeq->size] = data;
	++pSeq->size;
}

//ͷ��
void SeqListPushFront(SeqList* pSeq, DataType data)
{
	assert(pSeq != NULL);
	//�������
	ExpandIfRequired(pSeq);
	//ͨ�����
	//i����λ��
	for (int i = pSeq->size; i > 0; --i)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	/*
	//i��������
	for (int i = pSeq->size - 1; i >= 0; --i)
	{
	pSeq->array[i + 1] = pSeq->array[i];
	}
	*/
	//����
	pSeq->array[0] = data;
	++pSeq->size;
}

//�м����
void SeqListInsert(SeqList* pSeq, int pos, DataType data)
{
	assert(pSeq != NULL);
	assert(pos >= 0 && pos <= pSeq->size);
	//�������
	ExpandIfRequired(pSeq);
	//ͨ�����
	for (int i = pSeq->size; i > pos; --i)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	//����
	pSeq->array[pos] = data;
	++pSeq->size;
}

//ɾ
//βɾ
void SeqListPopBack(SeqList* pSeq)
{
	assert(pSeq != NULL);
	//�������
	if (pSeq->size <= 0)
	{
		printf("û������");
		return;
	}
	//ͨ�����
	--pSeq->size;
}

//ͷɾ
void SeqListTopFront(SeqList* pSeq)
{
	assert(pSeq != NULL);
	//�������
	if (pSeq->size <= 0)
	{
		printf("û������\n");
		return;
	}
	//ͨ�����
	for (int i = 1; i < pSeq->size; ++i)
	{
		pSeq->array[i - 1] = pSeq->array[i];
	}
	--pSeq->size;
}

//�м�ɾ
void SeqListErase(SeqList* pSeq, int pos)
{
	assert(pSeq != NULL);
	assert(pos >= 0 && pos < pSeq->size);
	//�������
	ExpandIfRequired(pSeq);
	//���ݰ���
	for (int i = pos; i < pSeq->size - 1; ++i)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	--pSeq->size;
}

//����,�ҵ��˷����±꣬û�ҵ�����-1��
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

//ɾ������������data
void SeqListRemoveAll(SeqList* pSeq, DataType data)
{
	assert(pSeq!=NULL);
#if 0
	//�򵥷���ʱ�临�Ӷ�λO(n^2)
	int pos;
	while ((pos = SeqListFind(pSeq, data)) != -1)
	{
		SeqListErase(pSeq, pos);
	}
	//���ٿռ�洢�ռ临�Ӷ�λO(n)
	DataType* tempArray = (DataType*)malloc(
		sizeof(DataType)*pSeq->size);
	assert(tempArray != NULL);
	int j = 0;
	//������data����������¿��ٵĿռ���
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
	//ʱ�临�ӶȺͿռ临�Ӷȶ�ΪO(n)
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

//�޸�
void SeqListRevise(SeqList* pSeq, int pos, DataType data)
{
	assert(pSeq != NULL);
	assert(pos >= 0 && pos <= pSeq->size - 1);
	pSeq->array[pos] = data;
}

//��ָ����ٿռ䣬���ı�ֵ
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

//ð������
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

//ѡ������
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

//���ֲ���
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