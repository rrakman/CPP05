#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &ref);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &ref);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
        std::string get_target() const;
};