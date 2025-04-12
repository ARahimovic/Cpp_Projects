#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP
#include <iostream>

struct Date
{
    int day;
    int month;
    int year;

    Date(int d, int m, int y):day(d),month(m),year(y){}
};

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.day << "/"<< date.month << date.year << std::endl;
    return os;
}

#endif // COMMON_TYPES_HPP