#include <iostream>
using namespace std;

/**
 * Insertion Sort O(n^2) - Sắp xếp chèn
 * Sắp xếp chèn là một thuật toán sắp xếp bắt chước cách sắp xếp quân bài của
 * những người chơi bài. Muốn sắp một bộ bài theo trật tự người chơi bài rút lần
 * lượt từ quân thứ 2, so với các quân đứng trước nó để chèn vào vị trí thích hợp.
 * Nếu danh sách đã gần đúng thứ tự, Insertion Sort sẽ chạy rất nhanh.
 * https://youtu.be/OGzPmgsI-pQ
*/
void insertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		/**
		 * Di chuyển các phần tử của mảng [0..i-1] ([0..j]) lớn hơn a[i] (key)
		 * đến vị trí liền sau của nó
		*/
		while (0 <= j && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
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
