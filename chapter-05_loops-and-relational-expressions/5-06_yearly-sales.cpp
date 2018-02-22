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

unsigned long long yearlySales(unsigned *, unsigned);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    const unsigned Years = 3u;
    const unsigned MonthsInYear = 12u;
    const string Months[MonthsInYear] =
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
    for (unsigned year = 0u; year < Years; year++)
    {
        cout << "Year " << year + 1u << ":\n";
        for (unsigned month = 0u; month < MonthsInYear; month++)
        {
            cout << "Enter the number of books you sold in " << Months[month] << ": ";
            cin >> sales[year][month];
        }
        cout << endl;
    }

    unsigned long long sumYear[Years];
    unsigned long long sum = 0uLL;
    for (unsigned year = 0u; year < Years; year++)
    {
        sumYear[year] = yearlySales(sales[year], MonthsInYear);
        sum += sumYear[year];
    }

    for (unsigned year = 0u; year < Years; year++)
        cout << "You sold " << sumYear[year] << " books in year " << year + 1u << ".\n";
    cout << "You sold " << sum << " books total in " << Years << " years.\n";

    return 0;
}

unsigned long long yearlySales(unsigned * sales, unsigned months)
{
    unsigned long long sum = 0uLL;
    for (unsigned month = 0u; month < months; month++)
        sum += sales[month];

    return sum;
}
