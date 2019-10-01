
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct ps
{
   int ts;
   int ms;
};

typedef ps ps;

// Rút gọn
ps rutGon(ps p) {
   int ucln = __gcd(p.ts, p.ms);
   p.ms /= ucln;
   p.ts /= ucln;
   return p;
}

// Hàm hhởi tạo phân số
ps taoPs(int a, int b) {
    ps tmp;
    tmp.ts = a;
    tmp.ms = b;
    return rutGon(tmp);
}

// Nhập phân số (dạng "a/b")
istream& operator>> (istream& is,ps &a)
{
   char tmp;
   is >> a.ts >> tmp >> a.ms ;
   return is;
}

// In phân số
ostream& operator<< (ostream& os, ps a)
{
   os << a.ts << '/' << a.ms;
   return os;
}

// Cộng phân số
ps operator+ (ps a, ps b) {
    return taoPs(a.ts * b.ms + b.ts * a.ms, a.ms * b.ms);
}

// Trừ phân số
ps operator- (ps a, ps b) {
    return taoPs(a.ts * b.ms - b.ts * a.ms, a.ms * b.ms);
}

// Nhân phân số
ps operator* (ps a, ps b) {
    return taoPs(a.ts * b.ts, a.ms * b.ms);
}

// Chia phân số
ps operator/ (ps a, ps b) {
    return taoPs(a.ts * b.ms, b.ts * a.ms);
}

// Đảo dấu
ps operator- (ps &a) {
    a = a * taoPs(-1, -1);
    return a;
}


// +=
ps operator+= (ps &a, ps b) {
    a = a + b;
    return a;
}

// -=
ps operator-= (ps &a, ps b) {
    a = a - b;
    return a;
}

// *=
ps operator*= (ps &a, ps b) {
    a = a * b;
    return a;
}

// /=
ps operator/= (ps &a, ps b) {
    a = a/ b;
    return a;
}


// >
bool operator> (ps a, ps b) {
    return a.ts * b.ms > a.ms * b.ts;
}
// <
bool operator< (ps a, ps b) {
    return a.ts * b.ms < a.ms * b.ts;
}
// >=
bool operator>= (ps a, ps b) {
    return a.ts * b.ms >= a.ms * b.ts;
}
// <=
bool operator<= (ps a, ps b) {
    return a.ts * b.ms <= a.ms * b.ts;
}
// ==
bool operator== (ps a, ps b) {
    return a.ts * b.ms == a.ms * b.ts;
}
// !=
bool operator!= (ps a, ps b) {
    return a.ts * b.ms != a.ms * b.ts;
}



// ++ Tiền tố
ps operator++ (ps &a) {
    a = a + taoPs(1, 1);
    return a;
}

// ++ Hậu tố
ps operator++ (ps &a, int) {
    ps res = a;
    ++a;
    return res;
}

// -- Tiền tố
ps operator-- (ps &a) {
    a = a - taoPs(1, 1);
    return a;
}

// -- Hậu tố
ps operator-- (ps &a, int) {
    ps res = a;
    --a;
    return res;
}


// ......................

int main() {
   // ............

   return 0;
}
