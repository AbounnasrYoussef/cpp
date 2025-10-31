#include <iostream>
#include <string>
#include <fstream>






int main(int ac , char **av)
{
    if(ac != 4)
    {
        std::cerr<< "error , entrer 3 parametre" << std::endl;
        return 1;
    }
    else 
    {
        std::string file = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];

        if(s1.empty())
        {
            std::cerr<< "error , s1 ne peut pas etres vide !"<< std::endl;
            return 1;
        }

        std::ifstream inputFile(file.c_str());
        if(!inputFile.is_open())
        {
            std::cerr<< "error , impossible d'ouvrir le fichier !" << std::endl;
            return 1;
        }

        std::ofstream outputFile((file + ".replace").c_str());
        if(!outputFile.is_open())
        {
            std::cout<< "error , impossible de creer le fichier !" << std::endl;
            return 1;
        }
        // Lire tout le contenu du fichier dans une string
        std::string content((std::istreambuf_iterator<char>(inputFile)),
                         std::istreambuf_iterator<char>());

         // Fermer le fichier d’entrée (bonne pratique)
        inputFile.close();

    // Remplacer toutes les occurrences de s1 par s2
        size_t pos = content.find(s1);
        while (pos != std::string::npos)
        {
            content = content.substr(0, pos) + s2 + content.substr(pos + s1.length());
            pos = content.find(s1, pos + s2.length());
        }

    // Écrire le contenu modifié dans le fichier de sortie
        outputFile << content;

     // Fermer le fichier de sortie
        outputFile.close();

        std::cout << " Remplacement terminé avec succès "<< std::endl;




    }
    return 0;
}