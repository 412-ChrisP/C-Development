#include <iostream>

using namespace std;

int f(int n) {
    if (n == 0) {
        cout << "f(0): 5" << endl;
        return 5;
    } else {
        int result = 2 * f(n - 1) - 3;
        cout << "f(" << n << "): " << result << endl;
        return result;
    }
}

int main() {
    int number;
    do {
        cout << "Enter a number greater than or equal to 0: ";
        cin >> number;

        if (number < 0) {
            cout << "Please enter a valid number!" << endl;
        }
    } while (number < 0);

    f(number);

    return 0;
}