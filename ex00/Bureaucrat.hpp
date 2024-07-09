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
};