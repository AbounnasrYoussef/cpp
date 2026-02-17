#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name("default"), grade(LOWEST_GRADE)
{
    std::cout << "default constructor called" << std::endl;
}


Bureaucrat::Bureaucrat(const std::string& name, int _grade) : name(name)
{

    std::cout << "constuctor by parametre called" << std::endl;

    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw GradeTooLowException();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name) , grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat assignement operator called" << std::endl;

    if (this != &other)
    {
        grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destuctor called " << name <<std::endl;
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const{
    return grade;
}

void  Bureaucrat::incrementeGrade()
{
    std::cout << name << "tries to increment grade from " << grade;

    if (grade - 1 < 1)
    {
        std::cout << "Execption " << std::endl;
        throw GradeTooHighException();
    }
    grade--;
    std::cout << " to " << grade << std::endl;
}

void  Bureaucrat::decrementeGrade()
{
    std::cout << name << "tries to decrement grade from " << grade;

    if (grade + 1 > 150)
    {
        std::cout << "Execption " << std::endl;
        throw GradeTooLowException();
    }
    grade++;
    std::cout << " to " << grade << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high , must be >= 1";
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low , must be <= 150";
}

std::ostream& operator<<(std::ostream& out , const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
