#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default Bureaucrat"),grade(1)
{
    std::cout<<"Default Constructor Called!"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout<<"Bureaucrat "<< name <<" Constructor Called!"<<std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat &ref): name(ref.name), grade(ref.grade)
{
    std::cout<<"Bureaucrat Copy Constructor Called"<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref)
{
    if(this != &ref)
        grade = ref.grade;
    std::cout<<"Assignement operator called"<<std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout<<"Bureaucrat "<< name <<" Destructed"<<std::endl;
}

std::string Bureaucrat::get_name() const
{
    return this->name;
}

int Bureaucrat::get_grade() const
{
    return this->grade;
}

void Bureaucrat::increment_grade()
{
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrement_grade()
{
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooHighException();
    grade++;
}

std::ostream& operator<<(std::ostream &os, Bureaucrat const &obj)
{
    return os << obj.get_name() << ",  bureaucrat grade " << obj.get_grade();;
}