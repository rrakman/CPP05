#include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
    if(this != &ref)
        target = ref.target;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref): AForm("ShrubberyCreationForm", 145, 137)
{
    *this = ref;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if(this->get_is_signed())
    {
        if(this->get_grade_to_exec() > executor.get_grade())
        {
            std::string filename = target + "_shrubbery";
            std::ofstream Myfile (filename.c_str());
            if(Myfile.is_open())
            {
                std::string tree = 
                "\n       _-_\n"
                "    /~~   ~~\\\n"
                " /~~         ~~\\\n"
                "{               }\n"
                " \\  _-     -_  /\n"
                "   ~  \\ //  ~\n"
                "_- -   | | _- _\n"
                "  _ -  | |   -_\n"
                "      // \\\n";
                Myfile << tree;
                Myfile.close();
            }
            else
                std::cerr << "Error, during opening the file." << std::endl;
        }
        else
            throw AForm::GradeTooLowException();
    }
    else
    {
        throw AForm::Not_Signed();
    }

}

std::string ShrubberyCreationForm::get_target() const
{
    return target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}