/*
    Tính diệtích đa giác.
    Hình minh họa shapeArea.png 
*/
#include <iostream>
using namespace std;

int shapeArea(int n) {
    if (n == 1) return 1;
    return shapeArea(n-1) + n*4-4;
}

int shapeArea2(int n) { 
    return (1 + (n-1) * n) * 2 - 1;
}
int main() {
    cout << "Result: " << shapeArea(3) << endl;
    cout << "Result: " << shapeArea2(3) << endl;
    return 0;
}
