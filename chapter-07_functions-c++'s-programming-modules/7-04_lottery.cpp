// exercise 7.4

/**
 *
 * Many state lotteries use a variation of the simple lottery portrayed by Listing 7.4. In
 * these variations you choose several numbers from one set and call them the field
 * numbers. For example, you might select five numbers from the field of 1-47. You
 * also pick a single number (called a mega number or a power ball, etc.) from a second
 * range, such as 1-27. To win the grand prize, you have to guess all the picks correctly
 * The chance of winning is the product of the probability of picking all the
 * field numbers times the probability of picking the mega number. For instance, the
 * probability of winning the example described here is the product of the probability
 * of picking 5 out of 47 correctly times the probability of picking 1 out of 27 correctly
 * Modify Listing 7.4 to calculate the probability of winning this kind of lottery.
 *
 */

#include <iostream>

struct Lottery
{
    unsigned fieldNumbers;
    unsigned picks;
    unsigned megaNumber;
};

bool readLottery(Lottery * lottery);
long double probability(const Lottery * lottery);
void clearInput();

int main()
{
    using std::cout;

    Lottery lottery;
    cout << "Enter lottery details. To stop, enter invalid number.\n\n"
            "First lottery:\n";
    while (readLottery(&lottery))
    {
        cout << "You have one chance in " << probability(&lottery) << " of winning.\n\n"
                "Next lottery:\n";
    }

    return 0;
}

bool readLottery(Lottery * lottery)
{
    using std::cin;
    using std::cout;

    cout << "Enter total number of choices on the game card: ";
    if (!(cin >> lottery->fieldNumbers) || lottery->fieldNumbers < 2u)
        return false;
    clearInput();

    cout << "Enter the number of picks allowed: ";
    if (!(cin >> lottery->picks) || lottery->picks == 0u
                                 || lottery->picks >= lottery->fieldNumbers)
        return false;
    clearInput();

    cout << "Enter mega number range: ";
    if (!(cin >> lottery->megaNumber) || lottery->megaNumber < 2u)
        return false;
    clearInput();

    return true;
}

long double probability(const Lottery * lottery)
{
    long double result = 1.0L;
    unsigned fn;
    unsigned p;
    for (fn = lottery->fieldNumbers, p = lottery->picks; p > 0u; fn--, p--)
        result *= (long double) fn / p;

    return result * lottery->megaNumber;
}

void clearInput()
{
    while (std::cin.get() != '\n')
        continue;
}
