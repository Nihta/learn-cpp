# Cấu trúc dữ liệu mảng

## Mảng

Mảng (Array) là một trong các cấu trúc dữ liệu cũ và quan trọng nhất. Mảng có thể lưu giữ một số phần tử cố định và các phần tử này nền có cùng kiểu. Hầu hết các cấu trúc dữ liệu đều sử dụng mảng để triển khai giải thuật. Dưới đây là các khái niệm quan trọng liên quan tới Mảng.

* **Phần tử**: Mỗi mục được lưu giữ trong một mảng được gọi là một phần tử.
* **Chỉ mục (Index)**: Mỗi vị trí của một phần tử trong một mảng có một chỉ mục số được sử dụng để nhận diện phần tử.

Mảng gồm các bản ghi có kiểu giống nhau, có kích thước cố định, mỗi phần tử được xác định bởi chỉ số

Mảng là cấu trúc dữ liệu được cấp phát liên tục cơ bản

### Ưu điểm của mảng

* Truy câp phàn tử vơi thời gian hằng số O(1)
* Sử dụng bộ nhớ hiệu quả
* Tính cục bộ về bộ nhớ

### Nhược điểm

* Không thể thay đổi kích thước của mảng khi chương trình dang thực hiện

## Mảng động

* **Mảng động (dynamic aray)**: cấp phát bộ nhớ cho mảng một cách động trong quá trình chạy chương trình trong C là malloc và calloc, trong C++ là new. Sử dụng mảng động ta bắt đầu với mảng có 1 phần tử, khi số lượng phần tử vượt qua khả năng của mảng thì ta gấp đôi kích thước mảng cũ và copy phàn tử mảng cũ vào nửa đầu của mảng mới

**Ưu điểm**:

* Tránh lãng phí bộ nhớ khi phải khai báo mảng có kích thước lớn ngay từ đầu

**Nhược điểm**:

* Phải thực hiện thêm thao tác copy phần tử mỗi khi thay đổi kích thước.
* Một số thời gian thực hiện thao tác không còn là hằng số nữa.

## Một số điểm cần ghi nhớ về cấu trúc dữ liệu mảng

* Chỉ mục(index) bắt đầu với 0.
* Độ dài mảng là 10, nghĩa là mảng có thể lưu giữ 10 phần tử.
* Mỗi phần tử đều có thể được truy cập thông qua chỉ mục của phần tử đó.

## Phép toán cơ bản được hỗ trợ bởi mảng

* **Duyệt**: In tất cả các phần tử mảng theo cách in từng phần tử một.
* **Chèn**: Thêm một phần tử vào mảng tại chỉ mục đã cho.
* **Xóa**: Xóa một phần tử từ mảng tại chỉ mục đã cho.
* **Tìm kiếm**: Tìm kiếm một phần tử bởi sử dụng chỉ mục hay bởi giá trị.
* **Cập nhật**: Cập nhật giá trị một phần tử tại chỉ mục nào đó.
