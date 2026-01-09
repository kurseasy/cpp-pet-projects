#include <iostream>
using namespace std;

int main() {
    int a, b;
    char op;
    cout << "Введите выражение (например: 3 + 4): ";
    cin >> a >> op >> b;

    switch(op) {
        case '+': cout << "Результат: " << a + b; break;
        case '-': cout << "Результат: " << a - b; break;
        case '*': cout << "Результат: " << a * b; break;
        case '/': cout << "Результат: " << a / b; break;
        default: cout << "Неизвестная операция";
    }
    return 0;
}
