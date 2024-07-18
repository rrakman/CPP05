#include"Bureaucrat.hpp"
#include"Form.hpp"

int main()
{
    try
    {
        Bureaucrat hamid("hamid",150);
        Form test("test", 10,1);
        hamid.signForm(test);

    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return EXIT_SUCCESS;
}