#include "SList.h"
#include <stdio.h>
#include <stdlib.h>

SList list;

SListNode* Partition(SListNode* head, int x)
{
	SListNode* min = NULL;
	SListNode* minTail = NULL;
	SListNode* maxeq = NULL;
	SListNode* maxeqTail = NULL;
	while (head != NULL)
	{
		if (head->data < x)
		{
			if (min == NULL)
			{
				min = head;
				minTail = head;
			}
			else
			{
				minTail->next = head;
				minTail = head;
			}
		}
		else
		{
			if (maxeq == NULL)
			{
				maxeq = head;
				maxeqTail = head;
			}
			else
			{
				maxeqTail->next = head;
				maxeqTail = head;
			}
		}
		head = head->next;
	}
	if (min != NULL && maxeq != NULL)
	{
		maxeqTail->next = NULL;
		minTail->next = maxeq;
		return min;
	}
	if (min != NULL && maxeq == NULL)
	{
		return min;
	}
	if (min == NULL && maxeq != NULL)
	{
		return maxeq;
	}
	return head;
}
int main()
{
	SListInit(&list);
	//Í·²å
	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 4);
	SListPushFront(&list, 3);
	SListPushFront(&list, 5);
	SListPrint(&list);
	SListNode* head = list.first;
	SListNode* ret = Partition(head, 3);
	for (; ret != NULL; ret = ret->next)//´òÓ¡Á´±í
	{
		printf("%d-->", ret->data);
	}
	printf("NULL\n");
	system("pause");
	return 0;
}