# Cấu trúc dữ liệu hàng đợi (Queue)

## Hàng đợi (Queue)

Hàng đợi (Queue) là một cấu trúc dữ liệu trừu tượng, là một cái gì đó tương tự như hàng đợi trong đời sống hàng ngày (xếp hàng).

![Hàng đợi](img/queue.jpg)
Khác với ngăn xếp, hàng đợi là mở ở cả hai đầu. Một đầu luôn luôn được sử dụng để chèn dữ liệu vào (hay còn gọi là sắp vào hàng) và đầu kia được sử dụng để xóa dữ liệu (rời hàng). Cấu trúc dữ liệu hàng đợi tuân theo phương pháp `FIFO` (First-In-First-Out) tức là dữ liệu được nhập vào đầu tiên sẽ được truy cập đầu tiên.

Trong đời sống thực chúng ta có rất nhiều ví dụ về hàng đợi, chẳng hạn như hàng xe ô tô trên đường một chiều (đặc biệt là khi tắc xe), trong đó xe nào vào đầu tiên sẽ thoát ra đầu tiên. Một vài ví dụ khác là xếp hàng học sinh, xếp hàng mua vé, …

## Biểu diễn cấu trúc hàng đợi

Tương tự như cấu trúc dữ liệu ngăn xếp, thì cấu trúc dữ liệu hàng đợi cũng có thể được triển khai bởi sử dụng Mảng (Array), Danh sách liên kết (Linked List), Con trỏ (Pointer) và Cấu trúc (Struct).

## Các hoạt động cơ bản trên cấu trúc dữ liệu hàng đợi

Các hoạt động trên cấu trúc dữ liệu hàng đợi có thể liên quan tới việc khởi tạo hàng đợi, sử dụng dữ liệu trên hàng đợi và sau đó là xóa dữ liệu khỏi bộ nhớ. Danh sách dưới đây là một số hoạt động cơ bản có thể thực hiện trên cấu trúc dữ liệu hàng đợi:

* **Hoạt động enqueue()**: thêm (hay lưu trữ) một phần tử vào trong hàng đợi.
* **Hoạt động dequeue()**: xóa một phần tử từ hàng đợi.

Để sử dụng hàng đợi một cách hiệu quả, chúng ta cũng cần kiểm tra trạng thái của hàng đợi. Để phục vụ cho mục đích này, dưới đây là một số tính năng hỗ trợ khác của hàng đợi:

* **Phương thức peek()**: lấy phần tử ở đầu hàng đợi, mà không xóa phần tử này.
* **Phương thức isFull()**: kiểm tra xem hàng đợi là đầy hay không.
* **Phương thức isEmpty()**: kiểm tra xem hàng đợi là trống hay hay không.
Trong cấu trúc dữ liệu hàng đợi, chúng ta luôn luôn: (1) dequeue (xóa) dữ liệu được trỏ bởi con trỏ **front** và (2) enqueue (nhập) dữ liệu vào trong hàng đợi bởi sự giúp đỡ của con trỏ **rear**.
