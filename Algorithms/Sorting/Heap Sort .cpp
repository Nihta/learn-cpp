/*
    Heap sort O(nLogn) - Sắp xếp vun đống
    https://youtu.be/MtQL_ll5KhQ

Thuật toán sắp xếp vun đống:
    1. Xây dựng một đống tối đa từ dữ liệu đầu vào.
    2. Tại thời điểm này, phần tử lớn nhất (largest) được lưu trữ ở gốc (root) của heap.
       Thay thế nó bằng phần tử cuối cùng của heap, sau đó giảm heap size đi 1.
       Cuối cùng, heapify đống (với gốc mới và size heap giảm đi 1).
    3. Lặp lại các bước trên trong khi size heap > 1.
*/
#include <iostream>
using namespace std;

/*
Hàm Heapify sẽ kiểm tra nút trái, nút phải và nút ngay tại gốc (root) để tìm ra nút có giá trị lớn nhất.
Trong trường hợp nút có giá trị lớn nhất không phải nút ở vị trí gốc (root),
hàm sẽ đổi giá trị 2 nút này và tiếp tục đệ quy Heapify từ vị trí nút có giá trị lớn nhất
để đi đến các nhánh tiếp theo để đảm bảo nút cha sẽ luôn có giá trị lớn hơn các nút con
 */
void heapify(int arr[], int n, int root)
{
    // Giả định nút có giá trị lớn nhất (largest) là root
    int largest = root;

    // Vị trí nút trái, phải ngay dưới gốc
    int leftNode = 2*root + 1;
    int rightNode = 2*root + 2;

    // Nếu nút trái lớn hơn root
    if (leftNode < n && arr[leftNode] > arr[largest]) 
        largest = leftNode;

    // Nếu nút phải lớn hơn root
    if (rightNode < n && arr[rightNode] > arr[largest]) 
        largest = rightNode; 
  
    // Nếu phần tử lớn nhất không nằm ở gốc
    if (largest != root) 
    {
        // Hoán đổi phần tử lớn nhất lên gốc
        swap(arr[root], arr[largest]);

        // Đệ quy lấy phần tử root ban đầu nay đã nằm ở vị trí của nút trái hoặc phải làm gốc
        // để kiểm tra các nút nằm dưới nó xem có còn thỏa mãn các nút con luôn nhỏ hơn nút cha nữa hay không
        heapify(arr, n, largest); 
    }
}

void heapSort(int arr[], int n) 
{
    /*
    Tạo heap từ input thỏa mãn các tính chất cần thiết bằng hàm Heapify:
        Nút cha sẽ luôn lớn hơn tất cả các nút con, nút gốc của heap sẽ là phần tử lớn nhất.
        Heap được tạo thành phải là một cây nhị phân đầy đủ, tức ngoại trừ các nút lá, ở cùng một cấp độ các nút nhánh không được thiếu.

    Vòng for tạo ngược cây từ lá lên gốc (từ gốc xuống hàm Heapify sẽ không thể hoạt động đúng)
    */
    for (int root = n/2 - 1; root >= 0; --root)
        heapify(arr, n, root);

    // Sau mỗi vòng lặp sẽ có thêm 1 phần tử đúng vị trí trong mảng đã sắp xếp
    // ...9    ...89    ...789    ...6789    ...56789    ...456789
    for (int heapSize = n-1; heapSize >= 0; --heapSize) 
    {
        /*
        Tráo đổi vị trí root và phần tử cuối heap:
            Phần tử root sẽ về đúng vị trí khi mảng được sắp xếp
            Phần tử cuối heap trở thành gốc mới
        */
        swap(arr[0], arr[heapSize]); 
  
        // Xếp lại đống (gốc mới) để đảm bảo trong heap mới nút cha sẽ luôn có giá trị lớn hơn các nút con
        heapify(arr, heapSize, 0); 
    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
  
    heapSort(arr, n); 
  
    cout << "Sorted array is: ";
    for (auto &&i : arr)
        cout << i << " ";
    return 0;
}