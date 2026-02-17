#include "Bureaucrat.hpp"
#include "Form.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat: grade is too high (minimum is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat: grade is too low (maximum is 150)";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name), _grade(grade)
{
    if (_grade < GRADE_MAX)
        throw GradeTooHighException();
    if (_grade > GRADE_MIN)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const  { return _name; }
int                Bureaucrat::getGrade() const  { return _grade; }

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < GRADE_MAX)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > GRADE_MIN)
        throw GradeTooLowException();
    _grade++;
}

/*
** Pourquoi signForm catch et affiche le message plutot que de relancer ?
**
** signForm est le point d'entree "utilisateur" de cette interaction.
** Son role est de tenter la signature ET de rapporter le resultat de facon
** lisible. Si on relancait l'exception, l'appelant (main) devrait la catcher
** lui-meme et gerer l'affichage, ce qui disperse la responsabilite.
** En catchant ici, on respecte le principe de responsabilite unique :
** signForm sait afficher ce qui se passe lors d'une tentative de signature.
** L'exception est "consommee" car son information est convertie en message.
*/
void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
