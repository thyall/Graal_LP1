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
	//int A[] = {1,2,3,5,4,8,7,54,-5,3}; funcionado para os dois vetores
	double B[] = {2.5, 3.4, 4.8, 8.8,-3.2, -1.5, 10.89, 7.8, 5.5,45.8};

	std::cout<< "Antes: ";	
	for(int i = 0; i < 10; ++i)
	{
		std::cout << B[i] << " ";
	}
	std::cout << std::endl;

	reverse(std::begin(B), std::end(B));

	std::cout<< "Depois: ";	
	for(int i = 0; i < 10; ++i)
	{
		std::cout << B[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}