#include"Form.hpp"

Form::Form(): name("Default Form"), is_signed(false),grade_to_sign(150),grade_to_exec(150)
{
    std::cout<<"Default Form constructor called"<<std::endl;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_exec): \
    name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec)
{
    if(grade_to_sign > 150 || grade_to_exec > 150)
        throw Form::GradeTooLowException();
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw Form::GradeTooHighException();
    std::cout<<"Form "<< name << " constructor called"<<std::endl;
}

Form::Form(const Form &obj): name(obj.name),grade_to_sign(obj.grade_to_sign), \
    grade_to_exec(obj.grade_to_exec)
{
    is_signed = obj.is_signed;
    std::cout<<"Copy Constructor Called"<<std::endl;
}

Form & Form::operator=(const Form &obj)
{
    if(this != &obj)
        this->is_signed = obj.is_signed;
    return *this;
}

Form::~Form()
{
    std::cout<<"Form Destructor Called"<<std::endl;
}

std::string Form::get_name() const
{
    return name;
}

bool Form::get_is_signed() const
{
    return is_signed;
}

int Form::get_grade_to_sign() const
{
    return grade_to_sign;
}

int Form::get_grade_to_exec() const
{
    return grade_to_exec;
}

std::ostream & operator<<(std::ostream &os, const Form &obj)
{
    std::string is_signed = "False";
    if(obj.get_is_signed())
        is_signed = "True";
    return os << "Form " << obj.get_name() << " is signed: " << is_signed << ", and Grade to sign is: " << obj.get_grade_to_sign()<< ", and Grade to exec is: " << obj.get_grade_to_exec();
}

void Form::beSigned(Bureaucrat &obj)
{
    if(obj.get_grade() > grade_to_sign)
        throw Form::GradeTooLowException();
    is_signed = true;
}