#include "SDK_Core.hpp"
#include <iostream>
#include <sstream>
namespace SDK_Core {
std::string ltos(const unsigned long long l)
{
    std::string result;
    result = std::to_string(l);
    return result;
}
std::string dtos(const double l)
{
    std::string result;
    result = std::to_string(l);
    return result;
}
RGB::operator std::string() const
{
    return dtos(this->R) + ", " + dtos(this->G) + ", " + dtos(this->B);
}
ARGB::operator std::string() const
{
    return dtos(this->A) + ", " + dtos(this->R) + ", " + dtos(this->G) + ", " + dtos(this->B);
}

}