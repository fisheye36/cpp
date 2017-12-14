// exercise 5.5

/**
 *
 * You sell the book C++ for Fools. Write a program that has you enter a year’s worth
 * of monthly sales (in terms of number of books, not of money). The program should
 * use a loop to prompt you by month, using an array of char * (or an array of
 * string objects, if you prefer) initialized to the month strings and storing the input
 * data in an array of int. Then, the program should find the sum of the array contents
 * and report the total sales for the year.
 *
 */

#include <iostream>
#include <string>

unsigned long long yearlySales(unsigned *, int);

int main()
{
    using std::cout;

    const int MonthsInYear = 12;
    const std::string Months[MonthsInYear] =
    {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    unsigned sales[MonthsInYear];
    for (int month = 0; month < MonthsInYear; month++)
    {
        cout << "Enter the number of books you sold in " << Months[month] << ": ";
        std::cin >> sales[month];
    }

    unsigned long long sum = yearlySales(sales, MonthsInYear);
    cout << "\nYou sold " << sum << " books in a year.\n";

    return 0;
}

unsigned long long yearlySales(unsigned * sales, int months)
{
    unsigned long long sum = 0uLL;
    for (int month = 0; month < months; month++)
        sum += sales[month];

    return sum;
}
