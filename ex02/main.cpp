#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    // Test des méthodes de base
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Test des itérateurs normaux
    std::cout << "Iterating with normal iterators:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test des itérateurs constants
    std::cout << "Iterating with const iterators:" << std::endl;
    for (MutantStack<int>::const_iterator cit = mstack.cbegin(); cit != mstack.cend(); ++cit)
    {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    // Test des itérateurs inversés
    std::cout << "Iterating with reverse iterators:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
    {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Test des itérateurs constants inversés
    std::cout << "Iterating with const reverse iterators:" << std::endl;
    for (MutantStack<int>::const_reverse_iterator crit = mstack.rbegin(); crit != mstack.rend(); ++crit)
    {
        std::cout << *crit << " ";
    }
    std::cout << std::endl;

    // Comparaison avec std::list
    std::cout << "Testing with std::list:" << std::endl;
    std::list<int> lstack;
    lstack.push_back(5);
    lstack.push_back(17);
    lstack.pop_back();
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    lstack.push_back(0);
    for (std::list<int>::iterator lit = lstack.begin(); lit != lstack.end(); ++lit)
    {
        std::cout << *lit << " ";
    }
    std::cout << std::endl;

    return 0;
}
