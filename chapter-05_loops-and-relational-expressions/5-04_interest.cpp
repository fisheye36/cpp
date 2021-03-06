// exercise 5.4

/**
 *
 * Daphne invests $100 at 10% simple interest. That is, every year, the investment earns
 * 10% of the original investment, or $10 each and every year:
 *
 * interest = 0.10 * original balance
 *
 * At the same time, Cleo invests $100 at 5% compound interest. That is, interest is 5%
 * of the current balance, including previous additions of interest:
 *
 * interest = 0.05 * current balance
 *
 * Cleo earns 5% of $100 the first year, giving her $105. The next year she earns 5% of
 * $105, or $5.25 and so on. Write a program that finds how many years it takes for
 * the value of Cleo’s investment to exceed the value of Daphne’s investment and then
 * displays the value of both investments at that time.
 *
 */

#include <iostream>

void displayBalances(double, double);

int main()
{
    const double StartingBalance = 100.0;
    const double SimpleInterest = 0.1;
    const double CompoundInterest = 0.05;

    double balanceDaphne = StartingBalance;
    double balanceCleo = StartingBalance;
    displayBalances(balanceDaphne, balanceCleo);

    unsigned year = 0u;
    do
    {
        balanceDaphne += SimpleInterest * StartingBalance;
        balanceCleo += CompoundInterest * balanceCleo;
        year++;
    } while (balanceDaphne >= balanceCleo);

    std::cout << "After " << year
              << " years Cleo's investment exceeds Daphne’s investment.\n";
    displayBalances(balanceDaphne, balanceCleo);

    return 0;
}

void displayBalances(double daphne, double cleo)
{
    std::cout << "Daphne’s balance is $" << daphne
              << " and Cleo’s balance is $" << cleo << ".\n";
}
