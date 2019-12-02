/**
 * Tìm phần tử lớn thứ k trong mảng
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kthLargestElement(std::vector<int> nums, int k)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

int kthLargestElement2(std::vector<int> nums, int k)
{
    /**
     * std::nth_element() là một thuật toán STL sắp xếp lại danh sách theo cách
     * sao cho phần tử ở vị trí thứ n là vị trí của nó đó nếu chúng ta sắp xếp.
     * Nó không sắp xếp danh sách, chỉ là tất cả các phần tử trước phần tử thứ n
     * không lớn hơn nó và tất cả các phần tử sau phần tử n không nhỏ hơn nó.
    */
    std::nth_element(nums.begin(), nums.end() - k, nums.end());
    return nums[nums.size() - k];
}

int main()
{
    cout << kthLargestElement({7, 6, 5, 3, 4, 1, 2}, 2) << endl;  // 6
    cout << kthLargestElement2({7, 6, 5, 3, 4, 1, 2}, 2) << endl; // 6
    return 0;
}
