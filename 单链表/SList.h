#pragma once

//单向+不循环+不带头
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

//初始化、销毁
void SListInit(SList* list);
void SListDestroy(SList* list);

//增删查改
//头插
void SListPushFront(SList* list, SLDataType data);

//尾插
void SListPushBack(SList* list, SLDataType data);

//在pos结点后面插入
void SListINsertAfter(SListNode* pos, SLDataType data);

//头删
void SListPopFront(SList* list);

//尾删
void SListPopBack(SList* list);

//删除pos结点后的结点
//pos不是最后一个结点
void SListEraseAfter(SListNode* pos);

//删除第一个遇到的data结点
void SListRemove(SList* list, SLDataType data);

//查找
SListNode* SListFind(SList* list, SLDataType data);

//打印
void SListPrint(SList* list);