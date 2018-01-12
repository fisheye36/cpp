// exercise 7.7

/**
 *
 * Redo Listing 7.7, modifying the three array-handling functions to each use two
 * pointer parameters to represent a range. The fillArray() function, instead of
 * returning the actual number of items read, should return a pointer to the location
 * after the last location filled; the other functions can use this pointer as the second
 * argument to identify the end of the data.
 *
 */

#include <iostream>

double * fillArray(double * begin, double * end);
void revalue(double * begin, double * end, double r);
void showArray(const double * begin, const double * end);

double readFactor();
void clearInput();

int main()
{
    using std::cout;
    using std::endl;

    const unsigned Amount = 5u;

    cout << "Enter up to " << Amount << " property values.\n"
            "To stop, enter negative or invalid number.\n";
    double properties[Amount];
    double * propertiesEnd = fillArray(properties, properties + Amount);

    if (properties != propertiesEnd)
    {
        cout << endl;
        showArray(properties, propertiesEnd);

        cout << "\nEnter revaluation factor: ";
        double factor = readFactor();

        cout << endl;
        revalue(properties, propertiesEnd, factor);
        showArray(properties, propertiesEnd);
    }
    cout << "\nDone.\n";

    return 0;
}

double * fillArray(double * begin, double * end)
{
    using std::cout;
    using std::cin;

    cout << "Enter value #1: ";
    unsigned i = 2u;
    while (begin < end && cin >> *begin && *begin > 0.0)
    {
        clearInput();
        if (++begin < end)
            cout << "Enter value #" << i++ << ": ";
    }

    if (!cin || *begin <= 0.0)
        clearInput();

    return begin;
}

void revalue(double * begin, double * end, double r)
{
    while (begin < end)
        *(begin++) *= r;
}

void showArray(const double * begin, const double * end)
{
    for (unsigned i = 1u; begin < end; i++, begin++)
        std::cout << "Property #" << i << ": $" << *begin << std::endl;
}

double readFactor()
{
    double factor;
    while (!(std::cin >> factor))
    {
        clearInput();
        std::cout << "Try again: ";
    }

    return factor;
}

void clearInput()
{
    using std::cin;

    cin.clear();
    while (cin.get() != '\n')
        continue;
}
