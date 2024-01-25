#include <iostream>
using namespace std;

int main() {

    printf(" CALCULATOR\n");

    double num1, num2;
    char operation;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Enter the operator ( + , - , * , / ): ";
    cin >> operation;

    switch (operation) {
        case '+':
            cout << "The result is: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "The result is: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "The result is: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "The result is: " << num1 / num2 << endl;
            else
                cout << "Error! Division by zero is Error." << endl;
            break;
        default:
            cout << "Error! Invalid operator." << endl;
            break;
    }

    return 0;
}