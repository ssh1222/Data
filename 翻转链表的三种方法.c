#include "SList.h"
#include <stdio.h>
#include <stdlib.h>

SList list;

//递归从尾到头打印单链表的数据
void TailSListPrint(SListNode* SList)
{
	if (SList == NULL)
	{
		return;
	}
	TailSListPrint(SList->next);//递归打印
	printf("%d ", SList->data);
}

//翻转链表
//递归翻转
SListNode* Test(SListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	SListNode* cur = Test(head->next);//递归翻转
	head->next->next = head;
	head->next = NULL;
	return cur;
}
//头删，头插翻转
SListNode* Test1(SListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	SListNode* newHead = NULL;
	SListNode* node;
	while (head != NULL)
	{
		node = head;//头删
		head = head->next;

		node->next = newHead;//头插
		newHead = node;
	}
	return newHead;
}
//改变指向方法
SListNode* Test2(SListNode *head)
{
	if (head == NULL)
	{
		return head;
	}
	SListNode* p0 = NULL;
	SListNode* p1 = head;
	SListNode* p2 = head->next;
	while (p1 != NULL)
	{
		p1->next = p0;
		p0 = p1;
		p1 = p2;
		if (p2 != NULL)
		{
			p2 = p2->next;
		}
	}
	return p0;
}

int main()
{
	SListInit(&list);
	//头插
	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	SListPushFront(&list, 4);
	SListPushFront(&list, 5);
	SListPrint(&list);

	//反向打印链表
	SListNode* SList = list.first;
	TailSListPrint(SList);
	printf("\n");

	//翻转链表
	//递归翻转
	SListNode* head = list.first;
	SListNode* ret = Test(head);
	for (; ret != NULL; ret = ret->next)//打印链表
	{
		printf("%d-->", ret->data);
	}
	printf("NULL\n");
	//头删、头插翻转
	SListNode* ret1 = Test1(head);
	for (; ret1 != NULL; ret1 = ret1->next)//打印链表
	{
		printf("%d-->", ret1->data);
	}
	printf("NULL\n");
	//改变指向方法
	SListNode* ret2 = Test2(head);
	for (; ret2 != NULL; ret2 = ret2->next)//打印链表
	{
		printf("%d-->", ret2->data);
	}
	printf("NULL\n");

	//
	system("pause");
	return 0;
}