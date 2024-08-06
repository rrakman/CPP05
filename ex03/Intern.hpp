#pragma once
#include "AForm.hpp"

class Intern
{
    public :
        Intern();
        Intern(const Intern &ref);
        Intern & operator=(const Intern & ref);
        ~Intern();
        AForm* makeForm(std::string form_name, std::string form_target);
};