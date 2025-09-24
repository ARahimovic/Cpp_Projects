#include "commonTypes.hpp"

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.day << "/"<< date.month << date.year << std::endl;
    return os;
}

bool Date::isDateValid() const
{
    return !( day < 1 || day > 31 || year < 1900 || year > 2025 || month < 1 || month > 12);
}