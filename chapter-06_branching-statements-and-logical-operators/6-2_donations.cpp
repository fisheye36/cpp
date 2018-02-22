// exercise 6.2

/**
 *
 * Write a program that reads up to 10 donation values into an array of double. (Or, if
 * you prefer, use an array template object.) The program should terminate input on
 * non-numeric input. It should report the average of the numbers and also report
 * how many numbers in the array are larger than the average.
 *
 */

#include <array>
#include <iostream>

void clearInput();

int main()
{
    using std::array;
    using std::cin;
    using std::cout;

    const unsigned Size = 10u;

    cout << "Enter up to " << Size << " donations."
            " To stop, enter invalid or negative number.\n"
            "Enter first donation: $";
    array<double, Size> donations;
    unsigned elems = 0u;
    while (elems < Size && cin >> donations[elems] && donations[elems] >= 0.0)
    {
        clearInput();
        if (++elems < Size)
            cout << "Enter next donation: $";
    }

    if (elems > 1u)
    {
        long double sum = 0.0L;
        for (unsigned i = 0u; i < elems; i++)
            sum += donations[i];
        double average = sum / elems;

        unsigned aboveAverage = 0u;
        for (unsigned i = 0u; i < elems; i++)
        {
            if (donations[i] > average)
                aboveAverage++;
        }

        cout << "\nAverage donation is $" << average << " and " << aboveAverage
             << ((aboveAverage == 1u) ? " donation is" : " donations are")
             << " above average.\n";
    }

    return 0;
}

void clearInput()
{
    while (std::cin.get() != '\n')
        continue;
}
