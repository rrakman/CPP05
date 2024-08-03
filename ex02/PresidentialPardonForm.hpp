#pragma once
#include"AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &ref);
        PresidentialPardonForm & operator=(const PresidentialPardonForm &ref);
        void execute(Bureaucrat const & executor) const;
        ~PresidentialPardonForm();
        std::string get_target() const;
};