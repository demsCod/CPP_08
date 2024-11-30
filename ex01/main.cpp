#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour time()





int main()
{
    // Initialisation de l'objet Span avec une capacité de 10 000 nombres
    Span sp = Span(10000);

    // Ajout manuel de quelques nombres pour des cas simples
    sp.addNumber(42);  // Ajout d'un nombre "magique"
    sp.addNumber(5);   // Ajout d'un petit nombre
    sp.addNumber(1000); // Ajout d'un grand nombre

    // Vérification de base sur ces nombres manuels
    // Résultats attendus :
    // Shortest span: 37 (différence entre 42 et 5)
    // Longest span: 995 (différence entre 1000 et 5)
    std::cout << "Shortest span (cas manuel) : " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span (cas manuel) : " << sp.longestSpan() << std::endl;

    // Remplissage avec des valeurs aléatoires
    srand(time(0)); // Initialisation du générateur de nombres aléatoires
    for (int i = 0; i < 9997; ++i) {
        sp.addNumber(rand() % 100000); // Ajout de nombres aléatoires entre 0 et 99 999
    }

    // Vérification avec un grand nombre de valeurs
    // Résultats attendus (exemples) :
    // Shortest span: devrait être très petit, potentiellement 0 ou 1
    // Longest span: devrait être proche de 99 999 (si 0 et 99 999 sont générés)
    std::cout << "Shortest span (grand jeu de données) : " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span (grand jeu de données) : " << sp.longestSpan() << std::endl;

    // Test avec un seul nombre (devrait déclencher une exception)
    try {
        Span sp2 = Span(1);
        sp2.addNumber(15);
        std::cout << sp2.shortestSpan() << std::endl; // Erreur attendue
    } catch (const std::exception& e) {
        std::cout << "Exception capturée (shortestSpan avec un seul nombre) : " << e.what() << std::endl;
    }

    // Test avec aucun nombre (devrait également déclencher une exception)
    try {
        Span sp3 = Span(0);
        std::cout << sp3.longestSpan() << std::endl; // Erreur attendue
    } catch (const std::exception& e) {
        std::cout << "Exception capturée (longestSpan avec aucun nombre) : " << e.what() << std::endl;
    }


	try{
		Span sp = Span(10000);

    	// Test avec un vecteur
    	std::vector<int> vec;
		
		for (int i = 1; i <= 5; i++)
			vec.push_back(i * 10);
    	sp.fieldSpan<std::vector<int> >(vec.begin(), vec.end());
		// Vérification des résultats après ajout via fieldSpan
		// Résultats attendus :
		// Shortest span : 10 (différence entre 20 et 10)
		// Longest span : 40 (différence entre 50 et 10)
   		std::cout << "Shortest span (via vecteur) : " << sp.shortestSpan() << std::endl;
    	std::cout << "Longest span (via vecteur) : " << sp.longestSpan() << std::endl;

	}
	catch (const std::exception& e) {
    }


}