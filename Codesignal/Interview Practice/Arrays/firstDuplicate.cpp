/**
 * Cho 1 mảng: 1 ≤ a.length ≤ 100000, 1 ≤ a[i] ≤ a.length
 * Tìm số trùng lặp đầu tiên mà lần xuất hiện thứ hai có chỉ số tối thiểu
 * Nếu không có phần tử nào return -1
 * Ví dụ:
 *   	a = [2, 1, 3, 5, 3, 2]
 * 	    firstDuplicate(a) = 3
 * Lưu ú O(n^2) sẽ bị time limit
*/
#include <iostream>
#include <vector>
using namespace std;

int firstDuplicate(vector<int> v)
{
	// Duyệt qua số nào chuyển số đó thành số âm
	// Tìm thấy số âm tức là nó đã xuất hiện trước đó
	// Lưu ý: v[k] âm có nghĩa là k đã xuất hiện trước đó không phải v[k]
	for (int k : v)
	{
		if (v[abs(k) - 1] < 0)
			return abs(k);
		v[abs(k) - 1] *= -1;
	}
	return -1;
}

int firstDuplicate2(std::vector<int> v)
{
	int seen[100000] = {0};
	for (int n : v)
	{
		if (seen[n])
			return n;
		seen[n] = 1;
	}
	return -1;
}

int main()
{
	vector<int> v = {2, 1, 3, 5, 3, 2, 5, 6, 7, 8, 9}; // 3
	cout << firstDuplicate(v) << endl;
	cout << firstDuplicate2(v) << endl;
	return 0;
}
