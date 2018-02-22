// exercise 6.9

/**
 *
 * Do Programming Exercise 6 (6.6) but modify it to get information from a file. The first
 * item in the file should be the number of contributors and the rest of the file should
 * consist of pairs of lines, with the first line of each pair being a contributor’s name
 * and the second line being a contribution. That is, the file should look like this:
 *
 * 4
 * Sam Stone
 * 2000
 * Freida Flass
 * 100500
 * Tammy Tubbs
 * 5000
 * Rich Raptor
 * 55000
 *
 */

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib> // EXIT_FAILURE, exit()

struct Contributor
{
    std::string name;
    double contribution;
};

Contributor * readContributors(unsigned *, std::string);
void displayContributors(Contributor *, unsigned, std::string, double, bool);
void invalidSyntax();

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    const string DistinguishedContributionHeader = "Grand Patrons";
    const string StandardContributionHeader = "Patrons";
    const double ContributionThreshold = 10000.0;

    cout << "Enter file name to open: ";
    string fileName;
    cin >> fileName;

    unsigned amount;
    Contributor * contributors = readContributors(&amount, fileName);

    cout << endl;
    displayContributors(contributors, amount, DistinguishedContributionHeader,
                        ContributionThreshold, true);
    cout << endl;
    displayContributors(contributors, amount, StandardContributionHeader,
                        ContributionThreshold, false);
    delete[] contributors;

    return 0;
}

Contributor * readContributors(unsigned * amount, std::string fileName)
{
    std::ifstream fileIn;
    fileIn.open(fileName);
    if (!fileIn.is_open())
    {
        std::cout << "Could not open file \"" << fileName << "\".\n";
        exit(EXIT_FAILURE);
    }

    if (!(fileIn >> *amount) || *amount == 0u)
    {
        fileIn.close();
        invalidSyntax();
    }
    fileIn.get();

    Contributor * contributors = new Contributor[*amount];
    for (unsigned i = 0u; i < *amount; i++)
    {
        std::getline(fileIn, contributors[i].name);

        if (!(fileIn >> contributors[i].contribution)
            || contributors[i].contribution <= 0.0)
        {
            delete[] contributors;
            fileIn.close();
            invalidSyntax();
        }
        fileIn.get();
    }
    fileIn.close();

    return contributors;
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

void invalidSyntax()
{
    std::cout << "Invalid file syntax.\n";
    std::exit(EXIT_FAILURE);
}
