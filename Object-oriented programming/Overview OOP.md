# Tổng quan về lập tình hướng đối tượng

## Lập trình hướng đối tượng trong C++

Lập trình hướng đối tượng (Object Oriented Programming - OOP) là một mô hình sử dụng lớp (class) và đối tượng (object) trong chương trình hay nói cách khác là mô hình hóa chương trình chúng ta bằng những lớp, đối tượng.

Những khái niệm là chúng ta cần phải biết trong lập trình hướng đối tượng đó là:

* Lớp (Class)
* Đối tượng (Object)
* Thừa kế (Inheritance)
* Đa hình (Polymorphism)
* Trừu tượng (Abstraction)
* Đóng gói (Encapsulation)

## Object

Một thực thể có trạng thái và hành vi thì được gọi như là một đối tượng. Ví dụ đối tượng là những gì chúng ta có thể nhìn thấy và sờ được trong thực tế như: cái bàn, cây viết, chiếc xe, con mèo, ...

Cụ thể là đối tượng chiếc xe sẽ có các trạng thái có thể như sau:

* Màu
* Chiều dài
* Chiều rộng
* Chiều cao
* Trọng lượng
* Nhà sản xuất

Và có các hành vi có thể như sau:

* Chạy
* Đổ xăng
* Phanh

Tùy vào ngữ cảnh của chương trình mà chúng ta phân tích trạng thái và hành vi cho phù hợp, chúng ta chỉ lấy những trạng thái và hành vi mà chúng ta cần quan tâm tới trong chương trình của chúng ta, không cần phải lấy hết tất cả trạng thái và hành vi của đối tượng có thể có.

Ví dụ cùng là đối tượng con người trong môi trường trường học sẽ có trạng thái cần quan tâm như là MSSV, tên, lớp, điểm rèn luyện, điểm học tập, ... và có hành vi cần quan tâm như học, tham gia hoạt động ngoại khóa, thi cuộc thi học sinh giỏi, ...

Và cũng là con người đó trong môi trường cuộc thi hoa hậu sẽ có trạng thái cần quan tâm như như tên, tuổi, chiều cao, cân nặng, dân tộc, ... và hành vi cần quan tâm như ứng xử, nói tiếng anh, trình diễn thời trang, ...

Trong C++, Object là một thực thể trong thế giới thực, ví dụ: ghế, xe hơi, bút, điện thoại di động, máy tính xách tay, v.v. Hay nói cách khác, đối tượng là một thực thể có trạng thái và hành vi. Ở đây, trạng thái có nghĩa là dữ liệu và hành vi có nghĩa là hàm. Đối tượng là một thực thể runtime, bởi vì nó được tạo ra trong runtime. Đối tượng là một thể hiện của một lớp. Tất cả các thành viên của lớp có thể được truy cập thông qua đối tượng.

## Class

Tập hợp các đối tượng có điểm tương đồng thì được gọi đó là lớp (class), hay còn có thể nói lớp là khuôn mẫu để tạo ra đối tượng. Đối tượng là một thể hiện của lớp.

Ví dụ chúng ta có lớp học sinh, từng đối tượng của lớp học sinh là từng học sinh cụ thể như Nguyễn Văn A, Nguyễn Văn B, Nguyễn Văn C, ... Lớp động vật, các đối tượng của lớp động vật đó là con mèo, con chó, con heo, ...

Trong C++, lớp là một nhóm các đối tượng tương tự. Lớp là một mẫu mà từ đó các đối tượng được tạo ra. Lớp có thể có các trường (fields), các phương thức (methods), các hàm xây dựng (constructors ), ...

## Inheritance

Một đối tượng có tất cả trạng thái và hành vi của đối tượng cha thì được gọi là thừa kế.

## Polymorphism

Khi cùng một nhiệm vụ mà thực hiện nhiều cách khác nhau thì được gọi là đa hình.

Ví dụ chúng ta có nhiệm vụ kêu của động vật nhưng con chó thì kêu gâu gâu, con mèo thì kêu meo meo, con heo thì kêu ọc ọc...

Trong C++, sử dụng overloading và overriding để thực hiện tính đa hình.

## Abstraction

Ẩn đi các chi tiết bên trong và chỉ hiển thị các chức năng bên ngoài thì được gọi là trừu tượng.

Ví dụ cuộc gọi điện thoại, chúng ta không hề biết bên trong nó xữ lý thể nào để chúng ta có thể nói chuyện được với nhau, chúng ta chỉ biết chức năng bên ngoài của nó là có thể nói chuyện được với nhau.

Trong C++ sử dụng lớp trừu tượng và interface để thực hiện tính trừu tượng.

## Encapsulation

Gói dữ liệu và thông tin thành một đơn vị được gọi là đóng gói.

Ví dụ trong một công ty có các phòng ban như kế toán, lập trình, nhân sự thì những phòng ban chỉ có thể truy cập các phòng ban khác thông qua một cách thức được public sẳn cho các phòng ban khác truy cập.

Trong C++ sử dụng access modifiers để thực hiện tính đóng gói.

## Ưu điểm

Ưu điểm của lập trình hướng đối tượng so với lập trình hướng thủ tục như sau:

OOP làm cho việc phát triển và bảo trì dễ dàng hơn, trong khi ngôn ngữ lập trình hướng thủ tục, không dễ quản lý nếu dự án lớn và code ngày càng nhiều.

OOP ẩn dữ liệu đi, trong khi ngôn ngữ lập trình hướng thủ tục, dữ liệu toàn cục có thể được truy cập từ bất cứ đâu.

OOP cung cấp khả năng mô phỏng sự kiện trong thế giới thực hiệu quả hơn nhiều, chúng ta có thể giải quyết nhiều vấn đề từ thực tế nếu chúng ta sử dụng ngôn ngữ lập trình hướng đối tượng.
