// experience + reward >= threshold ?
#include <iostream>
using namespace std;

bool reachNextLevel(int experience, int threshold, int reward) {
    return experience + reward >= threshold;
}

int main() {
    cout << boolalpha << reachNextLevel(10, 15, 5); // true
    return 0;
}