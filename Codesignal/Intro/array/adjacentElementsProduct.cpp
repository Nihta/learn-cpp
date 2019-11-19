//  Cho một mảng các số nguyên, tìm cặp phần tử liền kề có tích lớn nhất và trả về tích đó.
#include <iostream>
#include <vector>
using namespace std;

//  Mảng >= 2 phần tử
int adjacentElementsProduct(std::vector<int> inputArray) {
    int result = inputArray[0] * inputArray[1];
    for (int i = 1; i < inputArray.size() - 1; i++) {
        int temp = inputArray[i] * inputArray[i+1];
        if (temp > result) result = temp; 
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 9 ,10 ,3 ,2 ,1};
    cout << "Result: " << adjacentElementsProduct(arr) << endl; 
    return 0;
}