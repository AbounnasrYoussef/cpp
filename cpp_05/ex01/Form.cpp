#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
** Pourquoi des exceptions imbriquees dans Form ?
**
** Chaque classe gere ses propres erreurs de grade de facon autonome.
** Form::GradeTooHighException et Form::GradeTooLowException sont semantiquement
** differentes de celles de Bureaucrat : ici l'erreur concerne le grade requis
** du formulaire, pas le grade de creation d'un bureaucrate.
** En les imbriquant dans Form, on peut distinguer precisement l'origine
** de l'exception (Form vs Bureaucrat) lors d'un catch.
*/

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: grade is too high (minimum is 1)";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: grade is too low (maximum is 150)";
}

/*
** Pourquoi valider les grades dans le constructeur ?
**
** Un formulaire avec un grade invalide n'a aucun sens metier.
** En lancant une exception des la construction, on garantit qu'aucun objet
** Form invalide ne peut exister dans le programme. C'est le principe du
** "fail fast" : mieux vaut planter tot qu'avoir un etat incoherent.
** Les attributs grades sont const donc ils ne peuvent jamais changer
** apres construction, ce qui renforce la coherence de l'objet.
*/
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < GRADE_MAX || gradeToExecute < GRADE_MAX)
        throw GradeTooHighException();
    if (gradeToSign > GRADE_MIN || gradeToExecute > GRADE_MIN)
        throw GradeTooLowException();
}

/*
** Pourquoi un constructeur de copie explicite quand on a des const members ?
**
** _name et _gradeToSign/_gradeToExecute sont const. Le compilateur ne peut pas
** les assigner dans le corps du constructeur : ils DOIVENT passer par la liste
** d'initialisation. Le constructeur de copie par defaut du compilateur fait
** exactement cela, mais il est bon de l'ecrire explicitement pour la forme 42.
** Note : _isSigned est volontairement copie depuis other (meme etat).
*/
Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

/*
** Pourquoi l'operateur= ne peut pas copier les membres const ?
**
** Les membres const (_name, _gradeToSign, _gradeToExecute) sont fixes
** a la construction et ne peuvent pas etre reassignes. L'operateur= ne peut donc
** modifier que _isSigned. C'est un comportement limite mais c'est la seule
** chose logiquement copiable. En pratique, copier un Form "signe" vers un autre
** propagera l'etat de signature, ce qui peut avoir du sens.
*/
Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const        { return _name; }
bool               Form::isSigned() const       { return _isSigned; }
int                Form::getGradeToSign() const { return _gradeToSign; }
int                Form::getGradeToExecute() const { return _gradeToExecute; }

/*
** Pourquoi beSigned prend un Bureaucrat par const reference ?
**
** On a besoin de lire le grade du bureaucrate (getGrade()), pas de le modifier.
** La reference const evite une copie inutile et signale clairement que
** la fonction ne modifie pas le bureaucrate. C'est du C++ idiomatique.
**
** Pourquoi lever GradeTooLowException et pas directement retourner false ?
**
** Le sujet impose une exception. De plus, les exceptions permettent a l'appelant
** (Bureaucrat::signForm) de distinguer proprement le succes de l'echec via
** try/catch, sans avoir a tester une valeur de retour booleenne.
** Le grade 1 est le plus haut (plus le nombre est petit, plus le grade est eleve).
*/
void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

/*
** Pourquoi surcharger operator<< ?
**
** Permet d'afficher un Form avec std::cout << form de facon naturelle,
** sans appeler manuellement chaque getter. C'est du polymorphisme d'affichage
** idiomatique en C++. On retourne l'ostream& pour permettre le chaining
** (cout << a << b << endl).
*/
std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form [" << form.getName() << "]"
       << " | Signed: " << (form.isSigned() ? "yes" : "no")
       << " | Grade to sign: " << form.getGradeToSign()
       << " | Grade to execute: " << form.getGradeToExecute();
    return os;
}
