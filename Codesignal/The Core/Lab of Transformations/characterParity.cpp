/**
 * Cho một ký tự, kiểm tra xem nó đại diện cho một chữ số lẻ, một chữ số chẵn
 * hay không phải là một chữ số.
 */
#include <iostream>
using namespace std;

string characterParity(char symbol) {
    return isdigit(symbol) ? (symbol - '0')%2 ? "odd" : "even" : "not a digit";
}

int main() {
    cout << characterParity('8');
    return 0;
}