#include <iostream>
template<typename itr>
itr rotate(itr first, itr n_first, itr last)
{
	auto aux = n_first;//passando o valor de n_first para uma variavel auxiliar

	while(aux!=last)
	{
		std::swap(*first, *aux);
		first++;
		aux++;
	}
	return first;
}


//cliente
int main()
{
	int A[] = {1,2,3,5,4,8,7,54,-5,12};

	std::cout << "Antes:" << std::endl;
	for(int i = 0; i < 10; ++i)
	{
	  std::cout << A[i] << " ";
	}std::cout << std::endl;

	auto a = rotate(std::begin(A), std::begin(A)+4, std::end(A));

	std::cout << "Depois:" << std::endl;
	for(int i = 0; i < 10; ++i)
	{
	  std::cout << A[i] << " ";
	}std::cout << std::endl;

	std::cout << "Ponteiro apontando para o primeiro elemento apos a rotação do vetor:" << std::endl << *a << std::endl;
	return 0;

}