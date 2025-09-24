#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP
#include <iostream>

struct Date
{
    int day;
    int month;
    int year;

    Date():day(0),month(0),year(0){}
    Date(int d, int m, int y):day(d),month(m),year(y){}
    bool isDateValid() const;
};

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif // COMMON_TYPES_HPP