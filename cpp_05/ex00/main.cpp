#include "Bureaucrat.hpp"
#include <iostream>

// ============================================================================
// FONCTION UTILITAIRE POUR LES TESTS
// ============================================================================

void printSeparator(const std::string& testName) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST: " << testName << std::endl;
    std::cout << "========================================" << std::endl;
}


// ============================================================================
// TEST 1 : Construction valide
// ============================================================================

void test1_validConstruction() {
    printSeparator("Construction valide");
    
    try {
        Bureaucrat b1("Alice", 1);      // Meilleur grade
        Bureaucrat b2("Bob", 75);       // Grade moyen
        Bureaucrat b3("Charlie", 150);  // Pire grade
        
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << b3 << std::endl;
        
        std::cout << "✓ Tous les bureaucrates créés avec succès!" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "✗ Exception inattendue: " << e.what() << std::endl;
    }
}


// ============================================================================
// TEST 2 : Grade trop haut à la construction
// ============================================================================

void test2_gradeTooHigh() {
    printSeparator("Grade trop haut à la construction");
    
    // Test avec grade 0
    try {
        std::cout << "Tentative de créer un bureaucrate avec grade 0..." << std::endl;
        Bureaucrat b("Too Good", 0);
        std::cout << "✗ ERREUR : Aucune exception lancée!" << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "✓ Exception correctement capturée: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "✗ Mauvaise exception: " << e.what() << std::endl;
    }
    
    // Test avec grade -42
    try {
        std::cout << "\nTentative de créer un bureaucrate avec grade -42..." << std::endl;
        Bureaucrat b("Super Good", -42);
        std::cout << "✗ ERREUR : Aucune exception lancée!" << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "✓ Exception correctement capturée: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "✗ Mauvaise exception: " << e.what() << std::endl;
    }
}


// ============================================================================
// TEST 3 : Grade trop bas à la construction
// ============================================================================

void test3_gradeTooLow() {
    printSeparator("Grade trop bas à la construction");
    
    // Test avec grade 151
    try {
        std::cout << "Tentative de créer un bureaucrate avec grade 151..." << std::endl;
        Bureaucrat b("Too Bad", 151);
        std::cout << "✗ ERREUR : Aucune exception lancée!" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "✓ Exception correctement capturée: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "✗ Mauvaise exception: " << e.what() << std::endl;
    }
    
    // Test avec grade 200
    try {
        std::cout << "\nTentative de créer un bureaucrate avec grade 200..." << std::endl;
        Bureaucrat b("Very Bad", 200);
        std::cout << "✗ ERREUR : Aucune exception lancée!" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "✓ Exception correctement capturée: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "✗ Mauvaise exception: " << e.what() << std::endl;
    }
}


// ============================================================================
// TEST 4 : Incrémenter le grade (amélioration)
// ============================================================================

void test4_incrementGrade() {
    printSeparator("Incrémenter le grade");
    
    try {
        Bureaucrat b("David", 5);
        std::cout << "Initial: " << b << std::endl;
        
        // Incrémenter plusieurs fois (5 -> 4 -> 3 -> 2)
        b.incrementeGrade();
        std::cout << "Après 1 increment: " << b << std::endl;
        
        b.incrementeGrade();
        std::cout << "Après 2 increments: " << b << std::endl;
        
        b.incrementeGrade();
        std::cout << "Après 3 increments: " << b << std::endl;
        
        std::cout << "✓ Incrémentations réussies!" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "✗ Exception inattendue: " << e.what() << std::endl;
    }
}


// ============================================================================
// TEST 5 : Décrémenter le grade (dégradation)
// ============================================================================

void test5_decrementGrade() {
    printSeparator("Décrémenter le grade");
    
    try {
        Bureaucrat b("Eve", 146);
        std::cout << "Initial: " << b << std::endl;
        
        // Décrémenter plusieurs fois (146 -> 147 -> 148 -> 149)
        b.decrementeGrade();
        std::cout << "Après 1 decrement: " << b << std::endl;
        
        b.decrementeGrade();
        std::cout << "Après 2 decrements: " << b << std::endl;
        
        b.decrementeGrade();
        std::cout << "Après 3 decrements: " << b << std::endl;
        
        std::cout << "✓ Décrémentations réussies!" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "✗ Exception inattendue: " << e.what() << std::endl;
    }
}


