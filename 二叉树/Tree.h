# pragma once
#include <stdio.h>

typedef struct Node
{
	int val;
	struct Node* left;
	struct Node* right;
}	Node;

//前序遍历二叉树
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

//中序遍历二叉树
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

//后序遍历二叉树
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