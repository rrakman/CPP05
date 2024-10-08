#pragma once
#include <iostream>
#include"Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_exec;
    public:
        Form();
        Form(std::string name, int grade_to_sign, int grade_to_exec);
        Form(const Form &obj);
        Form & operator=(const Form &obj);
        ~Form();
        std::string get_name() const;
        bool get_is_signed() const;
        int get_grade_to_sign() const;
        int get_grade_to_exec() const;
        void beSigned(Bureaucrat &obj);
        class GradeTooHighException : public std::exception 
        {
            public:
                virtual const char * what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
};

std::ostream & operator<<(std::ostream &os,const Form &obj);