/* 
    Quick Sort O(nlogn) - Sắp xếp nhanh
    Xem thông tin về các thuật toán sắp xếp: https://visualgo.net/en/sorting
    https://youtu.be/PgBzjlCcFvc

Giải thuật sắp xếp nhanh chia mảng thành hai phần bằng cách so sánh từng phần tử của mảng với một phần tử được chọn gọi là phần tử chốt (Pivot): một mảng bao gồm các phần tử nhỏ hơn hoặc bằng pivot và mảng còn lại bao gồm các phần tử lớn hơn hoặc bằng pivot
Tiến trình chia này diễn ra tiếp tục cho tới khi độ dài của các mảng con đều bằng 1
Giải thuật sắp xếp nhanh tỏ ra khá hiệu quả với các tập dữ liệu lớn khi mà độ phức tạp trường hợp trung bình và trường hợp xấu nhất là O(nlogn)
*/

#include<iostream>
using namespace std;

void swap(int* a, int* b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}

/*
    Thuật toán phân đoạn - partition

Cho một mảng và một phần tử x là pivot (high):
    Đặt x vào đúng vị trí của mảng đã sắp xếp
    Di chuyển tất cả các phần tử của mảng mà nhỏ hơn x sang bên trái x,
    Di chuyển tất cả các phần tử của mảng mà lớn hơn x sang bên phải x
*/
int partition(int arr[], int low, int high)
{
    // Đặt pivot là phần tử cuối cùng của arr[]
    int pivot = arr[high];

    // Chúng ta bắt đầu từ phần tử trái nhất của dãy số có chỉ số là left,
    // và phần tử phải nhất của dãy số right-1 (bỏ qua phần tử pivot)
    int left = low;
    int right = high - 1;

    // Xem Qick-sort-1.gif
    while(true)
    {
        // Tìm phần tử arr[left] >= arr[pivot]
        while(left <= right && arr[left] < pivot)
            left++;

        // Tìm phần tử <= arr[pivot]
        while(left <= right && pivot < arr[right])
            right--;

        // Khi left >= right thì duyệt xong
        if (left >= right)
            break;

        // Hoán đổi 2 phần tử left và right thỏa mãn
        swap(&arr[left], &arr[right]);

        // Tăng left và right lên 1 do chúng vừa được hoán đổi trước đó
        ++left, --right;
    }

    // Đổi chỗ phần tử left cho phần tử pivot
    swap(&arr[left], &arr[high]);

    // Trả về chỉ số sẽ dùng để chia đôi mảng (pivot)
    return left;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        // Đệ quy để sắp xếp 2 phần, phần tử pivot lúc này đã nằm đúng vị trí
        quickSort(arr, low, pivot - 1);  
        quickSort(arr, pivot + 1, high);  
    }
}

int main()  
{  
    int arr[] = {10, 7, 8, 9, 1, 2, 4, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (auto &&i : arr)
        cout << i << " ";

    return 0;  
}