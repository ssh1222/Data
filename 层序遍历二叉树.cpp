//#include <queue>
//#include <stack>
//#include <stdio.h>
////�������
//
//typedef struct Node
//{
//	int val;
//	struct Node* left;
//	struct Node* right;
//}	Node;
//
//typedef struct Result{
//	Node* node;  //�����õ���ĸ����
//	int used;    //�������Ĺ������õ���val����
//}	Result;
//
//
////�������������
//void LevelOrderTraversal(Node *root)
//{
//	if (root == NULL){                                                                                                                                                                                                                                                                                                                                     
//		return;                                                                                                                                                                                                                                                                                            
//	}
//
//	//�������У������д������������Node*
//	//�����ռ�
//	//ģ��
//	std::queue<Node *> q;
//
//	q.push(root);
//
//	while (!q.empty()){
//		Node *node = q.front();   //ȥ���׽��
//		q.pop();       //�������׽��
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
////�ж�һ�����Ƿ�����ȫ������
//bool isCompleteTree(Node *root)
//{
//	if (root == NULL){
//		return true;
//	}
//
//	//�������У������д������������Node*
//	//�����ռ�
//	//ģ��
//	std::queue<Node *> q;
//
//	q.push(root);
//
//	while (1){
//		Node *node = q.front();  //ȡ���׽��
//		q.pop();
//		if (node == NULL){
//			//�ڲ�������Ĺ����������ս��
//			break;
//		}
//		q.push(node->left);
//		q.push(node->right);
//	}
//
//	//���ʣ�½������û�зǽ��
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
////ǰ������ǵݹ�
//void PreorderTraversalNoR(Node *root)
//{
//	std::stack<Node *> s;   //ջ
//	Node *cur = root;
//	Node *top = NULL;
//
//	while (cur != NULL || !s.empty()){
//		//һ·����Ĺ���
//		while (cur != NULL){
//			printf("%c ", cur->val);
//			s.push(cur);
//			cur = cur->left;
//		}
//
//		//һ������������NULL
//		//����ջ����ʣ���������
//		top = s.top();
//		s.pop();
//		cur = top->right;
//	}
//}
//
////��������ǵݹ�
//void InorderTraversalNoR(Node *root)
//{
//	std::stack<Node *> s;
//	Node *cur = root;
//	Node *top = NULL;
//
//	//һ·����Ĺ���
//	while (cur != NULL || !s.empty()){
//		//��һ�������Ľ���λ��
//		s.push(cur);
//		cur = cur->left;
//	}
//
//	//һ������������NULL
//	//����ջ����ʣ���������
//	top = s.top;
//	s.pop();
//	//�ڶ��������ĵط�
//	printf("%c ", top->val);
//
//	cur = top->right;
//}
//
////��������ǵݹ�
//void PostorderTraversalNoR(Node *root) 
//{
//	std::stack<Node *> s;
//	Node *cur = root;
//	Node *top = NULL;
//	Node *last = NULL;
//
//	while (cur != NULL || !s.empty()){
//		//һ·����Ĺ���
//		while (cur != NULL){
//			//��һ�������Ľ���λ��
//			s.push(cur);
//			cur = cur->left;
//		}
//
//		//һ������������NULL
//		//����ջ����ʣ���������
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
