#pragma once  //��ֹͷ�ļ����ظ�ʹ��
              // #ifndef  endifͬ��

//���ݽṹ�ǳ�������
//���ݱ�������������

typedef int DataType;

#define INIT_CAPACITY (2)

typedef struct SeqList
{
	DataType* array;
	int capacity;  //��ǰ����
	int size;     //1.����˳������Ѿ����˵����ݸ���
	              //2.��ǰ�����±�
}SeqList;

//�ӿ� ��������
//��ʼ�������١�
//����ɾ���顢��

//��ʼ����������ƣ�
void SeqListInit(SeqList* pSeq);

//����
void SeqListDestroy(SeqList* pSeq);

//����
static void ExpandIfRequired(SeqList* pSeq);

//��
//β�壨������C++�� STLͳһ��
void SeqListPushBack(SeqList* pSeq, DataType data);

//ͷ��
void SeqListPushFront(SeqList* pSeq, DataType data);

//�м����
void SeqListInsert(SeqList* pSeq, int pos, DataType data);

//ɾ
//βɾ
void SeqListPopBack(SeqList* pSeq);

//ͷɾ
void SeqListTopFront(SeqList* pSeq);

//�м�ɾ
void SeqListErase(SeqList* pSeq, int pos);

//ɾ������������data
void SeqListRemoveAll(SeqList* pSeq, DataType data);

//����
int SeqListFind(SeqList* pSeq, DataType data);

//�޸�
void SeqListRevise(SeqList* pSeq, int pos, DataType data);

//��ָ����ٿռ䣬���ı�ֵ
void SeqListPrint(const SeqList* pSeq);

//ð������
void SeqListBubbleSort(SeqList* pSeq);

//ѡ������
void SeqListSelectSort(SeqList* pSeq);

//���ֲ���
int SeqListTwoPoint(SeqList* pSeq, DataType data);









