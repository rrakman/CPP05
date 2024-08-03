#include"PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5),target("Default target")
{
    std::cout << "Default PresidentialPardonForm constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm constructor Called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
    if(this != &ref)
        target = ref.target;
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : AForm("PresidentialPardonForm", 25, 5)
{
    *this = ref;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if(this->get_is_signed())
    {
        if(this->get_grade_to_exec() >= executor.get_grade())
        {
            std::cout<<target<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
        }
        else
            throw AForm::GradeTooLowException();
    }
    else
        throw AForm::Not_Signed();
}

std::string PresidentialPardonForm::get_target() const
{
    return target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout<< "PresidentialPardonForm Destructor Called" << std::endl;
}
