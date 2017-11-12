// exercise 3.5

/**
 *
 * Write a program that requests the user to enter the current world population and
 * the current population of the U.S. (or of some other nation of your choice). Store
 * the information in variables of type long long. Have the program display the percent
 * that the U.S. (or other nation’s) population is of the world’s population. The
 * output should look something like this:
 *
 * Enter the world's population: 6898758899
 * Enter the population of the US: 310783781
 * The population of the US is 4.50492% of the world's population.
 *
 * You can use the Internet to get more recent figures.
 *
 */

#include <iostream>

double populationPercentage(long long, long long);

int main()
{
    using std::cout;
    using std::cin;

    cout << "Enter the world's population: ";
    long long worldPopulation;
    cin >> worldPopulation;

    cout << "Enter the population of Poland: ";
    long long polandPopulation;
    cin >> polandPopulation;

    cout << "The population of Poland is "
         << populationPercentage(polandPopulation, worldPopulation)
         << "% of the world's population.\n";

    return 0;
}

double populationPercentage(long long country, long long world)
{
    return 100.0 * country / world;
}
