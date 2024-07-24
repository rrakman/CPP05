#include"AForm.hpp"

AForm::AForm(): name("Default AForm"), is_signed(false),grade_to_sign(150),grade_to_exec(150)
{
    std::cout<<"Default AForm constructor called"<<std::endl;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec): \
    name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec)
{
    if(grade_to_sign > 150 || grade_to_exec > 150)
        throw AForm::GradeTooLowException();
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw AForm::GradeTooHighException();
    std::cout<<"AForm "<< name << " constructor called"<<std::endl;
}

AForm::AForm(const AForm &obj): name(obj.name),grade_to_sign(obj.grade_to_sign), \
    grade_to_exec(obj.grade_to_exec)
{
    is_signed = obj.is_signed;
    std::cout<<"Copy Constructor Called"<<std::endl;
}

AForm & AForm::operator=(const AForm &obj)
{
    if(this != &obj)
        this->is_signed = obj.is_signed;
    return *this;
}

AForm::~AForm()
{
    std::cout<<"AForm Destructor Called"<<std::endl;
}

std::string AForm::get_name() const
{
    return name;
}

bool AForm::get_is_signed() const
{
    return is_signed;
}

int AForm::get_grade_to_sign() const
{
    return grade_to_sign;
}

int AForm::get_grade_to_exec() const
{
    return grade_to_exec;
}

std::ostream & operator<<(std::ostream &os, const AForm &obj)
{
    std::string is_signed = "False";
    if(obj.get_is_signed())
        is_signed = "True";
    return os << "AForm " << obj.get_name() << " is signed: " << is_signed << ", and Grade to sign is: " << obj.get_grade_to_sign()<< ", and Grade to exec is: " << obj.get_grade_to_exec();
}

void AForm::beSigned(Bureaucrat &obj)
{
    if(obj.get_grade() > grade_to_sign)
        throw AForm::GradeTooLowException();
    is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}