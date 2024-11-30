#pragma once
#include <vector>

class Span 
{
	private :
		std::vector<int> vec;
		unsigned int size;
		unsigned int i;
	public :
		Span(unsigned int N);
		void addNumber(int number);
		int longestSpan(void);
		int shortestSpan(void);
		template<typename T>
		void fieldSpan(typename T::iterator begin, typename T::iterator end)
		{
			while(begin != end)
			{
				this->addNumber(*begin);
				begin++;
			}
		}
		~Span();
};