//������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�

class Solution
{
public:
	void push(int node)
	{
		stack1.push(node);
	}

	int pop()
	{
		int ret;
		if (stack2.empty()){
			while (!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		ret = stack2.top();
		stack2.pop();
		return ret;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};