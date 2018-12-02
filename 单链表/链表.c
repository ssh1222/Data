#include "SList.h"
#include <stdlib.h>

void Test()
{
	SList list;
	SListInit(&list);
	//ͷ��
	SListPushFront(&list, 4);
	SListPushFront(&list, 5);
	SListPrint(&list);
	//β��
	SListPushBack(&list, 3);
	SListPushBack(&list, 2);
	SListPushBack(&list, 1);
	SListPrint(&list);
	//��pos�����
	SListNode* cur=SListFind(&list, 3);
	SListINsertAfter(cur, 10);
	SListPrint(&list);
	//ͷɾ
	SListPopFront(&list);
	SListPrint(&list);
	//βɾ
	SListPopBack(&list);
	SListPrint(&list);
	//��ָ������ɾ��
	SListEraseAfter(cur);
	SListPrint(&list);
}

int main()
{
	Test();
	system("pause");
	return 0;
}