// ============================================================================
// TEST 6 : Incrémenter au-delà du grade maximum
// ============================================================================

void test6_incrementBeyondMax() {
    printSeparator("Incrémenter au-delà du grade maximum");
    
    try {
        Bureaucrat b("Frank", 1);
        std::cout << "Bureaucrate avec grade 1 (meilleur possible)" << std::endl;
        std::cout << b << std::endl;
        
        std::cout << "\nTentative d'incrémenter encore..." << std::endl;
        b.incrementeGrade();  // Devrait lancer une exception
        
        std::cout << "✗ ERREUR : Aucune exception lancée!" << std::endl;
        std::cout << b << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "✓ Exception correctement capturée: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "✗ Mauvaise exception: " << e.what() << std::endl;
    }
}


// ============================================================================
// TEST 7 : Décrémenter au-delà du grade minimum
// ============================================================================

void test7_decrementBeyondMin() {
    printSeparator("Décrémenter au-delà du grade minimum");
    
    try {
        Bureaucrat b("Grace", 150);
        std::cout << "Bureaucrate avec grade 150 (pire possible)" << std::endl;
        std::cout << b << std::endl;
        
        std::cout << "\nTentative de décrémenter encore..." << std::endl;
        b.decrementeGrade();  // Devrait lancer une exception
        
        std::cout << "✗ ERREUR : Aucune exception lancée!" << std::endl;
        std::cout << b << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "✓ Exception correctement capturée: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "✗ Mauvaise exception: " << e.what() << std::endl;
    }
}


// ============================================================================
// TEST 8 : Constructeur de copie
// ============================================================================

void test8_copyConstructor() {
    printSeparator("Constructeur de copie");
    
    try {
        Bureaucrat original("Henry", 42);
        std::cout << "Original: " << original << std::endl;
        
        Bureaucrat copie(original);
        std::cout << "Copie: " << copie << std::endl;
        
        // Modifier la copie ne doit pas affecter l'original
        copie.incrementeGrade();
        std::cout << "\nAprès increment de la copie:" << std::endl;
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copie: " << copie << std::endl;
        
        std::cout << "✓ Constructeur de copie fonctionne correctement!" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "✗ Exception: " << e.what() << std::endl;
    }
}


// ============================================================================
// TEST 9 : Opérateur d'affectation
// ============================================================================

void test9_assignmentOperator() {
    printSeparator("Opérateur d'affectation");
    
    try {
        Bureaucrat b1("Iris", 10);
        Bureaucrat b2("Jack", 100);
        
        std::cout << "Avant affectation:" << std::endl;
        std::cout << "b1: " << b1 << std::endl;
        std::cout << "b2: " << b2 << std::endl;
        
        b2 = b1;  // Affectation
        
        std::cout << "\nAprès b2 = b1:" << std::endl;
        std::cout << "b1: " << b1 << std::endl;
        std::cout << "b2: " << b2 << std::endl;
        
        // ⚠️ NOTE : Le nom ne change pas car il est const !
        std::cout << "\n⚠️  Remarque: Le nom de b2 n'a pas changé (attribut const)" << std::endl;
        
        std::cout << "✓ Opérateur d'affectation fonctionne!" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "✗ Exception: " << e.what() << std::endl;
    }
}


// ============================================================================
// TEST 10 : Capture avec std::exception&
// ============================================================================

void test10_catchWithStdException() {
    printSeparator("Capture avec std::exception&");
    
    std::cout << "Test 1: Grade trop haut" << std::endl;
    try {
        Bureaucrat b("Test", 0);
    }
    catch (std::exception& e) {
        // ⚠️ Doit pouvoir capturer avec std::exception&
        std::cout << "✓ Capturé avec std::exception&: " << e.what() << std::endl;
    }
    
    std::cout << "\nTest 2: Grade trop bas" << std::endl;
    try {
        Bureaucrat b("Test", 151);
    }
    catch (std::exception& e) {
        std::cout << "✓ Capturé avec std::exception&: " << e.what() << std::endl;
    }
    
    std::cout << "\nTest 3: Increment trop haut" << std::endl;
    try {
        Bureaucrat b("Test", 1);
        b.incrementeGrade();
    }
    catch (std::exception& e) {
        std::cout << "✓ Capturé avec std::exception&: " << e.what() << std::endl;
    }
    
    std::cout << "\nTest 4: Decrement trop bas" << std::endl;
    try {
        Bureaucrat b("Test", 150);
        b.decrementeGrade();
    }
    catch (std::exception& e) {
        std::cout << "✓ Capturé avec std::exception&: " << e.what() << std::endl;
    }
}


