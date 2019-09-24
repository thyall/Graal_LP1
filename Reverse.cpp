#include <iostream>

template <typename itr>
void reverse(itr first, itr last)
{
	while(first != last) //percorrendo o range
	{
		std::swap(*first, *(last-1)); // é usado last menos 1 para não pegar "lixo", pois o std::end aponta para um endereço a frente do vetor

		first++;
		last--;
	}	
}


//cliente
int main()
{
	int A[] = {1,2,3,5,4,8,7,54,-5,3};

	std::cout<< "Antes: ";	
	for(int i = 0; i < 10; ++i)
	{
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	reverse(std::begin(A), std::end(A));

	std::cout<< "Depois: ";	
	for(int i = 0; i < 10; ++i)
	{
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}