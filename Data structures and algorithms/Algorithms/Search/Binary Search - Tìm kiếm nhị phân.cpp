// Binary Search O(Log n) - Tìm kiếm nhị phân
// Input cần phải được sắp xếp
// https://youtu.be/T2sFYY-fT5o
#include <iostream>
using namespace std;

int binary_search(int arr[],int l,int r,int key)
{
	while(l <= r)
	{
		// Giống (l+r)/2
		int middle = l+(r-l)/2;
		
		if(key == arr[middle])
			return middle;
			
		else if(key < arr[middle])
			r = middle - 1;

		else if(key > arr[middle])
			l = middle + 1;
	}
	return -1;
}

int main()
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int key = 5;

	int res = binary_search(arr, 0, n-1, key);

	if(res != -1)
		cout << key << " found at index " << res << endl;
	else
		cout << key << "Not found!" << endl;
	return 0;
}