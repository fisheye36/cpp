// exercise 3.3

/**
 *
 * Write a program that asks the user to enter a latitude in degrees, minutes and seconds,
 * and that then displays the latitude in decimal format. There are 60 seconds of
 * arc to a minute and 60 minutes of arc to a degree; represent these values with symbolic
 * constants. You should use a separate variable for each input value. A sample
 * run should look like this:
 *
 * Enter a latitude in degrees, minutes and seconds:
 * First, enter the degrees: 37
 * Next, enter the minutes of arc: 51
 * Finally, enter the seconds of arc: 19
 * 37 degrees, 51 minutes, 19 seconds = 37.8553 degrees
 *
 */

#include <iostream>

double latitude(unsigned, unsigned, unsigned);

int main()
{
    using std::cout;
    using std::cin;

    cout << "Enter a latitude in degrees, minutes and seconds:\n"
            "First, enter the degrees: ";
    unsigned degrees;
    cin >> degrees;

    cout << "Next, enter the minutes of arc: ";
    unsigned minutes;
    cin >> minutes;

    cout << "Finally, enter the seconds of arc: ";
    unsigned seconds;
    cin >> seconds;

    cout << degrees << " degrees, " << minutes << " minutes, " << seconds
         << " seconds = " << latitude(degrees, minutes, seconds) << " degrees\n";

    return 0;
}

double latitude(unsigned deg, unsigned min, unsigned sec)
{
    const unsigned SecondsInMinute = 60u;
    const unsigned MinutesInDegree = 60u;

    return deg + (min + double(sec) / SecondsInMinute) / MinutesInDegree;
}
