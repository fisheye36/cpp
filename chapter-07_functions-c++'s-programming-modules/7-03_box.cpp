// exercise 7.3

/**
 *
 * Here is a structure declaration:
 *
 * struct Box
 * {
 *     char maker[Size];
 *     float lenght;
 *     float width;
 *     float height;
 *     float volume;
 * };
 *
 * a) Write a function that passes a box structure by value and that displays the
 *    value of each member.
 * b) Write a function that passes the address of a box structure and that sets the
 *    volume member to the product of the other three dimensions.
 * c) Write a simple program that uses these two functions.
 *
 */

#include <iostream>

const unsigned Size = 40u;

struct Box
{
    char maker[Size];
    float lenght;
    float width;
    float height;
    float volume;
};

void calculateVolume(Box * box);
void display(Box box);

int main()
{
    Box small = { "Boxer", 25.0f, 12.5f, 10.0f, 0.0f };
    Box large = { "Delivery Just4You", 120.0f, 50.0f, 100.0f, 0.0f };
    calculateVolume(&small);
    calculateVolume(&large);

    display(small);
    std::cout << std::endl;
    display(large);

    return 0;
}

void calculateVolume(Box * box)
{
    const float CubicCentimetersInLitre = 1000.0f;
    box->volume = box->lenght * box->width * box->height / CubicCentimetersInLitre;
}

void display(Box box)
{
    std::cout << "Box made by \"" << box.maker << "\": "
              << box.lenght << " cm x " << box.width << " cm x " << box.height << " cm\n"
              << "Volume: " << box.volume << " l\n";
}
