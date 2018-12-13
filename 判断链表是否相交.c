bool hasCycle(struct ListNode *head)
{
	if (head == NULL || head->next == NULL)
	{
		return false;
	}
	ListNode* fast = head->next;
	ListNode* slow = head;
	while (fast != slow)
	{
		if (fast->next == NULL || fast->next->next == NULL)
		{
			return false;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	return true;
}