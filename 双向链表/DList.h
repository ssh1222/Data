#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DLDatatype;

typedef struct DListNode
{
	DLDatatype val;
	struct DListNode* next;
	struct DListNode* prev;
} DListNode;

typedef struct
{
	DListNode* head;
} DList;

//内部接口
DListNode* DListNodeBuy(DLDatatype val)
{
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	assert(node);
	node->next = NULL;
	node->prev = NULL;
	node->val = val;
	return node;
}

//初始化、销毁
void DlistInit(DList* dlist)
{
	DListNode* head = DListNodeBuy(0);
	head->next = head;
	head->prev = head;
	dlist->head = head;
}

//清除，不清楚头结点
void DListClear(DList* dlist)
{
	DListNode* cur = dlist->head->next;
	DListNode* next;
	for (; cur != dlist->head; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	dlist->head->next = dlist->head;
	dlist->head->prev = dlist->head;
}

//销毁
void DListDestroy(DList* dlist)
{
	DListClear(dlist);
	free(dlist->head);
	dlist->head = NULL;
}

//增删改查
//头插
void DListPushFront(DList* dlist, DLDatatype val)
{
	DListInsert(dlist->head, val);
}

#if 0
void DListPushFront(DList* dlist, DLDatatype val)
{
	 DListNode* node = DListNodeBuy(val);
	 assert(node);
	 node->next = dlist->head->next;
	 node->prev = dlist->head;
	 dlist->head->next->prev = node;
	 dlist->head->next = node;
}
#endif

//尾插
//空也可以
void DListPushBack(DList* dlist, DLDatatype val)
{
	DListInsert(dlist->head->prev, val);
}

#if 0
void DListPushBack(DList* dlist, DLDatatype val)
{
	DListNode* node = DListNodeBuy(val);
	assert(node);
	node->next = dlist->head;
	node->prev = dlist->head->prev;
	dlist->head->prev->next = node;
	dlist->head->prev = node;
}
#endif

//在pos之前做插入
void DListInsert(DListNode* pos, DLDatatype val)
{
	DListNode* node = DListNodeBuy(val);
	assert(node);

	node->next = pos;
	node->prev = pos->prev;
	pos->prev->next = node;
	pos->prev = node;
}

//头删
void DListPopFront(DList* dlist)
{
	assert(dlist->head->next != dlist->head);//链表不为空
	DListErase(dlist->head->next);
}

#if 0
void DListPopFront(DList* dlist)
{
	assert(dlist->head);
	assert(dlist->head->next);
	DListNode* cur = dlist->head->next;
	dlist->head->next = cur->next;
	cur->next->prev = dlist->head;
}
#endif

//尾删
void DListPopBack(DList* dlist)
{
	assert(dlist->head->next != dlist->head);//链表不为空
	DListErase(dlist->head->prev);
}

#if 0
void DListPopBack(DList* dlist)
{
	assert(dlist->head);
	assert(dlist->head->next);
	dlist->head->prev->prev->next = dlist->head;
	dlist->head->prev = dlist->head->prev->prev;
}
#endif

//删除pos结点,pos不是头结点
void DListErase(DListNode* pos)
{
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

//查找
DListNode* DLsitFind(DList* dlist, DLDatatype val)
{
	DListNode* cur = dlist->head->next;
	for (; cur != dlist->head; cur = cur->next)
	{
		if (cur->val == val)
		{
			return cur;
		}
	}
	return NULL;
}

//打印
void DListPrint(DList* dlist)
{
	DListNode* cur = dlist->head->next;
	for (; cur != dlist->head; cur = cur->next)
	{
		printf("%d-->", cur->val);
	}
	printf("\n");
}

