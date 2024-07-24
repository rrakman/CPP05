#include"Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat one("Hamiid", -1);
        std::cout<<one<<std::endl;
        one.decrement_grade();
        std::cout<<one<<std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return EXIT_SUCCESS;
}