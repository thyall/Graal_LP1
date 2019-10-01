#include <iostream>

template <typename itr, typename Equal>
bool equal(itr first, itr last, itr first2, Equal eq)
{
	while(first != last)// a loço serve para procurar se os ranges diferem
	{ 
		// segue mesma logica das funções anteriores
		if(!eq(*first, *first2))// se a função eq retornar true é negado pelo "!"e não retorna false, se ela for false, ou seja, valores diferentes o if fica valido (True) e a função retorna false
			return false;
		else
		{
			first++;
			first2++;//percorrendo ambos ranges
		}
	}
	return true;//se as funções não forem diferentes retorna true
}

template <typename itr, typename Equal>
bool equal (itr first, itr last, itr first2, itr last2, Equal eq)
{
	auto x = last - first;
	auto y = last2 - first2;

	if(x != y)
		return false;

	while(first != last)// a loço serve para procurar se os ranges diferem
	{ 
		// segue mesma logica das funções anteriores
		if(!eq(*first, *first2))// se a função eq retornar true é negado pelo "!"e não retorna o false dentro do if, se ela for false, ou seja, valores diferentes o if fica valido (True) e a função retorna false
			return false;
		else
		{
			first++;
			first2++;//percorrendo ambos ranges
		}
	}
	return true;//se as funções não forem diferentes retorna true
}

//cliente
bool eq(const int &a, const int &b){return a == b;} 

int main()
{
	int A[] = {1,2,3,5,4,8,7,54,-5,3};
	int B[] = {1,2,3,5,4,8,7,54,-5,3};//vetor B igual a A
	int C[] = {1,3,5,7,9,11,13,15,17,19};
	
	auto ret = equal(std::begin(A), std::end(A), std::begin(B), eq);

	auto ret2 = equal(std::begin(A), std::end(A), std::begin(C), eq);

	auto ret3 = equal(std::begin(A), std::end(A), std::begin(B), std::end(B), eq);

	auto ret4 = equal(std::begin(A), std::end(A), std::begin(C), std::end(C), eq);


	std::cout << std::boolalpha << "Vetor A e B: " << ret << std::endl << "Vetor A e C: " << ret2 << std::endl;
	std::cout << std:: boolalpha <<  "Vetor A e B: " << ret3 << std::endl << "Vetor A e C: " << ret4 << std::endl;

	
	return 0;
}