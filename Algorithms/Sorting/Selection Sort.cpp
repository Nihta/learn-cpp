/**
 * Selection Sort - Sắp xếp chọn
 * Time Complexity: O(n^2)
*/
#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * Ý tưởng thuật toán là thực hiện n-1 lượt việc đưa phần tử nhỏ nhất trong dãy
 * hiện hành về vị trí đúng ở đầu dãy
 * https://youtu.be/xWBP4lzkoyM
*/
void selectionSort(int arr[], int n)
{
	// Tường bước một di chuyển ranh giới của mảng con chưa được sắp xếp
	for (int i = 0; i < n - 1; i++)
	{
		// Tìm phần tử nhỏ nhất trong dãy chưa được sắp xếp
		int min_idx = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Hoán đổi phần tử nhỏ nhất (trong mảng con chưa sắp xếp) vừa tìm được
		// với phần tử đầu mảng (mảng con chưa được sắp xếp)
		swap(&arr[min_idx], &arr[i]);
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = {9, 8, 7, 1, 2, 3, 6, 5, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, n);

	cout << "Sorted array: ";
	printArray(arr, n);
	return 0;
}
