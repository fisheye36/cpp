// exercise 7.8b

/**
 *
 * Redo Listing 7.15 without using the array class. Do two versions:
 *
 * a) Use an ordinary array of const char * for the strings representing the season
 *    names and use an ordinary array of double for the expenses.
 * b) Use an ordinary array of const char * for the strings representing the season
 *    names and use a structure whose sole member is an ordinary array of
 *    double for the expenses. (This design is similar to the basic design of the
 *    array class.)
 *
 */

#include <iostream>

const unsigned Seasons = 4u;
const char * SeasonNames[Seasons] = { "Spring", "Summer", "Fall", "Winter" };

struct Expenses
{
    double season[Seasons];
};

void fill(Expenses * expenses, unsigned seasons);
void show(const Expenses * expenses, unsigned seasons);

double readExpenses();
void clearInput();

int main()
{
    Expenses expenses;
    fill(&expenses, Seasons);

    std::cout << std::endl;
    show(&expenses, Seasons);

    return 0;
}

void fill(Expenses * expenses, unsigned seasons)
{
    for (unsigned i = 0u; i < seasons; i++)
    {
        std::cout << "Enter " << SeasonNames[i] << " expenses: $";
        expenses->season[i] = readExpenses();
    }
}

void show(const Expenses * expenses, unsigned seasons)
{
    using std::cout;
    using std::endl;

    cout << "EXPENSES:\n";
    double total = 0.0;
    for (unsigned i = 0u; i < seasons; i++)
    {
        cout << SeasonNames[i] << ": $" << expenses->season[i] << endl;
        total += expenses->season[i];
    }
    cout << "\nTotal Expenses: $" << total << endl;
}

double readExpenses()
{
    double expenses;
    while (!(std::cin >> expenses) || expenses < 0.0)
    {
        clearInput();
        std::cout << "Try again: $";
    }
    clearInput();

    return expenses;
}

void clearInput()
{
    using std::cin;

    cin.clear();
    while (cin.get() != '\n')
        continue;
}
