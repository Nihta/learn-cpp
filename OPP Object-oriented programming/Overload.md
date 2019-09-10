# Nạp chồng

## Overview

**Các toán tử có thể được nạp chồng**:

| | | | | | |
|-|-|-|-|-|-|
+|-|*|/|%|^
&|\||~|!|,|=
<|>|<=|>=|++|--
<<|>>|==|!=|&&|||
+=|-=|/=|%=|^=|&=
|=|*=|<<=|>>=|[]|()
->|->*|new|new []|delete|delete []

**Các toán tử không thể được nạp chồng**:

| | | | |
|-|-|-|-|
::|.*|.|? :

|Dạng toán tử|Phương thức của lớp|Hàm toàn cục|
|--|--|--|
aa@bb|aa.operator@(bb)|operator@(aa,bb)
@aa|aa.operator@()|operator@(aa)
aa@|aa.operator@(int)|operator@(aa,int)

## Details

* [Toán tử một ngôi](#Nạp-chồng-toán-tử-đơn)
* [Toán tử đôi](#Nạp-chồng-toán-tử-đôi)
* [Toán tử quan hệ](#Nạp-chồng-toán-tử-quan-hệ)
* [Toán tử input/output](#Nạp-chồng-toán-tử-input/output)
* [Toán tử ++ và --](#Nạp-chồng-toán-tử-++-và---)
* [Toán tự gán](#Nạp-chồng-toán-tự-gán)
* [Toán tử gọi hàm ()](#Nạp-chồng-toán-tử-gọi-hàm-())
* [Toán tử []](#Nạp-chồng-toán-tử-[])
* [Toán tử truy cập thành viên lớp ->](#Nạp-chồng-toán-tử-truy-cập-thành-viên-lớp-`->`)

## Nạp chồng toán tử đơn

Toán tử một ngôi (unary) trong c++ hoạt động trên một toán hạng đơn:

* Nạp chồng toán tử tăng `++` và toán tử giảm `--`
* Toán tử một ngôi `-`
* Toán tử logic phủ định `!`

Toán tử một ngôi hoạt động trên đối tượng mà chúng được gọi, và thường thì toán tử này xuất hiện bên trái đối tượng, dạng như: `!obj`, `-obj`, và `++obj`, nhưng đôi khi chúng có thể sử dụng như là hậu tố giống như `obj++` hoặc `obj--`.

Ví dụ sau giải thích cách toán tử`-` có thể được nạp chồng với sự sử dụng tiền tố cũng như hậu tố.

```cpp
#include <iostream>
using namespace std;

class KhoangCach {
   private:
        int met;
        int centimet;
   public:
        // constructor
        KhoangCach() {
            met = 0;
            centimet = 0;
        }
        KhoangCach(int m, int c) {
            met = m;
            centimet = c;
        }

        // Phương thức hiện thị khoảng cách
        void hienthiKC() {
            cout << "Khoang cach bang m la: " << met << endl;
            cout << "Khoang cach bang cm la: " << centimet << endl;
        }

        // Nạp chồng toán tử -
        KhoangCach operator-() {
            met = -met;
            centimet = -centimet;
            return KhoangCach(met, centimet);
        }
};

int main() {
    KhoangCach K1(20, 6), K2(-6, 15);

    -K1;
    K1.hienthiKC();

    -K2;
    K2.hienthiKC();

    return 0;
}
```

[TOP^](#!)

-----

## Nạp chồng toán tử đôi

* Toán tử cộng `+`, trừ `-`, nhân `*` toán tử chia `/`.

Ví dụ sau giải thích cách toán tử cộng `+` có thể được nạp chồng trong C++.

```cpp
#include <iostream>
using namespace std;

class Box {
    private:
        double chieudai;
        double chieurong;
        double chieucao;
    public:
        double tinhTheTich() {
            return chieudai * chieurong * chieucao;
        }

        void setChieuDai(double dai) {
            chieudai = dai;
        }

        void setChieuRong(double rong) {
            chieurong = rong;
        }

        void setChieuCao(double cao) {
            chieucao = cao;
        }

        // Nạp chồng toán tử cộng
        Box operator+(const Box& b) {
            Box box;
            box.chieudai = this->chieudai + b.chieudai;
            box.chieurong = this->chieurong + b.chieurong;
            box.chieucao = this->chieucao + b.chieucao;
            return box;
        }
};

int main() {
    Box Box1, Box2, Box3;
    double thetich;

    Box1.setChieuDai(3.0);
    Box1.setChieuRong(4.0);
    Box1.setChieuCao(5.0);

    Box2.setChieuDai(6.0);
    Box2.setChieuRong(7.0);
    Box2.setChieuCao(8.0);

    thetich = Box1.tinhTheTich();
    cout << "The tich cua Box1 : " << thetich <<endl;

    thetich = Box2.tinhTheTich();
    cout << "The tich cua Box2 : " << thetich <<endl;

    Box3 = Box1 + Box2;

    thetich = Box3.tinhTheTich();
    cout << "The tich cua Box3 : " << thetich <<endl;

    return 0;
}
```

-----

[TOP^](#!)

## Nạp chồng toán tử quan hệ

Có nhiều toán tử quan hệ như `<`, `>`, `<=`, `>=`, `==`, ...

Bạn có thể nạp chồng bất kỳ toán tử quan hệ nào, mà có thể được sử dụng để so sánh các đối tượng của một lớp.

```cpp
#include <iostream>
using namespace std;

class KhoangCach {
   private:
        int met;
        int centimet;
   public:
        KhoangCach() {
                met = 0;
                centimet = 0;
            }
        KhoangCach(int m, int c) {
                met = m;
                centimet = c;
        }

        bool operator<(const KhoangCach& k) {
            if (this->met < k.met)
                return true;
            if (this->met == k.met && this->centimet < k.centimet)
                return true;
            return false;
        }
};

int main() {
   KhoangCach K1(23, 15), K2(17, 46);

   if( K1 < K2 )
        cout << "K1 la ngan hon K2 " << endl;
   else
        cout << "K2 la ngan hon K1 " << endl;

   return 0;
}
```

-----

[TOP^](#!)

## Nạp chồng toán tử input/output

C++ có thể input và output các kiểu dữ liệu có sẵn bởi sử dụng toán tử trích luồng >> và toán tử chèn luồng <<. Các toán tử trích luồng và chèn luồng cũng có thể được nạp chồng để thực hiện input và output cho các kiểu tự định nghĩa (user-defined).

Ở đây, nó là quan trọng để tạo một hàm nạp chồng toán tử một friend của lớp, bởi vì nó sẽ được gọi mà không tạo một đối tượng.

```cpp
#include <iostream>
using namespace std;

class KhoangCach {
    private:
        int met;
        int centimet;
    public:
        KhoangCach() {
            met = 0;
            centimet = 0;
        }
        KhoangCach(int m, int c) {
            met = m;
            centimet = c;
        }

        friend ostream &operator<<(ostream &output, const KhoangCach &K) {
            output << "\nDo dai bang m la: " << K.met << "\nVa do dai bang cm la: " << K.centimet;
            return output;
        }

        friend istream &operator>>(istream &input, KhoangCach &K) {
            input >> K.met >> K.centimet;
            return input;
        }
};

int main() {
    KhoangCach K1(23, 14), K2(14, 35), K3;

    cout << "Nhap gia tri cua doi tuong K3: ";
    cin >> K3;

    cout << "Khoang cach dau tien: " << K1 << endl;

    cout << "Khoang cach thu hai: " << K2 << endl;

    cout << "Khoang cach thu ba: " << K3 << endl;

    return 0;
}
```

-----

[TOP^](#!)

## Nạp chồng toán tử ++ và --

```cpp
#include <iostream>
using namespace std;

class ThoiGian {
    private:
        int gio;
        int phut;
    public:
        // constructor
        ThoiGian() {
            gio = 0;
            phut = 0;
        }
        ThoiGian(int h, int m) {
            gio = h;
            phut = m;
        }

        void hienthiTG() {
            cout << "Gio: " << gio << " Phut: " << phut << endl;
        }

        // Nạp chồng toán tử ++ (tiền tố)
        ThoiGian operator++() {
            ++phut;
            if(phut >= 60) {
                ++gio;
                phut -= 60;
            }
            return ThoiGian(gio, phut);
        }

        // Nạp chồng toán tử ++ (hậu tố)
        ThoiGian operator++(int) {
            // Lưu giá trị ban đầu
            ThoiGian T(gio, phut);
            // Tăng đối tượng này
            ++phut;
            if (phut >= 60) {
                ++gio;
                phut -= 60;
            }
            // Trả về giá trị trước khi tăng
            return T;
        }
};

int main() {
    ThoiGian T1(6, 59), T2(19,24);
    ++T1;
    T1.hienthiTG();

    ++T1;
    T1.hienthiTG();

    T2++;
    T2.hienthiTG();

    T2++;
    T2.hienthiTG();
    return 0;
}
```

-----

[TOP^](#!)

## Nạp chồng toán tự gán

Bạn có thể nạp chồng toán tử gán `=` như khi bạn có thể với các toán tử khác trong C++ và nó có thể được sử dụng để tạo một đối tượng giống như copy constructor.

```cpp
#include <iostream>
using namespace std;

class KhoangCach {
    private:
        int met;
        int centimet;
    public:
        // constructor
        KhoangCach() {
            met = 0;
            centimet = 0;
        }

        KhoangCach(int m, int c) {
            met = m;
            centimet = c;
        }

        void operator=(const KhoangCach &K) {
            met = K.met;
            centimet = K.centimet;
        }

        void hienthiKC() {
            cout << "\nDo dai bang m la: " << met << "\nVa do dai bang cm la: " <<  centimet << endl;
        }
};

int main() {
    KhoangCach K1(2, 113), K2(1, 69);

    cout << "Khoang cach dau tien: ";
    K1.hienthiKC();

    cout << "Khoang cach thu hai:";
    K2.hienthiKC();

    K1 = K2;

    cout << "Khoang cach dau tien: ";
    K1.hienthiKC();

    return 0;
}
```

-----

## Nạp chồng toán tử gọi hàm ()

Toán tử gọi hàm `()` trong C++ có thể được nạp chồng cho các đối tượng của kiểu lớp. Khi bạn nạp chồng `()`, bạn đang không tạo một cách mới để gọi một hàm. Đúng hơn là, bạn đang tạo một hàm toán tử mà có thể được truyền số tham số tùy ý.

```cpp
#include <iostream>
using namespace std;

class KhoangCach {
    private:
        int met;
        int centimet;
    public:
        // constructor
        KhoangCach() {
            met = 0;
            centimet = 0;
        }
        KhoangCach(int m, int c) {
            met = m;
            centimet = c;
        }

        // Nạp chồng toán tử gọi hàm
        KhoangCach operator()(int x, int y, int z) {
            KhoangCach K;

            K.met = x + y + 5;
            K.centimet = y - z + 20 ;
            return K;
        }

        void hienthiKC() {
            cout << "\nDo dai bang m la: " << met <<  "\nVa do dai bang cm la: " <<  centimet << endl;
        }
};

int main() {
    KhoangCach K1(24, 36), K2;

    cout << "Khoang cach dau tien la: ";
    K1.hienthiKC();

    K2 = K1(15, 15, 15);

    cout << "Khoang cach thu hai la: ";
    K2.hienthiKC();

    return 0;
}
```

-----

[TOP^](#!)

## Nạp chồng toán tử []

Toán tử subscript [] trong C++ thường được sử dụng để truy cập các phần tử mảng. Toán tử này có thể được nạp chồng để nâng cao tính năng đang tồn tại về mảng trong C++ (do vậy, có thể gọi là toán tử chỉ số mảng).

```cpp
#include <iostream>
using namespace std;
const int MAX = 15;

class ViDuMang {
    private:
        int mang[MAX];
    public:
        ViDuMang() {
            register int i;
            for(i = 0; i < MAX; i++)
                mang[i] = i;
        }

        int &operator[](int i) {
            if(i > MAX) {
                cout << "Chi muc vuot gioi han!" <<endl;
                // Tra ve phan tu dau tien.
                return mang[0];
            }
            return mang[i];
        }
};

int main() {
    ViDuMang V;

    cout << "Gia tri cua V[3] la: " << V[3] <<endl;
    cout << "Gia tri cua V[6] la: " << V[6]<<endl;
    cout << "Gia tri cua V[16] la: " << V[16]<<endl;

    return 0;
}
```

-----

[TOP^](#!)

## Nạp chồng toán tử truy cập thành viên lớp `->`

Toán tử truy cập thành viên lớp `->` có thể được nạp chồng, nhưng nó khá là phức tạp. Nó được định nghĩa để cung cấp một kiểu lớp một hành vi "pointer-like". Toán tử `->` phải là một hàm thành viên. Nếu được sử dụng, kiểu trả về của nó phải là một con trỏ hoặc một đối tượng của một lớp để bạn có thể áp dụng.

Toán tử `->` thường được sử dụng kết hợp với toán tử `*` để triển khai "smart pointer". Những con trỏ này là các đối tượng mà vận hành như các con trỏ thông thường, ngoại trừ việc chúng thực hiện các tác vụ khi bạn truy cập một đối tượng thông qua chúng, ví dụ: xóa đối tượng tự động hoặc khi con trỏ bị hủy hoặc khi con trỏ được sử dụng để trỏ tới đối tượng khác.

Toán tử -> có thể được định nghĩa như là một toán tử hậu tố một ngôi.

```cpp
class Ptr {
   //...
   X * operator->();
};
```

Các đối tượng của lớp `Ptr` có thể được sử dụng để truy cập các thành viên của lớp `X` ở trên theo phương thức giống như cách các con trỏ được sử dụng. Ví dụ:

```cpp
void f(Ptr p ) {
   p->m = 10 ; // la tuong tu (p.operator->())->m = 10
}
```

Lệnh `p->m` được thông dịch thành `(p.operator->())->m`. Sử dụng cùng khái niệm trên, ví dụ sau sẽ giải thích cách một toán tử truy cập lớp `->` trong C++ có thể được nạp chồng.

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Nihta {
    static int i, j;
    public:
        // Các smart pointer để hiện thị
        void f() const { cout << i++ << endl; }
        void g() const { cout << j++ << endl; }
        void h() const { cout << "--------" << endl; }
        };

        // Phần định nghĩa các thành viên Static:
        int Nihta::i = 4;
        int Nihta::j = 15;

        // Triển khai một container cho lớp trên
        class NiContainer {
            vector<Nihta*> a;
            public:
                void add(Nihta* vj) {
                    a.push_back(vj);
                }
            friend class SmartPointer;
        };

        // Triển khai smart pointer để truy cập thành viên của lớp Nihta.
        class SmartPointer {
            NiContainer vc;
            int index;
            public:
                SmartPointer(NiContainer& nic) {
                    vc = nic;
                    index = 0;
                }
                // Trả về giá trị để chỉ phần cuối của danh sách:
                bool operator++() {
                    if(index >= vc.a.size()) return false;
                    if(vc.a[++index] == 0) return false;
                    return true;
                }

                bool operator++(int) {
                    return operator++();
                }

                // Nạp chồng operator->
                Nihta* operator->() const {
                    if (!vc.a[index]) {
                        cout << "Gia tri 0!!";
                        return (Nihta*)0;
                    }
                    return vc.a[index];
                }
};

int main() {
    const int sz = 5;
    Nihta o[sz];
    NiContainer vc;

    for (int i = 0; i < sz; i++)
        vc.add(&o[i]);

    SmartPointer sp(vc); // Tạo một iterator
    do {
        sp->f(); // Gọi smart pointer
        sp->g();
        sp->h();
    } while(sp++);

    return 0;
}
```

[TOP^](#!)
