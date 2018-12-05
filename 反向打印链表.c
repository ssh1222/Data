#include "SList.h"
#include <stdio.h>
#include <stdlib.h>

SList list;

//�ݹ��β��ͷ��ӡ�����������
void TailSListPrint(SListNode* SList)
{
	if (SList == NULL)
	{
		return;
	}
	TailSListPrint(SList->next);
	printf("%d ", SList->data);
}

int main()
{
	SListInit(&list);
	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	SListPushFront(&list, 4);
	SListPushFront(&list, 5);
	SListPrint(&list);
	SListNode* SList = list.first;
	TailSListPrint(SList);
	printf("\n");
	system("pause");
	return 0;
}