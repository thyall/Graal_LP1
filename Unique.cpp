#include <iostream>

template <typename itr, typename equal >
itr unique (itr first, itr last, equal eq)
{
	auto val = first;
	while(first!=last)
	{	
		if(!eq(*val == *first))
		{	

		}
		

	}

}



//cliente
bool eq(const int &a, const int &b){return a == b;} 
int main()
{
	int A[] = {1,1,2,2,3,3,5,5,4,8,7,54,-5,3};

	auto ret = find(std::begin(A), std::end(A),  eq);

	std::cout << *ret << std::endl;
	
	return 0;
}