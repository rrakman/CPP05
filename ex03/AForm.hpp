#pragma once
#include <iostream>
#include"Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_exec;
    public:
        AForm();
        AForm(std::string name, int grade_to_sign, int grade_to_exec);
        AForm(const AForm &obj);
        AForm & operator=(const AForm &obj);
        virtual ~AForm();
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
        class Not_Signed : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream & operator<<(std::ostream &os,const AForm &obj);