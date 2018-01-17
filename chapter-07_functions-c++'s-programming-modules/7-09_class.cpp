// exercise 7.9

/**
 *
 * This exercise provides practice in writing functions dealing with arrays and structures.
 * The following is a program skeleton. Complete it by providing the described
 * functions:
 *
 * #include <iostream>
 *
 * const unsigned Lenght = 30u;
 *
 * struct Student
 * {
 *     char fullName[Lenght];
 *     char hobby[Lenght];
 *     int oopLevel;
 * };
 *
 * // getInfo() has two arguments: a pointer to the first element of
 * // an array of student structures and an unsigned int representing the
 * // number of elements in the array. The function solicits and
 * // stores data about students. It terminates input upon filling
 * // the array or upon encountering a blank line for the student
 * // name. The function returns the actual number of array elements
 * // filled.
 * unsigned getInfo(Student * pa, unsigned n);
 *
 * // display1() takes a student structure as an argument
 * // and displays its contents
 * void display1(Student st);
 *
 * // display2() takes the address of student structure as an
 * // argument and displays the structure’s contents
 * void display2(const Student * ps);
 *
 * // display3() takes the address of the first element of an array
 * // of student structures and the number of array elements as
 * // arguments and displays the contents of the structures
 * void display3(const Student * pa, unsigned n);
 *
 * int main()
 * {
 *     using std::cout;
 *     using std::endl;
 *
 *     cout << "Enter class size: ";
 *     unsigned classSize = readSize();
 *
 *     Student * students = new Student[classSize];
 *     cout << endl;
 *     unsigned entered = getInfo(students, classSize);
 *
 *     if (entered)
 *     {
 *         cout << endl;
 *         for (unsigned i = 0u; i < entered; i++)
 *         {
 *             if (i > 0u)
 *                 cout << endl;
 *
 *             display1(students[i]);
 *             cout << endl;
 *             display2(students + i);
 *         }
 *
 *         cout << endl;
 *         display3(students, entered);
 *     }
 *     delete[] students;
 *
 *     cout << "\nDone.\n";
 *
 *     return 0;
 * }
 *
 */

#include <iostream>

const unsigned Lenght = 30u;

struct Student
{
    char fullName[Lenght];
    char hobby[Lenght];
    int oopLevel;
};

unsigned getInfo(Student * pa, unsigned n);
void display1(Student st);
void display2(const Student * ps);
void display3(const Student * pa, unsigned n);

bool readString(char * str, unsigned n);
unsigned readSize();
int readLevel();
void clearInput();

int main()
{
    using std::cout;
    using std::endl;

    cout << "Enter class size: ";
    unsigned classSize = readSize();

    Student * students = new Student[classSize];
    cout << endl;
    unsigned entered = getInfo(students, classSize);

    if (entered)
    {
        cout << endl;
        for (unsigned i = 0u; i < entered; i++)
        {
            if (i > 0u)
                cout << endl;

            display1(students[i]);
            cout << endl;
            display2(students + i);
        }

        cout << endl;
        display3(students, entered);
    }
    delete[] students;

    cout << "\nDone.\n";

    return 0;
}

unsigned getInfo(Student * pa, unsigned n)
{
    using std::cout;

    unsigned i;
    for (i = 0u; i < n; i++)
    {
        if (i > 0u)
            cout << std::endl;

        cout << "Student #" << i + 1u << ":\n"
             << "Enter student's name: ";
        if (!readString(pa[i].fullName, Lenght))
            break;

        cout << "Enter student's hobby: ";
        readString(pa[i].hobby, Lenght);

        cout << "Enter student's OOP level: ";
        pa[i].oopLevel = readLevel();
    }

    return i;
}

void display1(Student st)
{
    std::cout << "Name: " << st.fullName
              << "\nHobby: " << (*(st.hobby) ? st.hobby : "none")
              << "\nOOP level: " << st.oopLevel << std::endl;
}

void display2(const Student * ps)
{
    std::cout << "Name: " << ps->fullName
              << "\nHobby: " << (*(ps->hobby) ? ps->hobby : "none")
              << "\nOOP level: " << ps->oopLevel << std::endl;
}

void display3(const Student * pa, unsigned n)
{
    for (unsigned i = 0u; i < n; i++)
    {
        if (i > 0u)
            std::cout << std::endl;
        display2(pa + i);
    }
}

bool readString(char * str, unsigned n)
{
    std::cin.get(str, n);
    clearInput();

    if (*str)
        return true;

    return false;
}

unsigned readSize()
{
    unsigned size;
    while (!(std::cin >> size) || size == 0u)
    {
        clearInput();
        std::cout << "Try again: ";
    }
    clearInput();

    return size;
}

int readLevel()
{
    int level;
    while (!(std::cin >> level))
    {
        clearInput();
        std::cout << "Try again: ";
    }
    clearInput();

    return level;
}

void clearInput()
{
    using std::cin;

    cin.clear();
    while (cin.get() != '\n')
        continue;
}
