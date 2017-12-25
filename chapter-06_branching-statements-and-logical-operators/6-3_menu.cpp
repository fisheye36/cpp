// exercise 6.3

/**
 *
 * Write a precursor to a menu-driven program. The program should display a menu
 * offering four choices, each labeled with a letter. If the user responds with a letter
 * other than one of the four valid choices, the program should prompt the user to
 * enter a valid response until the user complies. Then the program should use a
 * switch to select a simple action based on the user’s selection. A program run could
 * look something like this:
 *
 * Please enter one of the following choices:
 * c) carnivore     p) pianist
 * t) tree          g) game
 * f
 * Please enter a c, p, t or g: q
 * Please enter a c, p, t or g: t
 * A maple is a tree.
 *
 */

#include <iostream>

void displayMenu();
char readChar();
void clearInput();

int main()
{
    using std::cout;

    displayMenu();
    bool finished;
    do
    {
        finished = true;
        switch (readChar())
        {
            case 'C' :
            case 'c' :
                cout << "Mmm... meat!\n";
                break;
            case 'P' :
            case 'p' :
                cout << "Being a pianist is easier than being a C++ developer.\n";
                break;
            case 'T' :
            case 't' :
                cout << "A maple is a tree.\n";
                break;
            case 'G' :
            case 'g' :
                cout << "Do you want to play a game?\n";
                break;
            default :
                cout << "Please enter a c, p, t or g: ";
                finished = false;
        }
    } while (!finished);

    return 0;
}

void displayMenu()
{
    std::cout << "Please enter one of the following choices:\n"
                 "c) carnivore\tp) pianist\n"
                 "t) tree\t\tg) game\n";
}

char readChar()
{
    char ch;
    std::cin >> ch;
    clearInput();

    return ch;
}

void clearInput()
{
    while (std::cin.get() != '\n')
        continue;
}
