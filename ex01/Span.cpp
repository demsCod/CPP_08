#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <iostream>


Span::Span(unsigned int N) : size(N) , i(0)
{
}



void Span::addNumber(int number)
{
	if (i < size)
	{
		vec.push_back(number);
		i++;
	}
	else
		throw std::exception();
}
Span::~Span()
{
}


 int Span::longestSpan(void)
 {
	if (i < 2)
		throw std::exception();
	std::vector<int>::iterator a = std::min_element(vec.begin(), vec.end());
	std::vector<int>::iterator b = std::max_element(vec.begin(), vec.end());
	return(*b - *a);
 }


 int Span::shortestSpan(void)
 {
	if (i < 2)
		throw std::exception();
	std::sort(vec.begin(), vec.end());
	int shortest = *(vec.begin() + 1 ) - (*vec.begin());
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if ((it + 1) == vec.end())
			break;
		if ((*(it + 1 ) - (*it)) < shortest)
		{
			shortest =  (*(it + 1 ) - (*it));
			//std::cout << shortest << std::endl;
		}
	}
	return shortest;

 }