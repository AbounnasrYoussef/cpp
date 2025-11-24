📘 CPP Modules 00 → 04 — Résumé & Guide (42 School)

Ce dépôt contient mes travaux réalisés dans le cadre des modules C++ (CPP00 → CPP04) de l'école 42.
Ces exercices constituent une introduction progressive aux concepts fondamentaux de la programmation orientée objet en C++.

🧩 CPP00 — Bases du langage & Orthodox Canonical Form
🎯 Objectif du module

Découvrir les bases de la syntaxe C++ et les premières règles de la POO.

🔑 Concepts abordés

Namespace

std::cout / std::cin

Classes vs. objets

Membres publics/privés

Constructeurs / destructeurs

Forme canonique orthodoxe (OCF) :

Constructeur par défaut

Constructeur de copie

Opérateur d’affectation

Destructeur

Pointeurs sur objets, références

Application pratique : PhoneBook, Contacts

🧩 CPP01 — Allocation, pointeurs, références & lifecycle
🎯 Objectif du module

Comprendre la différence entre stack et heap, la gestion de la mémoire et le comportement des objets.

🔑 Concepts abordés

new / delete

Références vs pointeurs

Lifecycle d’un objet

Fonctions membres

Introduction à l’allocation dynamique

Zombie, Weapon, HumanA / HumanB

🧩 CPP02 — Fixe-point, surcharge opérateurs & orthodox canonical form
🎯 Objectif du module

Apprendre la surcharge d’opérateurs et manipuler les nombres à virgule fixe.

🔑 Concepts abordés

Surcharge d’opérateurs :

operator+, operator-, operator*, operator/

operator<<

Incrémentation / décrémentation

Constructeurs / opérateurs de copie (forme canonique)

Nombres à virgule fixe

Encapsulation

Classe Fixed

🧩 CPP03 — Héritage & polymorphisme statique
🎯 Objectif du module

Apprendre à construire une hiérarchie de classes et réutiliser le code via l'héritage.

🔑 Concepts abordés

Héritage simple

protected vs private

Constructeurs dérivés & ordre de construction

Appels aux fonctions de la classe mère

Polymorphisme statique (surcharge, early-binding)

Exercices : ClapTrap, ScavTrap, FragTrap, DiamondTrap

🧩 CPP04 — Polymorphisme dynamique & classes abstraites
🎯 Objectif du module

Maîtriser le polymorphisme dynamique, le runtime binding, et les classes abstraites.

🔑 Concepts abordés

Fonctions virtuelles

destructeur virtuel

override

Abstract classes (virtual void func() = 0)

VTable / Virtual dispatch

Deep copy vs shallow copy

Composition : Brain dans Dog et Cat

WrongAnimal / WrongCat → démonstration du polymorphisme incorrect

🧠 Résumé des compétences acquises

✔ Syntaxe C++ moderne (C++98 pour les projets 42)
✔ Gestion mémoire manuelle (stack vs heap)
✔ Structures orientées objet complètes
✔ Héritage & polymorphisme
✔ Constructeurs + forme canonique
✔ Surcharge d’opérateurs
✔ Classes abstraites & virtualisation
✔ Composition d’objets (Brain)
✔ Compréhension interne : vtable, binding dynamique

▶️ Comment compiler

Chaque exercice possède son propre Makefile, typiquement :

make
./executable
make clean

📦 Structure du dépôt
CPP00/
CPP01/
CPP02/
CPP03/
CPP04/


Chaque dossier contient :

Les fichiers .hpp et .cpp

Un Makefile propre

Des tests démontrant le comportement demandé

🧑‍💻 Auteur

Projet réalisé dans le cadre du cursus 42
youssef abounnasr
