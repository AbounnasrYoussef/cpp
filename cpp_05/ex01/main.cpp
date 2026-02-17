#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

/*
** Structure des tests :
** Chaque bloc teste un cas precis isole.
** On utilise try/catch pour que l'echec d'un test n'interrompe pas les suivants.
** L'affichage manuel des separateurs aide a reperer rapidement quel cas echoue.
*/

static void printSeparator(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========" << std::endl;
}

int main()
{
    // -----------------------------------------------------------------------
    // TEST 1 : Construction valide d'un Form
    // Verifie que le constructeur accepte des grades dans [1..150]
    // et que l'etat initial (non signe) est correct.
    // -----------------------------------------------------------------------
    printSeparator("TEST 1 - Construction valide d'un Form");
    try
    {
        Form f("Tax Return", 50, 25);
        std::cout << f << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "ERREUR inattendue : " << e.what() << std::endl;
    }

    // -----------------------------------------------------------------------
    // TEST 2 : Grade trop haut a la construction (gradeToSign = 0)
    // Doit lancer Form::GradeTooHighException.
    // -----------------------------------------------------------------------
    printSeparator("TEST 2 - Grade trop haut a la construction");
    try
    {
        Form f("Bad Form", 0, 50);
        std::cout << "ERREUR : aucune exception lancee" << std::endl;
    }
    catch (const Form::GradeTooHighException& e)
    {
        std::cout << "Exception correcte : " << e.what() << std::endl;
    }

    // -----------------------------------------------------------------------
    // TEST 3 : Grade trop bas a la construction (gradeToExecute = 151)
    // Doit lancer Form::GradeTooLowException.
    // -----------------------------------------------------------------------
    printSeparator("TEST 3 - Grade trop bas a la construction");
    try
    {
        Form f("Bad Form", 50, 151);
        std::cout << "ERREUR : aucune exception lancee" << std::endl;
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cout << "Exception correcte : " << e.what() << std::endl;
    }

    // -----------------------------------------------------------------------
    // TEST 4 : Signature reussie
    // Un bureaucrate de grade 10 signe un form qui requiert grade 50.
    // Grade 10 <= 50 donc il est suffisamment haut.
    // Rappel : grade 1 est le PLUS haut, grade 150 le PLUS bas.
    // -----------------------------------------------------------------------
    printSeparator("TEST 4 - Signature reussie");
    try
    {
        Bureaucrat alice("Alice", 10);
        Form f("Budget Approval", 50, 30);
        std::cout << alice << std::endl;
        std::cout << f << std::endl;
        alice.signForm(f);
        std::cout << f << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "ERREUR inattendue : " << e.what() << std::endl;
    }

    // -----------------------------------------------------------------------
    // TEST 5 : Signature echouee (grade trop bas)
    // Un bureaucrate de grade 100 tente de signer un form qui requiert grade 50.
    // Grade 100 > 50 donc il n'est PAS assez haut.
    // signForm doit afficher le message d'echec sans planter le programme.
    // -----------------------------------------------------------------------
    printSeparator("TEST 5 - Signature echouee (grade insuffisant)");
    try
    {
        Bureaucrat bob("Bob", 100);
        Form f("Classified Report", 50, 25);
        std::cout << bob << std::endl;
        bob.signForm(f);
        std::cout << f << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "ERREUR inattendue : " << e.what() << std::endl;
    }

    // -----------------------------------------------------------------------
    // TEST 6 : Signature avec grade exactement egal au requis (grade 50 = grade 50)
    // Verifie le cas limite : "greater than or equal to the required one".
    // -----------------------------------------------------------------------
    printSeparator("TEST 6 - Signature avec grade exactement egal au requis");
    try
    {
        Bureaucrat charlie("Charlie", 50);
        Form f("Permit", 50, 100);
        charlie.signForm(f);
        std::cout << f << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "ERREUR inattendue : " << e.what() << std::endl;
    }

    // -----------------------------------------------------------------------
    // TEST 7 : Affichage complet via operator<<
    // Verifie que toutes les infos sont bien affichees.
    // -----------------------------------------------------------------------
    printSeparator("TEST 7 - Affichage operator<<");
    try
    {
        Bureaucrat d("Dave", 1);
        Form f("Master Form", 1, 1);
        std::cout << d << std::endl;
        std::cout << f << std::endl;
        d.signForm(f);
        std::cout << f << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "ERREUR inattendue : " << e.what() << std::endl;
    }

    // -----------------------------------------------------------------------
    // TEST 8 : Construction invalide de Bureaucrat (grade 0)
    // Rappel des regles Bureaucrat pour montrer la coherence avec Form.
    // -----------------------------------------------------------------------
    printSeparator("TEST 8 - Bureaucrat grade invalide");
    try
    {
        Bureaucrat e("Eve", 0);
        std::cout << "ERREUR : aucune exception lancee" << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Exception correcte : " << e.what() << std::endl;
    }

    return 0;
}
