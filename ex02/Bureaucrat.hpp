#pragma once
#include<iostream>
#include"Form.hpp"

class Form;

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
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        void signForm(Form &obj);
};

std::ostream& operator<<(std::ostream &os, Bureaucrat const &obj);