#include "Time.h"
#include <iostream>
#include <string>
using namespace std;
// Set the objectfs data values.
void Time::Set(unsigned hours, unsigned minutes, char am_pm)
{
    if (hours >= 1 && hours <= 12 && minutes >= 0 && minutes <= 59 &&
        (am_pm == 'A' || am_pm == 'P'))
    {
        myHours = hours;
        myMinutes = minutes;
        myAMorPM = am_pm;
    }
    else
        cerr << "*** Can't set these values ***\n";
}
// Display the time represented by the object
void Time::Display() const
{
    string minStr = to_string(myMinutes);
    if (myMinutes == 0) {
        minStr = "00";
    }
    cout << myHours << ':' << minStr << ' ' << myAMorPM << ".M." <<
         endl;
}
unsigned Time::getHours() const {
    return myHours;
}
unsigned Time::getMinutes() const {
    return myMinutes;
}
char Time::getAMorPM() const {
    return myAMorPM;
}
// Forward the time by a given number of minutes
void Time::Forward(int minutesToForward)
{
    int totalMinutes = myMinutes + minutesToForward;
    myMinutes = totalMinutes % 60;
    int hoursAdded = totalMinutes / 60;
    int nowHours = myHours + hoursAdded;
    int flipAmPm = ((nowHours / 12) - (myHours / 12)) % 2;
    if (flipAmPm == 1) {
        if (myAMorPM == 'A') {
            myAMorPM = 'P';
        }
        else {
            myAMorPM = 'A';
        }
    }
    myHours = nowHours % 12;
    if (myHours == 0) {
        myHours = 12;
    }
}
Time::Time() {
    myHours = 12;
    myMinutes = 0;
    myAMorPM = 'A';
}
Time::Time(unsigned hours, unsigned minutes, char am_pm){
    if (hours >= 1 && hours <= 12 && minutes >= 0 && minutes <= 59 &&
        (am_pm == 'A' || am_pm == 'P')) {
        myHours = hours;
        myMinutes = minutes;
        myAMorPM = am_pm;
    } else {
        cerr << "*** Can't set these values ***\n";
        Set(12, 0, 'A');
    }
}

Time Time::operator+(int minutes)
{
    Time result = *this;
    result.Forward(minutes);
    return result;
}

Time& Time::operator+=(int minutes)
        {
    Forward(minutes);
    return *this;
}

Time& Time::operator=(int hour)
{
    if (hour >= 1 && hour <= 12)
    {
        Set(hour, 0, 'A');
    }
    else
    {
        Set(12, 0, 'A');
    }
    return *this;
}
