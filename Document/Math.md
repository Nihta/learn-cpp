# Math Function

## Hàm toán học (Math Function) trong C++

Trong C++ cung cấp một số hàm toán học cơ bản và chúng ta phải include `<math.h>` thì mới có thể sử dụng các hàm toán học được.

Trong C++ có hổ trợ các loại toán học sau:

* Trignometric functions
* Hyperbolic functions
* Exponential functions
* Floating point manipulation functions
* Maximum,Minimum and Difference functions
* Power functions
* Nearest integer operations
* Other functions
* Macro functions
* Comparison macro functions
* Error and gamma functions

## Trignometric functions

|Hàm|Mô tả|
|---|-----|
`cos(x)`|Dùng để tính cosin của x. Giá trị trả về trong phạm vi [-1, 1]
`sin(x)`|Dùng để tính sin của x. Giá trị trả về trong phạm vi [-1, 1]
`tan(x)`|Dùng để tính tan của x.
`acos(x)`|Dùng để tìm cosin nghịch đảo (acos(x) = cos-1x) của x. Giá trị trả về trong phạm vi (0,∏) nếu -1≤x≤1, không phải một số (nan) nếu x<-1 hoặc x>1
`asin(x)`|Dùng để tìm sin nghịch đảo (asin(x) = sin-1x) của x.  Giá trị trả về là -∏/2,∏/2 nếu -1≤x≤1, không phải là số (nan) nếu x<-1 hoặc x>1
`atan(x)`|Dùng để tìm tan nghịch đảo (atan(x) = tan-1x) của x. Giá trị trả về trong phạm vi [-∏/2, ∏/2]
`atan2(x,y`)|Dùng để tìm tan nghịch đảo của tọa độ x và y.

## Hyperbolic functions

|Hàm|Mô tả|
|---|-----|
`cosh(x)`|Dùng để tính cos hyperbolic của x.
`sinh(x)`|Dùng để tính sin hyperbolic của x.
`tanh(x)`|Dùng để tính tang hyperbolic của x.
`acosh(x)`|Dùng để tìm nghịch đảo cos hyperbolic của x.
`asinh(x)`|Dùng để tìm nghịch đảo sin hyperbolic của x.
`atanh(x)`|Dùng để tìm nghịch đảo tang hyperbolic của x.

## Nearest integer operations

|Hàm|Mô tả|
|---|-----|
`ceil(x)`|Dùng để làm tròn lên giá trị của x.
`floor(x)`|Dùng để làm tròn xuống giá trị của x.
`round(x)`|Dùng để làm tròn giá trị của x.
`lround(x)`|Dùng để làm tròn giá trị của x và chuyển thành số nguyên long.
`llround(x)`|Dùng để làm tròn giá trị của x và chuyển thành số nguyên long long.
`fmod(n,d)`|Dùng để lấy phần dư của phép chia n cho d
`trunc(x)`|Dùng để làm tròn xuống không chữ số thập phân
`rint(x)`|Dùng để làm tròn giá trị của x bằng rounding mode
`lrint(x)`|Dùng để làm trong giá trị của x bằng roungding mode và chuyển đổi thành số nguyên long.
`llrint(x)`|Dùng để làm tròn giá trị x và chuyển thành số nguyên long long
`nearbyint(x)`|Dùng để làm tròn giá trị x thành giá trị tích phân gần đó
`remainder(n,d)`|Dùng để tính phần còn lại của n/d.
`remquo()`|Dùng để tính toán phần còn lại và thương.

## Other functions

|Hàm|Mô tả|
|---|-----|
`fabs(x)`|Dùng để tính giá trị tuyệt đối của x.
`abs(x)`|Dùng để tính giá trị tuyệt đối của x.
`fma(x,y,z)`|Dùng để tính biểu thức x * y + z.

## Macro functions

|Hàm|Mô tả|
|---|-----|
`fpclassify(x)`|Dùng để trả về giá trị của loại khớp với một trong các hằng số macro.
`isfinite(x)`|Dùng để kiểm tra xem x có hữu hạn hay không.
`isinf(x)`|Dùng để kiểm tra xem x là vô hạn hay không.
`isnan(x)`|Dùng để kiểm tra xem x có phải là nan hay không.
`isnormal(x)`|Dùng để kiểm tra xem x có bình thường hay không.
`signbit(x)`|Dùng để kiểm tra xem dấu của x có âm hay không.

## Comparison macro functions

|Hàm|Mô tả|
|---|-----|
`isgreater(x,y)`|Dùng để xác định xem x có lớn hơn y hay không.
`isgreaterequal(x,y)`|Dùng để xác định xem x có lớn hơn hoặc bằng y hay không.
`less(x,y)`|Dùng để xác định xem x có nhỏ hơn y hay không.
`islessequal(x,y)`|Dùng để xác định xem x nhỏ hơn hoặc bằng y.
`islessgreater(x,y)`|Dùng để xác định xem x nhỏ hơn hay lớn hơn y hay không.
`isunordered(x,y)`|Dùng để kiểm tra xem x có thể được so sánh một cách có ý nghĩa hay không.

## Error and gamma functions

|Hàm|Mô tả|
|---|-----|
`erf(x)`|Dùng để tính giá trị hàm lỗi của x.
`erfc(x)`|Dùng để tính giá trị hàm lỗi bổ sung của x.
`tgamma(x)`|Dùng để tính giá trị hàm gamma của x.
`lgamma(x)`|Dùng để tính toán logarit của hàm gamma của x.
