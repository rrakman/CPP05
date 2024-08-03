#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat hamid("hamid",5);
        PresidentialPardonForm form("home");
        hamid.signForm(form);
        hamid.executeForm(form);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return EXIT_SUCCESS;
}