#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"
#include"Intern.hpp"

int main()
{
    try
    {
        Intern intern1;
        AForm * form1 = intern1.makeForm("ShrubberyCreationForm", "test");
        if(form1)
        {
            std::cout << *form1 << std::endl;
            delete form1;
        }
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return EXIT_SUCCESS;
}