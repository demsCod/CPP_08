#include "easyfind.hpp"
#include <iostream>

int main(void)
{
	std::vector<int> a(1, 1);


	for (int i = 0; i < 10; i++)
		a.push_back(i);
	a.push_back(42);
	if (easyfind(a, 47) != a.end())
		std::cout << "find !!\n";
	else 
		std::cout << "Not find\n";
	
}