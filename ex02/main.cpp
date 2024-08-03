#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"

int main()
{
    try
    {
        Bureaucrat hamid("hamid",145);
        ShrubberyCreationForm form("home");
        ShrubberyCreationForm second("test");
        hamid.signForm(form);
        hamid.executeForm(form);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return EXIT_SUCCESS;
}