#include <iostream>

using namespace std;

int main() {
    int m, d, y;
    char seperator;

    cout << "Please enter your birthday in the format of MM/DD/YY ";
    cin >> m >> seperator >> d >> seperator >> y;

    cout << "Your birthday is: " << m << seperator << d << seperator << y << endl;
    system("pause");
}