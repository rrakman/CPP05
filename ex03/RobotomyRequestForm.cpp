#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("Default")
{
    std::cout<< "RobotomyRequestForm Default Constructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72 , 45),target(target)
{
    std::cout<< "RobotomyRequestForm Constructor called"<<std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
    if (this != &ref)
        target = ref.target;
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref): AForm("RobotomyRequestForm", 72 , 45)
{
    *this = ref;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if(this->get_is_signed())
    {
        if (this->get_grade_to_exec() >= executor.get_grade())
            std::cout<<"AAAAAAAAAAAAAAAAAAA *drilling noise*"<<std::endl<<target<< " has been robotomized successfully 50% of the time"<<std::endl;
        else
        {
            std::cout<<"the robotomy failed."<<std::endl;
            throw RobotomyRequestForm::GradeTooLowException();
        }
    }
    else
    {
        std::cout<<"the robotomy failed."<<std::endl;
        throw AForm::Not_Signed();
    }
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout<< "RobotomyRequestForm Destructor called"<<std::endl;
}
std::string RobotomyRequestForm::get_target() const
{
    return target;
}