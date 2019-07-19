// Linear Search O(n) - Tìm kiếm tuyến tính
#include<iostream>
using namespace std;
/*
	Bắt đầu từ phần tử ngoài cùng bên trái của array[] và lần lượt so sánh key với từng phần tử của array[]
	Nếu key khớp với một phần tử return chỉ mục (i)
	Nếu key không khớp với bất kỳ phần tử nào return -1
 */
int LinearSearch(int *array, int size, int key)
{
	for (int i = 0; i < size; ++i)
		if (array[i] == key)
			return i;
	return -1;
}


int main()
{
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = sizeof(array)/sizeof(array[0]);
	int key = 5;

	int index = LinearSearch(array, size, key);

	if (index != -1)
		cout<<"\nNumber found at index : "<<index;
	else
		cout<<"\nNot found";

	return 0;
}
