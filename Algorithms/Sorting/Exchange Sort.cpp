// Exchange Sort - Sắp xếp kiểu đổi chỗ trực tiếp
#include <iostream>
using namespace std;

void exchangeSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                std::swap(arr[i], arr[j]);
}

int main()
{
    int arr[] = {2, 1, 3, 4, 7, 6, 5, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    exchangeSort(arr, n);

    for (auto &&i : arr)
        cout << i << " ";

    return 0;
}
