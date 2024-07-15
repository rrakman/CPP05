#pragma once
#include<iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int         grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &ref);
        Bureaucrat& operator=(const Bureaucrat &ref);
        ~Bureaucrat();
        std::string get_name() const;
        int get_grade() const;
        void increment_grade();
        void decrement_grade();
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade is too high";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade is too low";
                }
        };
};

std::ostream& operator<<(std::ostream &os, Bureaucrat const &obj);