/**
 * https://app.codesignal.com/arcade/code-arcade/mirror-lake/kGeuCkJNbqczCCqgg
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int numbersGrouping(vector<int> v) {
    set<int> setGroup;
    for (int i : v)
        setGroup.insert((i - 1)/10000);
    return setGroup.size() + v.size();
}

int main() {
    vector<int> v ={20000, 239, 10001, 999999, 10000, 20566, 29999};
    cout << numbersGrouping(v);
    return 0;
}