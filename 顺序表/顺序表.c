#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>

void Test()
{
	SeqList seqList;
	SeqListInit(&seqList); //1.seqList 2.&seqList  
	//传第二个1.指针空间小 2.修改里面的值
	//尾插
	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 4);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 5);
	SeqListPushBack(&seqList, 2);
	SeqListPrint(&seqList);
	//头插
	SeqListPushFront(&seqList, 6);
	SeqListPrint(&seqList);
	//中间插
	SeqListInsert(&seqList, 3, 7);
	SeqListPrint(&seqList);
	//尾删
	SeqListPopBack(&seqList);
	SeqListPrint(&seqList);
	//头删
	SeqListTopFront(&seqList);
	SeqListPrint(&seqList);
	//中间删
	SeqListErase(&seqList, 3);
	SeqListPrint(&seqList);
	//查找
	int c = SeqListFind(&seqList, 2);
	printf("%d\n", c);
	//删除遇到的所有data
	SeqListRemoveAll(&seqList, 2);
	SeqListPrint(&seqList);
	//修改
	SeqListRevise(&seqList, 2, 9);
	SeqListPrint(&seqList);
	//冒泡
	SeqListBubbleSort(&seqList);
	SeqListPrint(&seqList);
	//二分查找
	int a = SeqListTwoPoint(&seqList, 5);
	printf("%d\n", a);
	//选择排序
	SeqListSelectSort(&seqList);
	SeqListPrint(&seqList);
	//二分查找
	int b = SeqListTwoPoint(&seqList, 5);
	printf("%d\n", b);
	//销毁
	SeqListDestroy(&seqList);
}

int main()
{
	Test();
	system("pause");
	return 0;
}