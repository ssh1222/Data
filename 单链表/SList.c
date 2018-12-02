#include "SList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��ʼ��
void SListInit(SList* list)
{
	assert(list != NULL);
	list->first = NULL;
}

//����
void SListDestroy(SList* list)
{
	assert(list != NULL);
	SListNode* next;
	for (SListNode* cur = list->first; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	list->first = NULL;
}

//���ٽ��
static SListNode* SListBuyNode(SLDataType data)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	assert(node);
	node->data = data;
	node->next = NULL;
	return node;
}

//ͷ��
void SListPushFront(SList* list, SLDataType data)
{
	assert(list != NULL);
	//Node�ռ俪��
	SListNode* node = SListBuyNode(data);
	node->next = list->first;
	list->first = node;
}

//β��
void SListPushBack(SList* list, SLDataType data)
{
	assert(list != NULL);
	if (list->first == NULL)
	{
		SListPushFront(list, data);
		return;
	}
	SListNode* lastone = list->first;
	while (lastone->next != NULL)
	{
		lastone = lastone->next;
	}
	SListNode* node = SListBuyNode(data);
	lastone->next = node;
}

//�ڽ��������
void SListINsertAfter(SListNode* pos, SLDataType data)
{
	assert(pos != NULL);
	SListNode* node = SListBuyNode(data);
	node->next = pos->next;
	pos->next = node;
}

//ͷɾ
void SListPopFront(SList* list)
{
	assert(list != NULL);//û������
	assert(list->first != NULL);//���������������ǿյ�
	SListNode* old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}

//βɾ
void SListPopBack(SList* list)
{
	assert(list != NULL);
	assert(list->first != NULL);
	SListNode* cur = list->first;
	if (cur->next == NULL)
	{
		SListPopFront(list);
		return;
	}
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

//ɾ��pos����Ľ��
//pos�������һ�����
void SListEraseAfter(SListNode* pos)
{
	assert(pos != NULL);
	if (pos->next == NULL)
	{
		return;
	}
	SListNode* cur = pos->next;
	pos->next = pos->next->next;
	free(cur);
}


//ɾ����һ��������data���
void SListRemove(SList* list, SLDataType data)
{
	assert(list != NULL);
	SListNode* cur = list->first;
	SListNode* prev = NULL;
	while (cur != NULL && cur->data != data)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL)
	{
		return;
	}
	if (prev == NULL)
	{
		SListPopFront(list);
		return;
	}
	prev->next = cur->next;
	free(cur);
}

//����
//NULL��ʾû���ҵ�
SListNode* SListFind(SList* list, SLDataType data)
{
	assert(list != NULL);
	for (SListNode* cur = list->first; cur != NULL; cur = cur->next)
	{
		if (cur->data == data)
		{
			return cur;
		}
	}
	//û���ҵ���
	return NULL;
}

//��ӡ
void SListPrint(SList* list)
{
	assert(list != NULL);
	SListNode* cur = list->first;
	for (; cur != NULL; cur = cur->next)
	{
		printf("%d-->", cur->data);
	}
	printf("NULL\n");
}
