//#include "SList.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//SList list;
//
//SListNode* Test3(SListNode* head)
//{
//	if (head == NULL || head->next == NULL)
//	{
//		return head;
//	}
//	SListNode* cur = Test3(head->next);
//	head->next->next = head;
//	head->next = NULL;
//	return cur;
//}
//
//int main()
//{
//	SListInit(&list);
//	SListPushFront(&list, 1);
//	SListPushFront(&list, 2);
//	SListPushFront(&list, 3);
//	SListPushFront(&list, 4);
//	SListPushFront(&list, 5);
//	SListPrint(&list);
//	SListNode* head = list.first;
//	SListNode* ret = Test3(head);
//	for (; ret != NULL; ret = ret->next)
//	{
//		printf("%d-->", ret->data);
//	}
//	printf("NULL\n");
//	system("pause");
//	return 0;
//}