#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string name, int grade)
    : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}


Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade)
{
    std::cout << "Constructor by copy" << std::endl;
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->grade = other.grade;
    return *this;
}


Bureaucrat::~Bureaucrat() 
{
    std::cout << "Destructor" << std::endl;
}


const std::string &Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}


void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}
