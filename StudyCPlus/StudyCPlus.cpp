#include <iostream>

int main()
{
    const int minK{ 3 };
    const int maxK{ 5 };
    int value{ 0 };

    std::cout << "Enter value: ";
    std::cin >> value;

    system("cls");

    //******************************************************************
    bool isBool;
    isBool = (value == 1) || (value == 2) || (value == 4) || (value == 7) ? false : true;
    std::cout << isBool;

}