// ============================================================================
// TEST 11 : Scénario complexe
// ============================================================================

void test11_complexScenario() {
    printSeparator("Scénario complexe");
    
    std::cout << "Simulation d'un système bureaucratique complet\n" << std::endl;
    
    try {
        // Créer plusieurs bureaucrates
        Bureaucrat chef("Chef", 5);
        Bureaucrat employe("Employé", 100);
        Bureaucrat stagiaire("Stagiaire", 145);
        
        std::cout << "État initial:" << std::endl;
        std::cout << "  " << chef << std::endl;
        std::cout << "  " << employe << std::endl;
        std::cout << "  " << stagiaire << std::endl;
        
        // Promotions et rétrogradations
        std::cout << "\n--- Promotions et rétrogradations ---" << std::endl;
        
        std::cout << "L'employé fait du bon travail:" << std::endl;
        for (int i = 0; i < 5; i++) {
            employe.incrementeGrade();
        }
        std::cout << "  " << employe << std::endl;
        
        std::cout << "\nLe stagiaire fait des erreurs:" << std::endl;
        for (int i = 0; i < 3; i++) {
            stagiaire.decrementeGrade();
        }
        std::cout << "  " << stagiaire << std::endl;
        
        std::cout << "\nLe chef obtient une reconnaissance exceptionnelle:" << std::endl;
        for (int i = 0; i < 4; i++) {
            chef.incrementeGrade();
        }
        std::cout << "  " << chef << std::endl;
        
        // Tenter une promotion impossible
        std::cout << "\nTentative de promouvoir encore le chef..." << std::endl;
        chef.incrementeGrade();  // Exception!
        
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "✓ Limite atteinte: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "✓ Limite atteinte: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}


// ============================================================================
// PROGRAMME PRINCIPAL
// ============================================================================

int main() {
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║   TESTS DE LA CLASSE BUREAUCRAT       ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    
    // Exécuter tous les tests
    test1_validConstruction();
    test2_gradeTooHigh();
    test3_gradeTooLow();
    test4_incrementGrade();
    test5_decrementGrade();
    test6_incrementBeyondMax();
    test7_decrementBeyondMin();
    test8_copyConstructor();
    test9_assignmentOperator();
    test10_catchWithStdException();
    test11_complexScenario();
    
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║        TOUS LES TESTS TERMINÉS         ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    
    return 0;
}


/*
 * ============================================================================
 * RÉSUMÉ DES TESTS
 * ============================================================================
 * 
 * Test 1  : Construction avec grades valides (1, 75, 150)
 * Test 2  : Grade trop haut à la construction (0, -42)
 * Test 3  : Grade trop bas à la construction (151, 200)
 * Test 4  : Incrémenter le grade normalement
 * Test 5  : Décrémenter le grade normalement
 * Test 6  : Tenter d'incrémenter un grade 1 (exception)
 * Test 7  : Tenter de décrémenter un grade 150 (exception)
 * Test 8  : Constructeur de copie
 * Test 9  : Opérateur d'affectation
 * Test 10 : Capture avec std::exception&
 * Test 11 : Scénario complexe avec multiples opérations
 * 
 * ============================================================================
 * COMPILATION ET EXÉCUTION
 * ============================================================================
 * 
 * Compilation:
 *   c++ -Wall -Wextra -Werror -std=c++98 main.cpp Bureaucrat.cpp -o bureaucrat
 * 
 * Ou avec C++11:
 *   c++ -Wall -Wextra -Werror -std=c++11 main.cpp Bureaucrat.cpp -o bureaucrat
 * 
 * Exécution:
 *   ./bureaucrat
 * 
 * ============================================================================
 */
