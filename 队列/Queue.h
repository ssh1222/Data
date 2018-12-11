#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;

//�õ�����ʵ�ֶ���
typedef struct QNode
{
	QDataType val;
	struct QNode* next;
} QNode;

typedef struct Queue
{
	QNode* front; //ָ������ĵ�һ�����
	QNode* rear;  //ָ�����������һ�����
	int size;     //������Ԫ�صĸ���
} Queue;

//��ʼ��
void QueueInit(Queue* queue)
{
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}

//����
void QueueDestory(Queue* queue)
{
	QNode* next;
	for (QNode* cur = queue->front; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}

//��ɾ�Ĳ�
//ֻ���ڶ�β����
void QueuePush(Queue* queue, QDataType val)
{
	//�����½ڵ�
	QNode* node = (QNode*)malloc(sizeof(QNode));
	assert(node);
	node->next = NULL;
	node->val = val;
	if (queue->rear == NULL)
	{
		queue->front = queue->rear = node;
	}
	else
	{
		queue->rear->next = node;
		queue->rear = node;
	}
}

//ֻ�ܴӶ���ɾ��
void QueuePop(Queue* queue)
{
	assert(queue->size > 0);
	QNode* cur = queue->front;
	queue->front = queue->front->next;
	free(cur);
	if (queue->front == NULL);
	{
		queue->rear = NULL;
	}
	--queue->size;
}

//���ض���Ԫ��
QDataType QueueFront(const Queue* queue)
{
	assert(queue->size > 0);
	return queue->front->val;
}

//�ж������Ƿ�Ϊ��
int QueueEmpty(const Queue* queue)
{
	return queue->size > 0 ? 0 : 1;
}

//���еĴ�С
int QueueSize(const Queue* queue)
{
	return queue->size;
}