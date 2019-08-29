#include<iostream>
using namespace std;

struct node
{
	int data;
	// Địa chỉ node phía sau
	node *next;
};

// Node đầu tiên
node *start;

// Hiện thị Linked List
void show()
{
	node *t = start;

	while(t != NULL)
	{
		cout << t->data << "\t";
		t = t->next;
	}
}

// Chèn vào cuối Linked List
void insert(int x)
{
	node *t = start;

	// Nếu Linked List có ít nhất 1 node
	if (start != NULL)
	{
		// Tìm đến node cuối cùng
		while(t->next != NULL)
			t=t->next;

		// Chèn node mới vào cuối Linked List
		node *n= new node;
		t->next = n;
		n->data = x;
		n->next = NULL;
	}
	else // TH Linked List chưa có node nào
	{
		node *n= new node;
		n->data = x;
		n->next = NULL;
		start = n;
	}
}

// Tìm kiếm
void search(int x)
{
	node *t= start;

	int found = 0;
	// Lặp cho dến node cuối cùng
	while(t != NULL)
	{
		if(t->data == x)
		{
			cout << "\nTim thay!";
			found = 1;
			break;
		}
		t = t->next;
	}

	if(found == 0)
		cout<<"\nKhong tim thay";
}

//
void remove(int x){

	if( start == NULL ){
		cout<<"\nLinked List trong!";
		return ;
	}
	else if( start->data == x ) // Trường hợp x nằm ngay đầu Linked List
	{
		node *temp = start;
		// Node thứ 2 trở thành first node
		start = start->next;
		delete temp;
		return ;
	}

	node *temp = start, *parent = start;
	// Lặp cho đến khi hết node hoặc tìm thấy node có giá trị = x
	while( temp != NULL && temp->data != x )
	{
		parent = temp;
		temp = temp->next;
	}

	if( temp == NULL ){
		cout << endl << x <<" khong ton tai!\nKhong the xoa";
		return ;
	}

	// Parent là node ngay phía trước temp
	parent->next = temp->next;
	delete temp;
}



int main()
{
	int choice, x;
	do
	{
		cout << "\n1. Insert";
		cout << "\n2. Delete";
		cout << "\n3. Search";
		cout << "\n4. Print";
		cout << "\n0. Exit";
		cout << "\n\nEnter you choice : ";
		cin >> choice; 
		switch (choice)
		{
			case 1 : 	cout << "\nEnter the element to be inserted : ";
					 	cin >> x;
					 	insert(x);
						break;
			case 2 : 	cout << "\nEnter the element to be removed : ";
						cin >> x;
						remove(x);
						break;
			case 3 : 	cout << "\nEnter the element to be searched : ";
						cin >> x;
						search(x);
						break;
			case 4 : 	show();
						cout << endl;
						break;
		}
	}
	while(choice!=0);

	return 0;
}