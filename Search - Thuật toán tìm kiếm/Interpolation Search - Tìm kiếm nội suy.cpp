// Interpolation Search O(log log n) - Tìm kiếm nội suy
// Là cải tiến của Binary Search
// Yều cầu input là mảng đã được sắp xếp
#include<iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int key)
{ 
	// Khởi tạo vị trí ban đầu của low và hight
	int lo = 0, hi = (n - 1);

	// Vì mảng được sắp xếp, một phần tử có mặt trong mảng phải nằm trong phạm vi được xác định bởi góc(lo, hi)
	while (lo <= hi && arr[lo] <= key && key <= arr[hi])
	{
		if (lo == hi)
		{
			if (arr[lo] == key)
				return lo;
			return -1;
		}

		// Phương thức để chia mảng thành 2 phần
		//Ở Binary Search là pos = (lo + hi)/2
		int pos = lo + (hi - lo) * (key - arr[lo]) / (arr[hi] - arr[lo]);

		// Nếu key nằm đúng tại vị trí pos
		if (arr[pos] == key)
			return pos;
		// Nếu key lớn hơn, key nằm ở phần sau
		if (arr[pos] < key)
			lo = pos + 1;
		// Nếu key nhỏ hơn, key ở phần trước
		else
			hi = pos - 1;
	}
	return -1;
}

int main()
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof(arr)/sizeof(arr[0]); 
	int key = 8;

	int index = interpolationSearch(arr, n, key);


	if (index != -1) 
		cout << "Element found at index " << index;
	else
		cout << "Element not found.";
	return 0;
}