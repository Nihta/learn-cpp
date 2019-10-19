#include <stdio.h>

struct Node
{
	int data;
	Node *next;
};

Node *makeNode(int n)
{
	Node *tmp = new Node;
	tmp->data = n;
	tmp->next = NULL;
	return tmp;
}

struct List
{
	Node *first = NULL;
	Node *last = NULL;
};

// Kiểm tra list trống hay không
bool isEmpty(const List &L)
{
	if (L.first == NULL)
		return true;
	else
		return false;
}

// Số Lượng node của list
int size(const List &L)
{
	int size = 0;
	for (Node *p = L.first; p != NULL; p = p->next)
		size++;
	return size;
}

// In thông tin của list
void infoList(List L)
{
	if (isEmpty(L))
	{
		printf("Danh sach trong!");
	}
	else
	{
		printf("List: ");
		for (Node *p = L.first; p != NULL; p = p->next)
			printf("%d ", p->data);
		printf("\nSize: %d\n", size(L));
		printf("First: %d\n", L.first->data);
		printf("Last: %d\n", L.last->data);
	}
}

// Chèn node vào đầu
void insertHead(List &L, Node *p)
{
	if (isEmpty(L)) // Nếu như list không có Node nào
	{
		L.first = L.last = p;
	}
	else // Nếu như list >= 1 Node
	{
		p->next = L.first;
		L.first = p;
	}
}

// Chèn node vào cuối list
void insertTail(List &L, Node *p)
{
	if (isEmpty(L)) // Nếu như list không có Node nào
	{
		L.first = L.last = p;
	}
	else // Nếu như list >= 1 Node
	{
		L.last->next = p;
		L.last = p;
	}
}

// Chèn node vào list dựa vào index
void insert(List &L, int index, Node *p)
{
	int sizeL = size(L);
	if (index == 0)
	{
		insertHead(L, p);
	}
	else if (index == sizeL)
	{
		insertTail(L, p);
	}
	else if (0 < index && index < size(L))
	{
		Node *q = L.first;
		while (index != 1)
		{
			index--;
			q = q->next;
		}
		p->next = q->next;
		q->next = p;
	}
	else
	{
		printf("Vi tri chen khong hop le!\n");
	}
}

// Xóa node đầu
void removeHead(List &L)
{
	if (isEmpty(L)) // Nếu list không có node nào
	{
		printf("Khong co phan tu nao de xoa!\n");
	}
	else if (L.first->next == NULL) // Nếu list có một node
	{
		L.first = L.last = NULL;
	}
	else // Nếu như list >= 2 Node
	{
		Node *tmp = L.first;
		L.first = L.first->next;
		delete tmp;
	}
}

// Xóa node cuối list
void removeTail(List &L)
{
	if (isEmpty(L)) // Nếu list không có node nào
	{
		printf("Khong co phan tu nao de xoa!\n");
	}
	else if (L.first->next == NULL) // Nếu list có một node
	{
		L.first = L.last = NULL;
	}
	else // Nếu như list >= 2 Node
	{
		for (Node *p = L.first; p != NULL; p = p->next)
		{
			if (p->next == L.last)
			{
				delete L.last;
				L.last = p;
				L.last->next = NULL;
			}
		}
	}
}

// Xóa dựa vào index
void removeIndex(List &L, int index)
{
	int sizeL = size(L);
	if (index == 0)
	{
		removeHead(L);
	}
	else if (index + 1 == sizeL)
	{
		removeTail(L);
	}
	else if (0 < index && index < sizeL)
	{
		Node *q = L.first;
		while (index != 1)
		{
			index--;
			q = q->next;
		}

		Node *tmp = q->next;
		q->next = q->next->next;
		delete tmp;
	}
	else
	{
		printf("Vi tri xoa khong hop le!\n");
	}
}

// Xóa toàn bộ List
void clear(List &L)
{
	Node *p = L.first;
	while (p != NULL)
	{
		Node *tmp = p;
		p = p->next;
		delete tmp;
	}
	L.first = L.last = NULL;
}

// Tìm kiếm node dựa vào index
Node *findIndex(const List &L, int index)
{
	for (Node *p = L.first; p != NULL; p = p->next)
	{
		if (index == 0)
			return p;
		index--;
	}
	return NULL;
}

// Tìm kiếm vị trí của node có data = value
int findValue(const List L, int value)
{
	int index = 0;
	for (Node *p = L.first; p != NULL; p = p->next)
	{
		if (p->data == value)
			return index;
		index++;
	}
	return -1;
}

int main()
{
	// Khởi tạo list
	List L;

	// Chèn vào đầu, cuối
	insertHead(L, makeNode(3));
	insertHead(L, makeNode(2));
	insertHead(L, makeNode(1));
	insertHead(L, makeNode(0));
	insertTail(L, makeNode(4));
	insertTail(L, makeNode(5));
	insertTail(L, makeNode(6));
	infoList(L);
	printf("------------------------------------\n");

	// Xóa đầu, cuối
	removeHead(L);
	removeTail(L);
	infoList(L);
	printf("------------------------------------\n");

	// Chèn ở index
	insert(L, 4, makeNode(99));
	infoList(L);
	printf("------------------------------------\n");

	// Xóa ở index
	removeIndex(L, 4);
	infoList(L);
	printf("------------------------------------\n");

	// Tìm kiếm theo index
	int index = 4;
	if (findIndex(L, index) != NULL)
	{
		printf("Data can tim: %d\n", findIndex(L, index)->data);
	}
	else
	{
		printf("Khong tim thay!\n");
	}

	// Tìm kiếm theo value
	int value = 4;
	if (findValue(L, value) != -1)
	{
		printf("Tim thay %d tai index = %d\n", value, findValue(L, value));
	}
	else
	{
		printf("Khong tim thay!\n");
	}

	clear(L);

	return 0;
}
