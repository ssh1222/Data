# pragma once
#include <stdio.h>

typedef struct Node
{
	int val;
	struct Node* left;
	struct Node* right;
}	Node;

//ǰ�����������
void Preorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->val);
	Preorder(root->left);
	Preorder(root->right);
}

//�������������
void MiddleOrder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	MiddleOrder(root->left);
	printf("%d ", root->val);
	MiddleOrder(root->right);
}

//�������������
void Epilogue(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	Epilogue(root->left);
	Epilogue(root->right);
	printf("%d ", root->val);
}