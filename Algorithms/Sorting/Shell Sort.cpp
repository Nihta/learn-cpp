// Shell Sort 
// https://youtu.be/SHcPqUe2GZM

#include <iostream>
using namespace std;

/*
Đầu tiên shell sort sắp xếp chọn trên các phần tử có khoảng cách xa nhau,
sau đó sắp xếp các phần tử có khoảng cách hẹp hơn(khoảng cách giảm dần),
Khoảng cách này còn được gọi là gap – là khoảng chênh lệch số vị trí từ phần tử này tới phần tử khác
*/

void shellSort(int arr[], int n) 
{
	// Bắt đầu với gap lớn, sau đó giảm dần 
	for (int gap = n/2; gap > 0; gap /= 2)
	{
		// Mục tiêu vòng for này : arr[x] < arr[x + gap] (với mọi x < n-gap) 
		for (int i = gap; i < n; ++i) 
		{ 
			// Thêm a[i] vào các phần tử đã được sắp xếp (các phần tử cách nhau gap)
			// Lưu arr[i] vào biến temp và tạo một khoảng trống ở vị trí arr[i]
			int temp = arr[i];

			// Lấy các phần tử được sắp xếp (các phần tử cách nhau gap) trước đó lên so sánh cho đến khi tìm thấy vị trí chính xác cho arr[i] 
			int j;
			for (j = i; j >= gap && temp < arr[j - gap]; j -= gap)
				arr[j] = arr[j - gap];

			// Đặt temp(arr[i] gốc) vào đúng vị trí của nó
			arr[j] = temp;
		}
	}
}

int main() 
{ 
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	shellSort(arr, n); 

	cout << "\nArray after sorting: "; 
	for (auto &&i : arr)
		cout << i << " ";
	

	return 0; 
}
/*
            G - - - - >
	9 8 7 6 5 4 3 2 1
	1 4 3 2 5 8 7 6 9
	1 2 3 4 5 6 7 8 9
	1 2 3 4 5 6 7 8 9
 */