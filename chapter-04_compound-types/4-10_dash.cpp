// exercise 4.10

/**
 *
 * Write a program that requests the user to enter three times for the 40-yd dash (or
 * 40-meter, if you prefer) and then displays the times and the average. Use an array
 * object to hold the data. (Use a built-in array if array is not available.)
 *
 */

#include <iostream>
#include <array>

int main()
{
    using std::cout;
    using std::cin;

    const unsigned Amount = 3u;

    cout << "Enter " << Amount << " times for the 40-meter dash in seconds:\n";
    std::array<double, Amount> times;
    cin >> times[0];
    cin >> times[1];
    cin >> times[2];

    double averageTime = (times[0] + times[1] + times[2]) / Amount;
    cout << "\nYour times are: "
         << times[0] << " s, " << times[1] << " s, " << times[2] << " s.\n"
            "Your average time is " << averageTime << " s.\n";

    return 0;
}
