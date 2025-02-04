#include <iostream> // std::cin, std::cout
#include <iomanip>  // std::get_time(), std::put_time()
#include <ctime>    // std::tm

using namespace std;

int main() {
    constexpr char Format[] = "%D";
    // Date/time format string, indicating "Date in form MM/DD/YY."
    // Note: Could also use "%m/%d/%y" for same results.

    //int m,d,y;
    tm date;

    cout << "Please enter your birthday in the format of MM/DD/YY ";
    //cin >> m >> d >> y;
    cin >> get_time(&date, Format);

    //cout << "Your birthday is: " << m << d << y << endl;
    cout << "Your birthday is: " << std::put_time(&date, Format) << '\n';
    return 0;
}