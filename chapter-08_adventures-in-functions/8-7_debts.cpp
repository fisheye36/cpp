// exercise 8.7

/**
 *
 * Modify Listing 8.14 so that it uses two template functions called SumArray() to
 * return the sum of the array contents instead of displaying the contents. The program
 * now should report the total number of things and the sum of all the debts.
 *
 */

#include <iostream>

template <typename T>
    T SumArray(T * arr, unsigned size);
template <typename T>
    T SumArray(T ** arr, unsigned size);

const unsigned Size = 50u;

struct Debt
{
    char name[Size];
    double amount;
};

int main()
{
    using std::cout;
    using std::endl;

    const unsigned DebtsSize = 3u;
    const unsigned ThingsSize = 6u;

    int things[ThingsSize] = { 13, 31, 103, 301, 130, 310 };
    cout << "Sum of Mr. E's things: " << SumArray(things, ThingsSize) << endl;

    Debt debts[DebtsSize] =
    {
        { "Ima Wolfe", 2400.0 },
        { "Ura Foxe", 1300.0 },
        { "Iby Stout", 1800.0 }
    };
    double * pd[DebtsSize];
    for (unsigned i = 0u; i < DebtsSize; i++)
        pd[i] = &debts[i].amount;
    cout << "Sum of Mr. E's debts: $" << SumArray(pd, DebtsSize) << endl;

    return 0;
}

template <typename T>
T SumArray(T * arr, unsigned size)
{
    T sum = 0;
    for (unsigned i = 0u; i < size; i++)
        sum += arr[i];

    return sum;
}

template <typename T>
T SumArray(T ** arr, unsigned size)
{
    T sum = 0;
    for (unsigned i = 0u; i < size; i++)
        sum += *arr[i];

    return sum;
}
