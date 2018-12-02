#include "SList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//初始化
void SListInit(SList* list)
{
	assert(list != NULL);
	list->first = NULL;
}

//销毁
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

//开辟结点
static SListNode* SListBuyNode(SLDataType data)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	assert(node);
	node->data = data;
	node->next = NULL;
	return node;
}

//头插
void SListPushFront(SList* list, SLDataType data)
{
	assert(list != NULL);
	//Node空间开辟
	SListNode* node = SListBuyNode(data);
	node->next = list->first;
	list->first = node;
}

//尾插
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

//在结点后面插入
void SListINsertAfter(SListNode* pos, SLDataType data)
{
	assert(pos != NULL);
	SListNode* node = SListBuyNode(data);
	node->next = pos->next;
	pos->next = node;
}

//头删
void SListPopFront(SList* list)
{
	assert(list != NULL);//没有链表
	assert(list->first != NULL);//有链表，但是链表是空的
	SListNode* old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}

//尾删
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

//删除pos结点后的结点
//pos不是最后一个结点
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


//删除第一个遇到的data结点
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

//查找
//NULL表示没有找到
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
	//没有找到！
	return NULL;
}

//打印
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
