#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>

void Test()
{
	SeqList seqList;
	SeqListInit(&seqList); //1.seqList 2.&seqList  
	//���ڶ���1.ָ��ռ�С 2.�޸������ֵ
	//β��
	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 4);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 5);
	SeqListPushBack(&seqList, 2);
	SeqListPrint(&seqList);
	//ͷ��
	SeqListPushFront(&seqList, 6);
	SeqListPrint(&seqList);
	//�м��
	SeqListInsert(&seqList, 3, 7);
	SeqListPrint(&seqList);
	//βɾ
	SeqListPopBack(&seqList);
	SeqListPrint(&seqList);
	//ͷɾ
	SeqListTopFront(&seqList);
	SeqListPrint(&seqList);
	//�м�ɾ
	SeqListErase(&seqList, 3);
	SeqListPrint(&seqList);
	//����
	int c = SeqListFind(&seqList, 2);
	printf("%d\n", c);
	//ɾ������������data
	SeqListRemoveAll(&seqList, 2);
	SeqListPrint(&seqList);
	//�޸�
	SeqListRevise(&seqList, 2, 9);
	SeqListPrint(&seqList);
	//ð��
	SeqListBubbleSort(&seqList);
	SeqListPrint(&seqList);
	//���ֲ���
	int a = SeqListTwoPoint(&seqList, 5);
	printf("%d\n", a);
	//ѡ������
	SeqListSelectSort(&seqList);
	SeqListPrint(&seqList);
	//���ֲ���
	int b = SeqListTwoPoint(&seqList, 5);
	printf("%d\n", b);
	//����
	SeqListDestroy(&seqList);
}

int main()
{
	Test();
	system("pause");
	return 0;
}