#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat
{
private:
    const std::string nom;
    int grade;

public:
    Bureaucrat(const std::string &nom, int grade);

    Bureaucrat(const Bureaucrat &other);

    Bureaucrat &operator=(const Bureaucrat &other);

    const std::string &getName() const;

    int getGrade() const;

    void incrementGrade();

    void decrementGrade();

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    ~Bureaucrat();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif