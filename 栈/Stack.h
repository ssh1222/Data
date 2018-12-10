#pragma once
#include <assert.h>

#define MAX 100

typedef int SDataType;

//���þ�̬˳���ʵ��ջ
typedef struct Stack
{
	SDataType val;
	SDataType array[MAX];
	int top;
} Stack;

//��ʼ��
void StackInit(Stack* stack)
{
	stack->top = 0;
}

//����
void StackDestroy(Stack* stack)
{
	stack->top = 0;
}

//��ɾ�Ĳ�
//ֻ�ܴ�ջ������
void StackPush(Stack* stack, SDataType val)
{
	assert(stack);
	assert(stack->top < MAX);
	stack->array[stack->top] = val;
	++stack->top;
}

//ֻ�ܴ�ջ��ɾ��
void StackPop(Stack* stack)
{
	assert(stack);
	assert(stack->top > 0);
	--stack->top;
}

//����ջ��Ԫ��
SDataType stackTop(Stack* stack)
{
	assert(stack);
	assert(stack->top > 1);
	return stack->array[stack->top - 1];
}

//�ж��Ƿ�Ϊ��
int StackEmpty(Stack* stack)
{
	return stack->top > 0 ? 0 : 1;
}

//����ջ��Ԫ�ظ���
int StackSize(Stack* stack)
{
	return stack->top;
}