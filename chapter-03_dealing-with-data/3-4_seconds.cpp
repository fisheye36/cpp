// exercise 3.4

/**
 *
 * Write a program that asks the user to enter the number of seconds as an integer
 * value (use type long, or, if available, long long) and that then displays the equivalent
 * time in days, hours, minutes and seconds. Use symbolic constants to represent
 * the number of hours in the day, the number of minutes in an hour and the number
 * of seconds in a minute. The output should look like this:
 *
 * Enter the number of seconds: 31600000
 * 31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds
 *
 */

#include <iostream>

void displayTime(unsigned long long);

int main()
{
    std::cout << "Enter the number of seconds: ";
    unsigned long long seconds;
    std::cin >> seconds;
    displayTime(seconds);

    return 0;
}

void displayTime(unsigned long long seconds)
{
    const unsigned HoursInDay = 24u;
    const unsigned MinutesInHour = 60u;
    const unsigned SecondsInMinute = 60u;

    unsigned long long days = seconds / (HoursInDay * MinutesInHour * SecondsInMinute);
    unsigned long remainingSeconds = seconds % (HoursInDay * MinutesInHour * SecondsInMinute);

    unsigned hours = remainingSeconds / (MinutesInHour * SecondsInMinute);
    remainingSeconds = remainingSeconds % (MinutesInHour * SecondsInMinute);

    unsigned minutes = remainingSeconds / SecondsInMinute;
    remainingSeconds = remainingSeconds % SecondsInMinute;

    std::cout << seconds << " seconds = " << days << " days, " << hours << " hours, "
              << minutes << " minutes, " << remainingSeconds << " seconds\n";
}
