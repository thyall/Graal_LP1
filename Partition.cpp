#include <iostream>
template <typename itr, typename p>
itr partition(itr first, itr last, p pred)
{
	auto x = --last;//last aponta para frnete do do ultimo lugar mas queremos o ultimo valor 

	while (first!=last)//laço para percorrer o vetor
	{
		while(!pred(*x))//se não satisfazer o predica ele irá retornar first se for igual a 'x' ou seja chegar no inicio
		{// e também ira decrescer o 'x' que no momento aponta para o ultimo valor
			if(first==x)
				return first;//função retornando first apontando para o primeiro valor pós partição
			x--;
		}

		std::swap(*first, *x);// se o predicado retornar true no while, a funçao vem pra essa linha e troca os valores
		first++;// e acrescenta o first para continuar o laço
	}  	
	return first;//função retornando first apontando para o primeiro valor pós partição
}





//cliente
bool p(const int &a){ return a%2 == 0;}//Aqui passamos um predicado para saber se o valor passado é par
int main(int argc, char const *argv[])
{
	int A[] = {1,2,3,5,4,8,7,54,-5,3};

	std::cout << "Por convensão o programa retorna 1 para True e 0 para False:" << std::endl;

	auto a = partition(std::begin(A), std::end(A), p);

	//std::swap(A[2], A[5]);

	for(int i = 0; i < 10; ++i)
	{
	  std::cout << A[i] << " ";
	}std::cout << std::endl;

	std::cout << "Ponteiro apontando para o primeiro elemento apos a particição do vetor:" << std::endl << *a << std::endl;
	return 0;
}