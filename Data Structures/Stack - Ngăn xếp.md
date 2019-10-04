# Cấu trúc dữ liệu ngăn xếp (Stack)

## Ngăn xếp (Stack)

Một ngăn xếp là một cấu trúc dữ liệu trừu tượng (`Abstract Data Type` – viết tắt là `ADT`), hầu như được sử dụng trong hầu hết mọi ngôn ngữ lập trình. Đặt tên là ngăn xếp bởi vì nó hoạt động như một ngăn xếp trong đời sống thực, ví dụ như một cỗ bài hay một chồng đĩa, …

Trong đời sống thực, ngăn xếp chỉ cho phép các hoạt động tại vị trí trên cùng của ngăn xếp. Ví dụ, chúng ta chỉ có thể đặt hoặc thêm một lá bài hay một cái đĩa vào trên cùng của ngăn xếp. Do đó, cấu trúc dữ liệu trừu tượng ngăn xếp chỉ cho phép các thao tác dữ liệu tại vị trí trên cùng. Tại bất cứ thời điểm nào, chúng ta chỉ có thể truy cập phần tử trên cùng của ngăn xếp.

Đặc điểm này làm cho ngăn xếp trở thành cấu trúc dữ liệu dạng **LIFO**. **LIFO** là viết tắt của Last-In-First-Out. Ở đây, phần tử được đặt vào (được chèn, được thêm vào) cuối cùng sẽ được truy cập đầu tiên. Trong thuật ngữ ngăn xếp, hoạt động chèn được gọi là hoạt động PUSH và hoạt động xóa được gọi là hoạt động POP.

## Biểu diễn cấu trúc dữ liệu ngăn xếp (Stack)

![Stack](img/stack1.jpg)

Một ngăn xếp có thể được triển khai theo phương thức của Mảng (Array), Cấu trúc (Struct), Con trỏ (Pointer) và Danh sách liên kết (Linked List). Ngăn xếp có thể là ở dạng kích cỡ cố định hoặc ngăn xếp có thể thay đổi kích cỡ. Phần dưới chúng ta sẽ triển khai ngăn xếp bởi sử dụng các mảng với việc triển khai các ngăn xếp cố định.

## Các hoạt động cơ bản trên cấu trúc dữ liệu ngăn xếp

Các hoạt động cơ bản trên ngăn xếp có thể liên quan tới việc khởi tạo ngăn xếp, sử dụng nó và sau đó xóa nó. Ngoài các hoạt động cơ bản này, một ngăn xếp có hai hoạt động nguyên sơ liên quan tới khái niệm, đó là:

* **Hoạt động push()**: lưu giữ một phần tử trên ngăn xếp.
* **Hoạt động pop()**: xóa một phần tử từ ngăn xếp.

Khi dữ liệu đã được PUSH lên trên ngăn xếp:

Để sử dụng ngăn xếp một cách hiệu quả, chúng ta cũng cần kiểm tra trạng thái của ngăn xếp. Để phục vụ cho mục đích này, dưới đây là một số tính năng hỗ trợ khác của ngăn xếp:

* **Hoạt động peek()**: lấy phần tử dữ liệu ở trên cùng của ngăn xếp, mà không xóa phần tử này.
* **Hoạt động isFull()**: kiểm tra xem ngăn xếp đã đầy hay chưa.
* **Hoạt động isEmpty()**: kiểm tra xem ngăn xếp là trống hay không.
* **Hoạt động PUSH()**: đặt (thêm) một phần tử dữ liệu mới vào trên ngăn xếp.
* **Hoạt động POP()**: truy cập nội dung phần tử và xóa nó từ ngăn xếp.

Tại mọi thời điểm, chúng ta duy trì một con trỏ tới phần tử dữ liệu vừa được PUSH cuối cùng vào trên ngăn xếp. Vì con trỏ này luôn biểu diễn vị trí trên cùng của ngăn xếp vì thế được đặt tên là top. Con trỏ top cung cấp cho chúng ta giá trị của phần tử trên cùng của ngăn xếp mà không cần phải thực hiện hoạt động xóa ở trên (hoạt động pop).

## Ứng dụng của ngăn xếp

* Xử lý gọi hàm trong C/C++
* Trong máy tính, sử dụng để tính giá trị biểu thức, xử lý ngắt
* Trong các chương trình biên dịch
* Trong trình duyệt web, trình soạn thảo văn bản
* Định giá biểu thức:
  * Biểu thức trung tố: toán tử hai ngôi đứng giữa hai toán hạng, toán tử một ngôi đứng trước toán hạng
  * Biểu thức hậu tố : toán tử đứng sau toán hạng
  * Biểu thức tiền tố : toán tử đứng trước toán hạng

VD: Định giá biểu thức: `A = b + c * d /e – f`:

* Trung tố `a*(b-c)/d`
* Hậu tố `abc-*d/`
* Tiền tố `/*a-bcd`

**Duyệt biểu thức hậu tố** :

* Gặp toán hạng : đẩy vào stack
* Gặp toán tử 1 ngôi : lấy ra 1 toán hạng trong stack, áp dụng toán tử lên toán hạng và đấy kết quả trở lại stack
* Gặp toán tử 2 ngôi :lấy 2 toán hạng ở đỉnh stack theo thứ tự, áp dụng toán tử lên 2 toán hạng đó, kết quả lại đẩy vào stack
* Kết thúc, đưa ra kết quả là giá trị ở đỉnh stack
* Vd định giá biểu thức hậu tố

**Chuyển biểu thức dạng trung tố sang hậu tố**:

* Duyệt lần lượt biểu thưc trung tố từ trái qua phải
* Gặp toán hạng : viết sang biểu thức kết quả
* Gặp toán tử có độ ưu tiên nhỏ hơn 6
  * Nếu stack rỗng hoặc đỉnh stack là toán tử có độ ưu tiên nhỏ hơn hoặc là '(' đẩy toán tử đang xét vào stack
  * Ngược lại : lấy các toán tử ở đỉnh stack có độ ưu tiên lớn hơn hoặc bằng toán tử đang xét lần lượt đưa vào biểu thức kết quả và đẩy toán tử đang xét vào stack
* Gặp toán tử có độ ưu tiên 6 hoặc '(' thì đẩy vào stack
* Gặp ')' lấy tất cả các toán tử trong stack cho đến khi gặp '(' đầu tiên, đưa sang biểu thức kết quả theo đúng thứ tự và đẩy 1 kí hiệu '(' ra khỏi stack
* Nếu duyệt hết biểu thức trung tố, lấy nốt những toán tử trong stack đưa sang biểu thức kết quả theo đúng thứ tự
