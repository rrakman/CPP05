#include"Bureaucrat.hpp"

int main()
{
    Bureaucrat one("simo",5);
    Bureaucrat two("ahmed",3);
    one = two;
    std::cout<<"two = "<<one.get_name()<< std::endl;
}