// exercise 7.2

/**
 *
 * Write a program that asks the user to enter up to 10 golf scores, which are to be
 * stored in an array. You should provide a means for the user to terminate input prior
 * to entering 10 scores. The program should display all the scores on one line and
 * report the average score. Handle input, display, and the average calculation with
 * three separate array-processing functions.
 *
 */

#include <iostream>

unsigned readScores(int * scores, unsigned amount);
void displayScores(const int * scores, unsigned amount);
double average(const int * scores, unsigned amount);
void clearInput();

int main()
{
    using std::cout;
    using std::endl;

    const unsigned Amount = 10u;

    cout << "Enter up to " << Amount << " golf scores. To stop, enter invalid number.\n";
    int scores[Amount];
    unsigned scoresRead = readScores(scores, Amount);

    cout << endl;
    displayScores(scores, scoresRead);
    cout << "Your average score: " << average(scores, scoresRead) << endl;

    return 0;
}

unsigned readScores(int * scores, unsigned amount)
{
    using std::cout;

    unsigned scoresRead = 0u;
    cout << "Score #1: ";
    while (scoresRead < amount && std::cin >> scores[scoresRead])
    {
        clearInput();
        if (++scoresRead < amount)
            cout << "Score #" << scoresRead + 1u << ": ";
    }

    return scoresRead;
}

void displayScores(const int * scores, unsigned amount)
{
    using std::cout;

    if (amount > 0u)
    {
        cout << "Your golf scores: " << scores[0];
        for (unsigned i = 1u; i < amount; i++)
            cout << ", " << scores[i];
        cout << std::endl;
    }
}

double average(const int * scores, unsigned amount)
{
    long long sum = 0LL;
    for (unsigned i = 0u; i < amount; i++)
        sum += scores[i];

    return (amount < 2u) ? sum : double(sum) / amount;
}

void clearInput()
{
    while (std::cin.get() != '\n')
        continue;
}
