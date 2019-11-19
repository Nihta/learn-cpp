#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *link;
};

struct Stack
{
	Node *top = NULL;
};

void push(Stack &st, int x)
{
	Node *n = new Node;
	n->val = x;
	n->link = st.top;
	st.top = n;
}

Node *pop(Stack &st)
{
	if (st.top == NULL)
	{
		cout << "ERROR! Stack empty!" << endl;
		return NULL;
	}

	Node *top = st.top;
	st.top = st.top->link;
	Node *res = new Node;
	res->val = top->val;
	delete top;

	return res;
}

void show(const Stack &st)
{
	Node *top = st.top;
	cout << "\nStack: ";
	while (top != NULL)
	{
		cout << top->val << " ";
		top = top->link;
	}
}

int main()
{
	Stack st;
	push(st, 1);
	push(st, 2);
	push(st, 3);
	show(st);

	pop(st);
	show(st);

	return 0;
}
