// Bubble Sort O(n^2) - Sắp xếp nổi bọt

#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * Sắp xếp nổi bọt là một giải thuật sắp xếp đơn giản. Giải thuật sắp xếp này
 * được tiến hành dựa trên việc so sánh cặp phần tử liền kề nhau và tráo đổi
 * thứ tự nếu chúng không theo thứ tự. Giải thuật này không thích hợp sử dụng
 * với các tập dữ liệu lớn khi mà độ phức tạp trường hợp xấu nhất và trường hợp
 * trung bình là Ο(n^2) với n là số phần tử
 * Giải thuật sắp xếp nổi bọt là giải thuật chậm nhất trong số các giải thuật sắp
 * xếp cơ bản
 * Giải thuật này còn chậm hơn giải thuật đổi chỗ trực tiếp mặc dù số lần so sánh
 * bằng nhau, nhưng do đổi chỗ hai phần tử kề nhau nên số lần đổi chỗ nhiều hơn
 * https://youtu.be/nmhjrI-aW5o
*/
void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

int main()
{
	int arr[] = {1, 5, 3, 4, 2, 8, 6, 9, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	bubbleSort(arr, n);

	cout << "Sorted array: ";
	for (auto &&i : arr)
		cout << i << " ";

	return 0;
}
