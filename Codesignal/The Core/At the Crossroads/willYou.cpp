/**
 * Mary tin rằng một người được yêu khi và chỉ khi anh ta/cô ta vừa trẻ, vừa đẹp, nhưng đây là một suy nghĩ khá buồn.
 * Vì vậy cô ta muốn đặt niềm tin của mình vào thử thách.
 * Biết young, beautiful và loved.
 * Hãy tìm hiểu nó có mâu thuẫn với niềm tin của Mary không?
 * Một người mâu thuẫn với niềm tin của Mary nếu một trong những tuyên bố sau là đúng: 
 *     Họ trẻ và đẹp nhưng không được yêu
 *     Họ được yêu nhưng không trẻ hay không đẹp.
 */
#include <iostream>
using namespace std;

bool willYou(bool young, bool beautiful, bool loved) {
    return loved ^ (young & beautiful);
}

int main() {
    cout << boolalpha << willYou(true, false, true); // true
    return 0;
}