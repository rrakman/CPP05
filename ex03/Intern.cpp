#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called!" << std::endl;
}

Intern::Intern(const Intern &ref)
{
    if(this == &ref)
        return *this;
}