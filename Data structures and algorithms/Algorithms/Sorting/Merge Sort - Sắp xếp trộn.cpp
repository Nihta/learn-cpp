/*
    Merge Sort - Sắp xếp trộn
    https://youtu.be/JSceec-wEyw

Merge sort là một thuật toán chia để trị:
    Thuật toán này chia mảng cần sắp xếp thành 2 nửa
    Tiếp tục lặp lại việc chia này ở các nửa mảng đã chia (đệ quy)

    Sau cùng gộp các nửa đó thành mảng đã sắp xếp.
    Hàm merge() được sử dụng để gộp hai nửa mảng.
    Hàm merge(arr, l, middle, r) là tiến trình quan trọng nhất sẽ gộp hai nửa mảng thành 1 mảng được sắp xếp - các nửa mảng là arr[l…middle] và arr[middle+1…r] sau khi gộp sẽ thành một mảng duy nhất đã sắp xếp tăng dần.
*/

#include<iostream>
using namespace std;

// Hàm gộp hai mảng con tăng arr[l...middle] và arr[middle+1..r]
// thành mảng tăng arr[l..r]
void merge(int arr[], int l, int middle, int r)
{
    int arr1Size = middle - l + 1;
    int arr2Size =  r - middle;
 
    // Tạo các mảng tạm L[l...middle], R[middle+1..r]
    int L[arr1Size], R[arr2Size];

    // Copy dữ liệu từ arr[l...r] sang 2 mảng tạm L, R
    for (int i = 0; i < arr1Size; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < arr2Size; j++)
        R[j] = arr[middle + 1+ j];


    // Các dòng phía dưới tương đương với task trộn 2 mảng tăng
    // thành một mảng tăng duy nhất

    // Khởi tạo chỉ số bắt đầu của mảng lưu kết quả( arr[l...r] )
    int k = l;

    // So sánh lần lượt các phần tử trên 2 mảng với nhau phần tử nào nhỏ hơn
    // thì cho vào mảng kết quả. Phần tử đã cho vào mảng kết quả trước đó thì
    // không xét nữa
    int i = 0, j = 0;
    while (i < arr1Size && j < arr2Size)
        arr[k++] = ( L[i] <= R[j] )? L[i++] : R[j++];

    // TH mảng R hết phần tử
    while (i < arr1Size)
        arr[k++] = L[i++];

    // TH mảng L hết phần tử
    while (j < arr2Size)
        arr[k++] = R[j++];
}





// l là chỉ số trái và r là chỉ số phải của mảng cần được sắp xếp
void mergeSort(int arr[], int l, int r)
{
    if (l < r) 
    {
        // Tìm chỉ số nằm giữa mảng để chia mảng thành 2 nửa
        int middle = l+(r-l)/2; // Giống như(l+r)/2
  
        // Gọi đệ quy hàm mergeSort cho nửa đầu tiên
        mergeSort(arr, l, middle);
        // Gọi đệ quy hàm mergeSort cho nửa thứ hai
        mergeSort(arr, middle+1, r);

        // Gộp 2 nửa mảng đã sắp xếp ở  trên
        merge(arr, l, middle, r); 

        /*
            Với trường hợp khi 2 mảng con chỉ có 1 phần tử,
            ta chỉ việc xem phần tử nào nhỏ hơn và đẩy lên đầu,
            phần tử còn lại đặt phía sau.
            Do vậy, các mảng con cần gộp lại luôn được sắp tăng dần.
         */

    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 

    mergeSort(arr, 0, arr_size - 1); 

    cout << "Sorted array is: "; 
    for (auto &&i : arr)
        cout << i << " ";
    return 0; 
}