/*
    Cho 1 mảng: 1 ≤ a.length ≤ 100000, 1 ≤ a[i] ≤ a.length
    Tìm số trùng lặp đầu tiên mà lần xuất hiện thứ hai có chỉ số tối thiểu
    Nếu không có phần tử nào return -1
    Ví dụ:
        a = [2, 1, 3, 5, 3, 2]
        firstDuplicate(a) = 3
    https://app.codesignal.com/interview-practice/task/pMvymcahZ8dY4g75q
 */
#include <iostream>
#include <vector>
using namespace std;

int firstDuplicate(std::vector<int> v) {
	// Duyệt qua số nào chuyển số đó thành số âm
	// Tìm thấy số âm tức là nó đã xuất hiện trước đó
	// Fun này dùng số âm, dương giống như fun dưới dùng 1, 0 nhưng ít bộ nhớ hơn
    for(auto &&k : v) {
        if(v[abs(k)-1] < 0) 
            return abs(k);
        v[abs(k)-1] *= -1;
    }
    return -1;
}

int firstDuplicate2(std::vector<int> v)
{
	// Mảng seen toàn phần tử không
	int seen[v.size()] = {0};

	for (auto &&n : v)
	{
		// seen[n] = 1 nghĩa là phần tử n trong v đã xuất hiện 1 lần trước đó
		if(seen[n] == 1)
			return n;
		// Gán bằng 1 đánh đấu phần tử n trong v đã xuất hiện 1 lần
		seen[n] = 1;
	}
	return -1;
}

int main() {
	vector<int> v = {2, 1, 3, 5, 3, 2}; // 3
	cout << firstDuplicate(v) << endl;
	cout << firstDuplicate2(v) << endl;
	return 0;
}