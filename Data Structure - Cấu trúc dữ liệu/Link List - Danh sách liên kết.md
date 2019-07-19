# Cấu trúc dữ liệu danh sách liên kết (Linked List)

## Danh sách liên kết (Linked List)

Một Danh sách liên kết (Linked List) là một dãy các cấu trúc dữ liệu được kết nối với nhau thông qua các liên kết (link). Hiểu một cách đơn giản thì Danh sách liên kết là một cấu trúc dữ liệu bao gồm một nhóm các nút (node) tạo thành một chuỗi. Mỗi nút gồm dữ liệu ở nút đó và tham chiếu đến nút kế tiếp trong chuỗi.
Danh sách liên kết là cấu trúc dữ liệu được sử dụng phổ biến thứ hai sau mảng. Dưới đây là các khái niệm cơ bản liên quan tới danh sách liên kết:

* **Link (liên kết)**: mỗi link của một danh sách liên kết có thể lưu giữ một dữ liệu được gọi là một phần tử.
* **Next**: Mỗi liên kết của một danh sách liên kết chứa một link tới next link được gọi là Next.
* **First**: một danh sách liên kết bao gồm các link kết nối tới first link được gọi là First.

## Biểu diễn Danh sách liên kết (Linked List)

Danh sách liên kết có thể được biểu diễn như là một chuỗi các nút (node). Mỗi nút sẽ trỏ tới nút kế tiếp.
Một số điểm cần nhớ về danh sách liên kết:

* Danh sách liên kết chứa một phần tử link thì được gọi là First.
* Mỗi link mang một trường dữ liệu và một trường link được gọi là Next.
* Mỗi link được liên kết với link kế tiếp bởi sử dụng link kế tiếp của nó.
Link cuối cùng mang một link là null để đánh dấu điểm cuối của danh sách.

## Các loại Danh sách liên kết (Linked List)

* Danh sách liên kết đơn (Simple Linked List): chỉ duyệt các phần tử theo chiều về trước.
* Danh sách liên kết đôi (Doubly Linked List): các phần tử có thể được duyệt theo chiều về trước hoặc về sau.
* Danh sách liên kết vòng (Circular Linked List): phần tử cuối cùng chứa link của phần tử đầu tiên như là next và phần tử đầu tiên có link tới phần tử cuối cùng như là prev.

## Các hoạt động cơ bản trên Danh sách liên kết

* **Hoạt động chèn**: thêm một phần tử vào cuối danh sách liên kết.
* **Hoạt động xóa (phần tử đầu)**: xóa một phần tử tại đầu danh sách liên kết.
* **Hiển thị**: hiển thị toàn bộ danh sách.
* **Hoạt động tìm kiếm**: tìm kiếm phần tử bởi sử dụng khóa (key) đã cung cấp.
* **Hoạt động xóa (bởi sử dụng khóa)**: xóa một phần tử bởi sử dụng khóa (key) đã cung cấp.

## Danh sách liên kết đôi (Doubly Linked List)

Danh sách liên kết đôi (Doubly Linked List) là một biến thể của Danh sách liên kết (Linked List), trong đó hoạt động duyệt qua các nút có thể được thực hiện theo hai chiều: về trước và về sau một cách dễ dàng khi so sánh với Danh sách liên kết đơn. Dưới đây là một số khái niệm quan trọng cần ghi nhớ về Danh sách liên kết đôi.

* **Link**: mỗi link của một Danh sách liên kết có thể lưu giữ một dữ liệu và được gọi là một phần tử.
* **Next**: mỗi link của một Danh sách liên kết có thể chứa một link tới next link và được gọi là Next.
* **Prev**: mỗi link của một Danh sách liên kết có thể chứa một link tới previous * link và được gọi là Prev.
* **First và Last**: một Danh sách liên kết chứa link kết nối tới first link được gọi là First và tới last link được gọi là Last.

### Các hoạt động cơ bản trên Danh sách liên kết đôi

* **Hoạt động chèn**: thêm một phần tử vào vị trí đầu của Danh sách liên kết.
* **Hoạt động chèn vào sau**: thêm một phần tử vào sau một phần tử của Danh sách liên kết.
* **Hoạt động xóa (bởi key)**: xóa một phần tử từ Danh sách liên kết bởi sử dụng khóa đã cung cấp.
* **Hiển thị danh sách về phía trước**: hiển thị toàn bộ Danh sách liên kết theo chiều về phía trước.
* **Hiển thị danh sách về phía sau**: hiển thị toàn bộ Danh sách liên kết theo chiều về phía sau.

## Danh sách liên kết vòng (Circular Linked List)

Danh sách liên kết vòng (Circular Linked List) là một biến thể của danh sách liên kết (Linked List), trong đó phần tử đầu tiên trỏ tới phần tử cuối cùng và phần tử cuối cùng trỏ tới phần tử đầu tiên.

Cả hai loại Danh sách liên kết đơn (Singly Linked List) và Danh sách liên kết đôi (Doubly Linked List) đều có thể được tạo thành dạng Danh sách liên kết vòng.
