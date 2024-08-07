#pragma once
#include "AForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"

class Intern
{
    public :
        Intern();
        Intern(const Intern &ref);
        Intern & operator=(const Intern & ref);
        ~Intern();
        AForm* makeForm(std::string form_name, std::string form_target);
        class FormNotFound : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};