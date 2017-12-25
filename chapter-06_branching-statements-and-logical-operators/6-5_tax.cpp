// exercise 6.5

/**
 *
 * The Kingdom of Neutronia, where the unit of currency is the tvarp, has the following
 * income tax code:
 *
 * First 5,000 tvarps: 0% tax
 * Next 10,000 tvarps: 10% tax
 * Next 20,000 tvarps: 15% tax
 * Tvarps after 35,000: 20% tax
 *
 * For example, someone earning 38,000 tvarps would owe 5,000 * 0.00 + 10,000 * 0.10 +
 * + 20,000 × 0.15 + 3,000 × 0.20, or 4,600 tvarps. Write a program that uses a
 * loop to solicit incomes and to report tax owed. The loop should terminate when
 * the user enters a negative number or non-numeric input.
 *
 */

#include <iostream>

double calculateTax(double);
void clearInput();

int main()
{
    using std::cout;

    cout << "Enter your income in tvarps. To stop, enter invalid or negative number.\n"
            "Enter first income: ";
    double income;
    while (std::cin >> income && income >= 0.0)
    {
        clearInput();
        double tax = calculateTax(income);
        cout << "You owe The Kingdom of Neutronia " << tax << " tvarps.\n"
                "Your net income is " << income - tax << " tvarps.\n\n"
                "Enter next income: ";
    }

    return 0;
}

double calculateTax(double income)
{
    const double incomeRange[] = { 5000.0, 10000.0, 20000.0 };
    const unsigned ranges = sizeof (incomeRange) / sizeof (double);
    const double taxRange[ranges + 1u] = { 0.0, 0.1, 0.15, 0.2 };

    double tax = 0.0;
    for (unsigned i = 0u; i < ranges; i++)
    {
        if (income >= incomeRange[i])
        {
            tax += incomeRange[i] * taxRange[i];
            income -= incomeRange[i];
        }
        else
        {
            tax += income * taxRange[i];
            income = 0.0;
            break;
        }
    }
    if (income > 0.0)
        tax += income * taxRange[ranges];

    return tax;
}

void clearInput()
{
    while (std::cin.get() != '\n')
        continue;
}
