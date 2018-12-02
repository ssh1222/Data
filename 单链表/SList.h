#pragma once

//����+��ѭ��+����ͷ
typedef int SLDataType;

typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
} SListNode;

typedef struct SList
{
	struct SListNode* first;
} SList;

//��ʼ��������
void SListInit(SList* list);
void SListDestroy(SList* list);

//��ɾ���
//ͷ��
void SListPushFront(SList* list, SLDataType data);

//β��
void SListPushBack(SList* list, SLDataType data);

//��pos���������
void SListINsertAfter(SListNode* pos, SLDataType data);

//ͷɾ
void SListPopFront(SList* list);

//βɾ
void SListPopBack(SList* list);

//ɾ��pos����Ľ��
//pos�������һ�����
void SListEraseAfter(SListNode* pos);

//ɾ����һ��������data���
void SListRemove(SList* list, SLDataType data);

//����
SListNode* SListFind(SList* list, SLDataType data);

//��ӡ
void SListPrint(SList* list);