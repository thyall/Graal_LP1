#include <iostream>

template <typename itr>
itr copy(itr first, itr last, itr d_first)
{	
	while(first != last)
	{
		d_first = first;
		first++;
		d_first++;
	}

	return d_first-1;
}




//cliente
int main(int argc, char const *argv[])
{
	int *retur; 

	int A[] = {1,2,3,5,4,8,7,54,-5,3};

	std::cout<< "Antes: ";	
	for(int i = 0; i < 10; ++i)
	{
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	retur = copy(std::begin(A), std::end(A), std::begin(A));

	std::cout << *retur <<std::endl;
	
	return 0;
}