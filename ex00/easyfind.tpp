#include <vector>
#include <algorithm>
template<typename T>
const typename T::iterator easyfind(T& a, int  nb)
{
	return (std::find(a.begin(),a.end(), nb)); 
}