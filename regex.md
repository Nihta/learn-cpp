# Regular Expression (Biểu thức chính quy)

## 1 Regular Expression

Regular Expression (hay còn gọi là biểu thức chính quy, RegEx, RegExp,…) là một chuỗi miêu tả một bộ các chuỗi khác, theo những quy tắc cú pháp nhất định. Ta có thể sử dụng regex để tìm kiếm, so sánh, cắt ghép,… chuỗi dựa trên các mẫu văn bản (pattern).

## 2 Các kí tự đặc biệt thường gặp

* `.` : đại diện cho bất kì kí tự nào ngoại trừ \
* `[abc]`: khớp với 1 kí tự trong nhóm kí tự a, b hoặc c
* `[a-z]`: khớp với 1 kí tự trong vùng từ a-z, ngăn cách bằng dấu –
* `[^abc]`: khớp với 1 kí tự ngoại trừ nhóm kí tự a, b và c
* `\d`: kí tự chữ số tương đương [0-9]
* `\D`: kí tự không phải chữ số
* `\s`: kí tự khoảng trắng (space)
* `\S`: kí tự không phải khoảng trắng
* `\w`: kí tự word (gồm chữ cái, chữ số và dấu _), tương đương [a-zA-Z0-9_]
* `\W`: tương đương [^a-zA-Z0-9_]
* `^`: bắt đầu 1 chuỗi hay 1 dòng
* `$`: kết thúc 1 chuỗi hay 1 dòng
* `\`: biểu diễn 1 kí tự đặc biệt trong regex thành kí tự thường (ví dụ `\.` sẽ khớp với dấu chấm, nếu thiếu `\` sẽ hiểu nhầm là kí tự đại diện `.` phía trên)
* `|`: kí tự tương đương phép or (sử dụng nhiều trong cặp móc tròn)
* `()`: khớp với 1 nhóm các kí tự (ví dụ Ste(v|ph)en sẽ khớp với Steven hoặc Stephen)
* `?`: khớp với kí tự đứng trước 0 – 1 lần (ví dụ S?even sẽ khớp Seven hoặc even)
* `\*`: khớp với kí tự đứng trước từ 0 lần trở lên (ví dụ Te*n sẽ khớp Tn, Ten, Teen, Teeen, Teeeen,…)
* `+`: khớp với kí tự đứng trước từ 1 lần trở lên (ví dụ Te+n sẽ khớp Ten, Teen, Teeen,…)
* `{<n>}`: khớp đúng với \<n> kí tự trước đó (ví dụ Te{2}n sẽ khớp Teen)
* `{<n>,}`: khớp với \<n> kí tự trước đó trở lên (ví dụ Te{2,}n sẽ khớp Teen, Teeen, Teeeen,…)
* `{<n>, <m>}`: khớp từ \<n> đến \<m> kí tự trước đó (ví dụ Te{1,3}n sẽ khớp Ten, Teen, Teeen,…)

## 3 Ví dụ

* Kiểm tra MAC-48 (IEEE 802)

```c++
string inputString = "00-12-34-99-AB-AE";
regex re("^([0-9a-fA-F]{2}[-]){5}([0-9a-fA-F]{2})$");
cout << boolalpha << regex_match(inputString ,re);
```

* Kiểm tra IPv4: 255.255.255.255

```c++
regex re("((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])");
```
