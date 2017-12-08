// exercise 4.8

/**
 *
 * Do Programming Exercise 7 (4.7) but use new to allocate a structure instead of declaring
 * a structure variable. Also have the program request the pizza diameter before it
 * requests the pizza company name.
 *
 */

#include <iostream>
#include <string>

struct Pizza
{
    std::string company;
    int diameter;
    double weight;
};

int main()
{
    using std::cout;
    using std::cin;

    cout << "Enter pizza diameter in centimeters: ";
    Pizza * pizza = new Pizza;
    (cin >> pizza->diameter).get();

    cout << "Enter the name of the pizza company: ";
    getline(cin, pizza->company);

    cout << "Enter pizza weight in kilograms: ";
    cin >> pizza->weight;

    cout << "\nPizza \"" << pizza->company << "\"\n"
            "diameter: " << pizza->diameter << " cm\n"
            "weight: " << pizza->weight << " kg\n";
    delete pizza;

    return 0;
}
