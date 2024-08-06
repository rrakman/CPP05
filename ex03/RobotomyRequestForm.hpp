#pragma once
#include"AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private :
        std::string target;
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &ref);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &ref);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
        std::string get_target() const;
};