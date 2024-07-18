#include"Bureaucrat.hpp"
#include"Form.hpp"

int main()
{
    try
    {
        Bureaucrat hamid("hamid",1);
        Form test("test", 10,1);
        std::cout<<test<<std::endl;
        test.beSigned(hamid);
        std::cout<<test<<std::endl;

    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return EXIT_SUCCESS;
}