// exercise 6.4

/**
 *
 * When you join the Benevolent Order of Programmers, you can be known at BOP
 * meetings by your real name, your job title or your secret BOP name. Write a program
 * that can list members by real name, by job title, by secret name or by a member's
 * preference. Base the program on the following structure:
 *
 * // Benevolent Order of Programmers name structure
 * struct Bop
 * {
 *     char fullName[Size]; // real name
 *     char title[Size];    // job title
 *     char bopName[Size];  // secret BOP name
 *     int preference;      // 0 = fullName, 1 = title, 2 = bopName
 * };
 *
 * In the program, create a small array of such structures and initialize it to suitable
 * values. Have the program run a loop that lets the user select from different
 * alternatives:
 *
 * a. display by name       b. display by title
 * c. display by BOP name   d. display by preference
 * q. quit
 *
 * Note that “display by preference” does not mean display the preference member; it
 * means display the member corresponding to the preference number. For instance, if
 * preference is 1, choice d would display the programmer’s job title. A sample run
 * may look something like the following:
 *
 * a. display by name       b. display by title
 * c. display by BOP name   d. display by preference
 * q. quit
 * Enter your choice: a
 *
 * Wimp Macho
 * Raki Rhodes
 * Celia Laiter
 * Hoppy Hipman
 * Pat Hand
 *
 * Next choice: d
 *
 * Wimp Macho
 * Junior Programmer
 * MIPS
 * Analyst Trainee
 * LOOPY
 *
 * Next choice: q
 *
 * Bye!
 *
 */

#include <iostream>

const unsigned Size = 80u;

struct Bop
{
    char fullName[Size];
    char title[Size];
    char bopName[Size];
    int preference;
};

enum Display { fullName, title, bopName, preference };

void displayMenu();
void displayProgrammers(Bop * programmers, unsigned amount, Display display);
char readChar();
void clearInput();

int main()
{
    using std::cout;

    Bop programmers[] =
    {
        { "Wimp Macho", "CEO", "MACHO", 0 },
        { "Raki Rhodes", "Junior programmer", "RHINO", 1 },
        { "Celia Laiter", "Tester", "MIPS", 2 },
        { "Hoppy Hipman", "Analyst Trainee", "H", 1 },
        { "Pat Hand", "Network Administrator", "LOOPY", 2}
    };
    unsigned amount = sizeof (programmers) / sizeof (Bop);

    displayMenu();
    bool finished = false;
    do
    {
        Display display;
        switch (readChar())
        {
            case 'A' :
            case 'a' :
                display = fullName;
                break;
            case 'B' :
            case 'b' :
                display = title;
                break;
            case 'C' :
            case 'c' :
                display = bopName;
                break;
            case 'D' :
            case 'd' :
                display = preference;
                break;
            case 'Q' :
            case 'q' :
                finished = true;
                continue;
            default :
                cout << "Try again: ";
                continue;
        }

        cout << std::endl;
        displayProgrammers(programmers, amount, display);
        cout << "\nNext choice: ";
    } while (!finished);

    cout << "\nBye!\n";

    return 0;
}

void displayMenu()
{
    std::cout << "a. display by name\tb. display by title\n"
                 "c. display by BOP name\td. display by preference\n"
                 "q. quit\n"
                 "Enter your choice: ";
}

void displayProgrammers(Bop * programmers, unsigned amount, Display display)
{
    using std::cout;
    using std::endl;

    for (unsigned i = 0u; i < amount; i++)
    {
        switch ((display != preference) ? display : Display(programmers[i].preference))
        {
            case fullName :
                cout << programmers[i].fullName << endl;
                break;
            case title :
                cout << programmers[i].title << endl;
                break;
            case bopName :
                cout << programmers[i].bopName << endl;
                break;
            default :
                cout << "Invalid preference value!\n";
        }
    }
}

char readChar()
{
    char ch;
    while (std::cin.get(ch) && ch == '\n')
        continue;
    clearInput();

    return ch;
}

void clearInput()
{
    while (std::cin.get() != '\n')
        continue;
}
