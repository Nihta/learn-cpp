#include <iostream>
using namespace std;

int applesDistribution(int apples, int boxCapacity, int maxResidue) {
    int count = 0;
    for (int i = boxCapacity; i > 0; i--)
        if (apples % i <= maxResidue)
            count++;
    return count;
}

int applesDistribution2(int a, int b, int m) {
    int c = 0;
    while (b)
        if (a % b-- <= m)
            c++;
    return c;
}

int main() {
    cout << applesDistribution(7, 4, 1); // 3
    return 0;
}