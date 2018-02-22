// exercise 6.6

/**
 *
 * Put together a program that keeps track of monetary contributions to the Society
 * for the Preservation of Rightful Influence. It should ask the user to enter the number
 * of contributors and then solicit the user to enter the name and contribution of
 * each contributor. The information should be stored in a dynamically allocated array
 * of structures. Each structure should have two members: a character array (or else a
 * string object) to store the name and a double member to hold the amount of the
 * contribution. After reading all the data, the program should display the names and
 * amounts donated for all donors who contributed $10,000 or more. This list should
 * be headed by the label Grand Patrons. After that, the program should list the
 * remaining donors. That list should be headed Patrons. If there are no donors in one
 * of the categories, the program should print the word "none". Aside from displaying
 * two categories, the program needs no sorting.
 *
 */

#include <iostream>
#include <string>

struct Contributor
{
    std::string name;
    double contribution;
};

void setContributors(Contributor *, unsigned);
void displayContributors(Contributor *, unsigned, std::string, double, bool);

unsigned readAmount();
double readContribution();
void clearInput();

int main()
{
    using std::cout;
    using std::endl;
    using std::string;

    const string DistinguishedContributionHeader = "Grand Patrons";
    const string StandardContributionHeader = "Patrons";
    const double ContributionThreshold = 10000.0;

    cout << "Enter the amount of contributors to the Society for the Preservation\n"
            "of Rightful Influence: ";
    unsigned amount = readAmount();

    Contributor * contributors = new Contributor[amount];
    cout << endl;
    setContributors(contributors, amount);

    cout << endl;
    displayContributors(contributors, amount, DistinguishedContributionHeader,
                        ContributionThreshold, true);
    cout << endl;
    displayContributors(contributors, amount, StandardContributionHeader,
                        ContributionThreshold, false);

    return 0;
}

void setContributors(Contributor * contributors, unsigned amount)
{
    using std::cin;
    using std::cout;
    using std::getline;

    for (unsigned i = 0u; i < amount; i++)
    {
        cout << "Contributor #" << i + 1u << ":\n"
                "Enter full name: ";
        getline(cin, contributors[i].name);

        cout << "Enter contribution: $";
        contributors[i].contribution = readContribution();
    }
}

void displayContributors(Contributor * contributors, unsigned amount, std::string header,
                         double limit, bool moreOrEqual)
{
    using std::cout;
    using std::endl;

    cout << header << ":\n\n";

    bool anyContributors = false;
    for (unsigned i = 0u; i < amount; i++)
    {
        bool display = (contributors[i].contribution < limit);
        if (moreOrEqual)
            display = !display;

        if (display)
        {
            cout << ((contributors[i].name.size()) ? contributors[i].name
                                                   : "Anonymous contributor")
                 << ": $" << contributors[i].contribution << endl;
            anyContributors = true;
        }
    }

    if (!anyContributors)
        cout << "none\n";
}

unsigned readAmount()
{
    unsigned amount;
    while (!(std::cin >> amount) || amount == 0u)
    {
        clearInput();
        std::cout << "Try again: ";
    }
    clearInput();

    return amount;
}

double readContribution()
{
    double contribution;
    while (!(std::cin >> contribution) || contribution <= 0.0)
    {
        clearInput();
        std::cout << "Try again: $";
    }
    clearInput();

    return contribution;
}

void clearInput()
{
    using std::cin;

    cin.clear();
    while (cin.get() != '\n')
        continue;
}
