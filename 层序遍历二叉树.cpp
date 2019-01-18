//#include <queue>
//#include <stack>
//#include <stdio.h>
////层序遍历
//
//typedef struct Node
//{
//	int val;
//	struct Node* left;
//	struct Node* right;
//}	Node;
//
//typedef struct Result{
//	Node* node;  //创建好的书的根结点
//	int used;    //创建树的过程中用掉的val个数
//}	Result;
//
//
////层序遍历二叉树
//void LevelOrderTraversal(Node *root)
//{
//	if (root == NULL){                                                                                                                                                                                                                                                                                                                                     
//		return;                                                                                                                                                                                                                                                                                            
//	}
//
//	//来个队列，队列中存的数据类型是Node*
//	//命名空间
//	//模板
//	std::queue<Node *> q;
//
//	q.push(root);
//
//	while (!q.empty()){
//		Node *node = q.front();   //去队首结点
//		q.pop();       //弹出队首结点
//		printf("%c ", node->val);
//
//		if (node->left != NULL){
//			q.push(node->left);
//		}
//
//		if (node->right != NULL){
//			q.push(node->right);
//		}
//	}
//}
//
////判断一棵树是否是完全二叉树
//bool isCompleteTree(Node *root)
//{
//	if (root == NULL){
//		return true;
//	}
//
//	//来个队列，队列中存的数据类型是Node*
//	//命名空间
//	//模板
//	std::queue<Node *> q;
//
//	q.push(root);
//
//	while (1){
//		Node *node = q.front();  //取队首结点
//		q.pop();
//		if (node == NULL){
//			//在层序遍历的过程中遇到空结点
//			break;
//		}
//		q.push(node->left);
//		q.push(node->right);
//	}
//
//	//检查剩下结点中有没有非结点
//	while (!q.empty()){
//		Node *node = q.front();
//		q.pop();
//		if (node != NULL){
//			return false;
//		}
//	}
//
//	return true;
//}
//
////前序遍历非递归
//void PreorderTraversalNoR(Node *root)
//{
//	std::stack<Node *> s;   //栈
//	Node *cur = root;
//	Node *top = NULL;
//
//	while (cur != NULL || !s.empty()){
//		//一路向左的过程
//		while (cur != NULL){
//			printf("%c ", cur->val);
//			s.push(cur);
//			cur = cur->left;
//		}
//
//		//一定是向左遇到NULL
//		//利用栈处理剩余的右子树
//		top = s.top();
//		s.pop();
//		cur = top->right;
//	}
//}
//
////中序遍历非递归
//void InorderTraversalNoR(Node *root)
//{
//	std::stack<Node *> s;
//	Node *cur = root;
//	Node *top = NULL;
//
//	//一路向左的过程
//	while (cur != NULL || !s.empty()){
//		//第一次遇到的结点的位置
//		s.push(cur);
//		cur = cur->left;
//	}
//
//	//一定是向左遇到NULL
//	//利用栈处理剩余的右子树
//	top = s.top;
//	s.pop();
//	//第二次遇到的地方
//	printf("%c ", top->val);
//
//	cur = top->right;
//}
//
////后序遍历非递归
//void PostorderTraversalNoR(Node *root) 
//{
//	std::stack<Node *> s;
//	Node *cur = root;
//	Node *top = NULL;
//	Node *last = NULL;
//
//	while (cur != NULL || !s.empty()){
//		//一路向左的过程
//		while (cur != NULL){
//			//第一次遇到的结点的位置
//			s.push(cur);
//			cur = cur->left;
//		}
//
//		//一定是向右遇到NULL
//		//利用栈处理剩余的右子树
//		top = s.top();
//		if (top->right == NULL){
//			printf("%c ", top->val);
//			s.pop();
//			last = top;
//		}
//		else if (top->right == last){
//			printf("%c ", top->val);
//			s.pop();
//			last = top;
//		}
//		else{
//			cur = cur->right;
//		}
//	}
//}
