#include <iostream>

bool isLeapYear(int year)
{
    if (year % 100 == 0) // if the year is century then it should be divisible by 400 to be a leap year
        return year % 400 == 0;
    return year % 4 == 0;

    // or simplly
    // return (year % 100 != 0 or year % 400 == 0) && year % 4 == 0;       // if a number is divisible by 400 sure its divisible by 4
}

int main()
{
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;

    if (isLeapYear(year))
    {
        std::cout << year << " is a leap year." << std::endl;
    }
    else
    {
        std::cout << year << " is not a leap year." << std::endl;
    }

    return 0;
}