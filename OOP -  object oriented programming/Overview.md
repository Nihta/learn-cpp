# Tổng quan về lập tình hướng đối tượng

## Overview

Lập trình hướng đối tượng (Object Oriented Programming - OOP) là một mô hình sử dụng lớp (class) và đối tượng (object) trong chương trình hay nói cách khác là mô hình hóa chương trình chúng ta bằng những lớp, đối tượng.

Những khái niệm là chúng ta cần phải biết trong lập trình hướng đối tượng đó là:

- [Lớp (Class)](#class)
- [Đối tượng (Object)](#Object)
- [Thừa kế (Inheritance)](#Inheritance)
- [Đa hình (Polymorphism)](#Polymorphism)
- [Trừu tượng (Abstraction)](#Abstraction)
- [Đóng gói (Encapsulation)](#Encapsulation)

## Object

Một thực thể có thuộc tính và phương thức thì được gọi như là một đối tượng. Ví dụ đối tượng là những gì chúng ta có thể nhìn thấy và sờ được trong thực tế như: cái bàn, cây bút, con chó, chiếc xe, ...

Cụ thể là đối tượng chiếc xe sẽ có các thuộc tính:

- Màu
- Chiều dài
- Chiều rộng
- Chiều cao
- Trọng lượng
- Nhà sản xuất

Và có các phương thức:

- Chạy
- Đổ xăng
- Phanh

Tùy vào ngữ cảnh của chương trình mà chúng ta phân tích thuộc tính và phương thức cho phù hợp, chúng ta chỉ lấy những thuộc tính và phương thức mà chúng ta cần quan tâm tới trong chương trình của chúng ta, không cần phải lấy hết tất cả thuộc tính và phương thức của đối tượng có thể có.

Ví dụ cùng là đối tượng con người trong môi trường trường học sẽ có thuộc tính cần quan tâm như là MSSV, tên, lớp, điểm rèn luyện, điểm học tập, ... và có phương thức cần quan tâm như học, tham gia hoạt động ngoại khóa, thi cuộc thi học sinh giỏi, ...

Và cũng là con người đó trong môi trường cuộc thi hoa hậu sẽ có thuộc tính cần quan tâm như như tên, tuổi, chiều cao, cân nặng, dân tộc, ... và phương thức cần quan tâm như ứng xử, nói tiếng anh, trình diễn thời trang, ...

Trong C++ Object là một thực thể có thuộc tính và phương thức. Ở đây, thuộc tính có nghĩa là dữ liệu và phương thức có nghĩa là hàm. Đối tượng là một thực thể runtime, bởi vì nó được tạo ra trong runtime. Đối tượng là một thể hiện của một lớp. Tất cả các thành viên của lớp có thể được truy cập thông qua đối tượng.

## Class

Tập hợp các đối tượng có điểm tương đồng thì được gọi đó là lớp (class), hay còn có thể nói lớp là khuôn mẫu để tạo ra đối tượng. Đối tượng là một thể hiện của lớp.

Ví dụ:

- Các đối tượng của lớp học sinh là từng học sinh cụ thể như: Nguyễn Văn A, Nguyễn Văn B, Nguyễn Văn C, ...
- Các đối tượng của lớp động vật đó là con chó, con mèo, con chuột, ...

Trong C++ class là một nhóm các đối tượng tương tự. Class là một mẫu mà từ đó các đối tượng được tạo ra. Class có thể có các trường (fields), các phương thức (methods), các hàm xây dựng (constructors), ...

## Inheritance

Một tính năng then chốt của lập trình hướng đối tượng đó là tính kế thừa.

Tính kế thừa cho phép một lớp có thể dẫn xuất từ một lớp khác, chính vì thế chúng sẽ tự động tiếp nhận các thành viên của bố mẹ và bổ sung thêm các thành viên của riêng chúng.

Tính kế thừa cho phép lớp mới có thể nhận được mọi dữ liệu thành viên (private, protected, public) và các hàm thành viên (trừ hàm tạo, hàm hủy, hàm bạn và hàm toán tử gán `=`).

## Polymorphism

Tính đa hình là tính chất thể hiện nhiều hình thái của đối tượng.

Các đối tượng khác nhau có thể có cùng phương thức thực thi  một hành động. Nhưng mỗi đối tượng lại thực thi hành động  theo cách riêng của mình, mà không giống nhau cho tất cả các đối tượng.

Ví dụ: Phương thức kêu của động vật như con chó thì kêu gâu gâu, con mèo thì kêu meo meo, ...

Trong C++, sử dụng overloading và overriding để thực hiện tính đa hình.

## Abstraction

Tính trừu tượng hóa là tính chất chỉ tập trung vào những  phần cốt lõi của đối tượng, bỏ qua những tiểu tiết không  cần thiết.

Nó còn thể hiện ở lớp trừu tượng cơ sở: lớp trừu tượng cơ sở chứa các đặc tính chung, tổng quát cho một nhóm đối tượng. Khi đó, nhóm đối tượng sẽ thừa kế từ lớp trừu tượng này để nhận các thuộc tính chung, đồng thời bổ sung thêm tính năng mới.

Khi phân tích một nhóm đối tượng, ta thường tìm ra các điểm chung, đặc trưng cho các đối tượng rồi từ đó xây dựng nên một lớp trừu tượng cơ sở để chứa các phương thức tác động đến các đặc trưng chung đó. Mỗi một đối tượng trong nhóm đối tượng trên khi thừa  kế từ lớp trừu tượng cơ sở sẽ có phương thức đặc trưng cho nhóm đối tượng này.

## Encapsulation

Tính đóng gói là tính chất không cho phép người dùng hay đối tượng khác thay đổi dữ liệu thành viên của đối tượng nội tại.

Chỉ có các hàm thành viên của đối tượng đó mới có quyền thay đổi trạng thái nội tại của nó mà thôi.

Các đối tượng khác muốn thay đổi thuộc tính thành viên của đối tượng nội tại, thì chúng cần truyền thông điệp cho đối tượng, và việc quyết định thay đổi hay không vẫn do đối tượng nội tại quyết định.

Trong C++ sử dụng access modifiers để thực hiện tính đóng gói.

## Ưu điểm của lập trình hướng đối tượng

Ưu điểm của lập trình hướng đối tượng so với lập trình hướng thủ tục như sau:

- OOP làm cho việc phát triển và bảo trì dễ dàng hơn, trong khi ngôn ngữ lập trình hướng thủ tục, không dễ quản lý nếu dự án lớn và code ngày càng nhiều.

- OOP ẩn dữ liệu đi, trong khi ngôn ngữ lập trình hướng thủ tục dữ liệu toàn cục có thể được truy cập từ bất cứ đâu.

- OOP cung cấp khả năng mô phỏng sự kiện trong thế giới thực hiệu quả hơn nhiều, chúng ta có thể giải quyết nhiều vấn đề từ thực tế nếu chúng ta sử dụng ngôn ngữ lập trình hướng đối tượng.
