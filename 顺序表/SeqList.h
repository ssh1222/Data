#pragma once  //防止头文件被重复使用
              // #ifndef  endif同理

//数据结构是抽象类型
//数据本身不仅仅是数字

typedef int DataType;

#define INIT_CAPACITY (2)

typedef struct SeqList
{
	DataType* array;
	int capacity;  //当前容量
	int size;     //1.保存顺序表里已经存了的数据个数
	              //2.当前可用下标
}SeqList;

//接口 （函数）
//初始化、销毁、
//增、删、查、改

//初始化（函数设计）
void SeqListInit(SeqList* pSeq);

//销毁
void SeqListDestroy(SeqList* pSeq);

//扩容
static void ExpandIfRequired(SeqList* pSeq);

//增
//尾插（尽量和C++的 STL统一）
void SeqListPushBack(SeqList* pSeq, DataType data);

//头插
void SeqListPushFront(SeqList* pSeq, DataType data);

//中间插入
void SeqListInsert(SeqList* pSeq, int pos, DataType data);

//删
//尾删
void SeqListPopBack(SeqList* pSeq);

//头删
void SeqListTopFront(SeqList* pSeq);

//中间删
void SeqListErase(SeqList* pSeq, int pos);

//删除所有遇到的data
void SeqListRemoveAll(SeqList* pSeq, DataType data);

//查找
int SeqListFind(SeqList* pSeq, DataType data);

//修改
void SeqListRevise(SeqList* pSeq, int pos, DataType data);

//传指针减少空间，不改变值
void SeqListPrint(const SeqList* pSeq);

//冒泡排序
void SeqListBubbleSort(SeqList* pSeq);

//选择排序
void SeqListSelectSort(SeqList* pSeq);

//二分查找
int SeqListTwoPoint(SeqList* pSeq, DataType data);









