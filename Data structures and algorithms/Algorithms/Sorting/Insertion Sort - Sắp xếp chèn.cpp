/*
	Insertion Sort O(n*2) - Sắp xếp chèn

Sắp xếp chèn là một thuật toán sắp xếp bắt chước cách sắp xếp quân bài của những người chơi bài.
Muốn sắp một bộ bài theo trật tự người chơi bài rút lần lượt từ quân thứ 2, so với các quân đứng trước nó để chèn vào vị trí thích hợp.
Nếu danh sách đã gần đúng thứ tự, Insertion Sort sẽ chạy rất nhanh.
https://youtu.be/OGzPmgsI-pQ
*/
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		// Tìm vị trí phù hợp cho arr[i]
		int j = i;
		while (j > 0 && arr[i] < arr[j-1])
			--j;

		// Chèn arr[i] vào vị trí phù hợp
		int tmp = arr[i];
		// Đẩy các phần tử từ arr[j]...arr[i-1] đến a[j+1]...arr[i]
		for (int k = i; k > j; k--)
			arr[k] = arr[k-1];
		// Thay arr[j] cũ bằng arr[i] cũ
		arr[j] = tmp;
	}
}

int main()
{
	int arr[] = {1, 2, 3, 4, 7, 6, 5, 9, 8};
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);

	for (auto &&i : arr)
		cout << i << " ";

	return 0; 
} 

