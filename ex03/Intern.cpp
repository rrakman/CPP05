#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called!" << std::endl;
}

Intern & Intern::operator=(const __unused Intern & ref)
{
    // no data to copy
    return *this;
}

Intern::Intern(const Intern &ref)
{
    *this = ref;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called!" << std::endl;
}

AForm * makeShrubberyCreationForm(std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm * makeRobotomyRequestForm(std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm * makePresidentialPardonForm(std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string form_name, std::string form_target)
{
    AForm * (*forms[])(std::string &) = {&makeShrubberyCreationForm , &makeRobotomyRequestForm, &makePresidentialPardonForm};
    std::string names[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    for (int i = 0; i < 3; i++)
    {
        if(form_name == names[i])
        {
            std::cout << "Intern creates " << form_name << std::endl;
            return forms[i](form_target);
        }
    }
    throw FormNotFound();
}

const char* Intern::FormNotFound::what() const throw()
{
    return "Form not found!";
}