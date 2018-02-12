// exercise 2.2

/**
 *
 * Write a C++ program that asks for a distance in furlongs and converts it to yards.
 * (One furlong is 220 yards.)
 *
 */

#include <iostream>

int furlongsToYards(int);

int main()
{
    using std::cin;
    using std::cout;

    cout << "Enter a distance in furlongs: ";
    int furlongs;
    cin >> furlongs;
    cout << furlongs << " furlongs = " << furlongsToYards(furlongs) << " yards.\n";

    return 0;
}

int furlongsToYards(int furlongs)
{
    return furlongs * 220;
}
