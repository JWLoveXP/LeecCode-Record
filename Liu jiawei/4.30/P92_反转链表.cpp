 ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* p = dummy;
	int i;
	for (i = 1; i < m; i++)
		p = p->next;
	ListNode*q = p->next;
	ListNode* last = q;
	ListNode* temp;
	for (i = m; i <= n; i++)
	{
		temp = q;
		q = q->next;
		temp->next = p->next;
		p->next = temp;
	}
	last->next = q;
	p = dummy->next;
	delete dummy;
	return p;
    }
