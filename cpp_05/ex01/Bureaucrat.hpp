#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
public:
    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string&  getName() const;
    int                 getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(Form& form);

private:
    const std::string   _name;
    int                 _grade;

    static const int    GRADE_MAX = 1;
    static const int    GRADE_MIN = 150;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
