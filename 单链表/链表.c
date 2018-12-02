#include "SList.h"
#include <stdlib.h>

void Test()
{
	SList list;
	SListInit(&list);
	//头插
	SListPushFront(&list, 4);
	SListPushFront(&list, 5);
	SListPrint(&list);
	//尾插
	SListPushBack(&list, 3);
	SListPushBack(&list, 2);
	SListPushBack(&list, 1);
	SListPrint(&list);
	//在pos后插入
	SListNode* cur=SListFind(&list, 3);
	SListINsertAfter(cur, 10);
	SListPrint(&list);
	//头删
	SListPopFront(&list);
	SListPrint(&list);
	//尾删
	SListPopBack(&list);
	SListPrint(&list);
	//在指定结点后删除
	SListEraseAfter(cur);
	SListPrint(&list);
}

int main()
{
	Test();
	system("pause");
	return 0;
}