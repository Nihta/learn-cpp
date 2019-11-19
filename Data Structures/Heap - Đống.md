# Cấu trúc dữ liệu Heap

## Heap

Cấu trúc dữ liệu Heap là một trường hợp đặc biệt của cấu trúc dữ liệu cây nhị phân cân bằng, trong đó khóa của nút gốc được so sánh với các con của nó và được sắp xếp một cách phù hợp. Nếu α có nút con β thì:

`key(α) ≥ key(β)`

Khi giá trị của nút cha lớn hơn giá trị của nút con, thì thuộc tính này tạo ra một Max Heap. Dựa trên tiêu chí này, một Heap có thể là một trong hai kiểu sau:

`Với dữ liệu đầu vào → 35 33 42 10 14 19 27 44 26 31`

* **Min-Heap**: ở đây giá trị của nút gốc là nhỏ hơn hoặc bằng các giá trị của các nút con.

![Min Heap](img/min-heap.jpg)

* **Max-Heap**: ở đây giá trị của nút gốc là lớn hơn hoặc bằng giá trị của các nút con.

![Max Heap](img/max-heap.jpg)

## Giải thuật xây dựng Max Heap

Chúng ta sẽ suy ra một giải thuật cho Max Heap bằng việc chèn một phần tử tại một thời điểm. Tại bất cứ thời điểm nào, Heap đều phải duy trì (tuân theo) thuộc tính của nó. Trong quá trình chèn, chúng ta cũng giả sử rằng chúng ta đang chèn một nút vào trong HEAPIFIED Tree.

**Bước 1**: Tạo một nút mới tại vị trí cuối cùng của Heap.

**Bước 2**: Gán giá trị mới cho nút này.

**Bước 3**: So sánh giá trị của nút con với giá trị cha.

**Bước 4**: Nếu giá trị của cha là nhỏ hơn con thì tráo đổi chúng.

**Bước 5**: Lặp lại bước 3 và 4 cho tới khi vẫn duy trì thuộc tính của Heap.

**Ghi chú**: Trong giải thuật xây dựng Min Heap, giá trị của nút cha sẽ là nhỏ hơn giá trị của các nút con.

![Max Heap](img/max-heap1.gif)

## Giải thuật xóa trong Max Heap

Hoạt động xóa trong Max (hoặc Min) Heap luôn luôn diễn ra tại nút gốc và để xóa giá trị Lớn nhất (hoặc Nhỏ nhất).

**Bước 1**: Xóa nút gốc.

**Bước 2**: Di chuyển phần tử cuối cùng có bậc thấp nhất lên nút gốc.

**Bước 3**: So sánh giá trị của nút con này với giá trị của cha.

**Bước 4**: Nếu giá trị của cha là nhỏ hơn của con thì **tráo đổi** chúng.

**Bước 5**: Lặp lại bước 3 và 4 cho tới khi vẫn duy trì thuộc tính của Heap.

![Max Heap](img/max-heap2.gif)
