// exercise 5.6

/**
 *
 * Do Programming Exercise 5 (5.5) but use a two-dimensional array to store input for 3
 * years of monthly sales. Report the total sales for each individual year and for the
 * combined years.
 *
 */

#include <iostream>
#include <string>

unsigned long long yearlySales(unsigned *, int);

int main()
{
    using std::cout;

    const int Years = 3;
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

    unsigned sales[Years][MonthsInYear];
    for (int year = 0; year < Years; year++)
    {
        cout << "Year " << year + 1 << ":\n";
        for (int month = 0; month < MonthsInYear; month++)
        {
            cout << "Enter the number of books you sold in " << Months[month] << ": ";
            std::cin >> sales[year][month];
        }
        cout << std::endl;
    }

    unsigned long long sumYear[Years];
    unsigned long long sum = 0uLL;
    for (int year = 0; year < Years; year++)
    {
        sumYear[year] = yearlySales(sales[year], MonthsInYear);
        sum += sumYear[year];
    }

    for (int year = 0; year < Years; year++)
        cout << "You sold " << sumYear[year] << " books in year " << year + 1 << ".\n";
    cout << "You sold " << sum << " books total in " << Years << " years.\n";

    return 0;
}

unsigned long long yearlySales(unsigned * sales, int months)
{
    unsigned long long sum = 0uLL;
    for (int month = 0; month < months; month++)
        sum += sales[month];

    return sum;
}
