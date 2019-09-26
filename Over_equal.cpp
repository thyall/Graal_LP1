#include <iostream>

template <typename itr, typename Equal>
bool equal(itr first, itr last, itr first2, Equal eq)
{
	while(first != last)// a loço serve para procurar se os ranges diferem
	{ 
		// segue mesma logica das funções anteriores
		if(!eq(*first, *first2))// se a função eq retornar true, se ela for false, ou seja, valores diferentes o if fica valido "True" e a função retorna false
			return false;
		else
		{
			first++;
			first2++;//percorrendo ambos ranges
		}
	}
	return true;//se o valor da função não for achado no range a função retornar last
}


////---------------> tentnado entender a logica do outra para ter o overload<-------------

/*template <typename itr, typename equal>
bool equal (itr first, itr last, itr first2, itr last2, equal eq)*/

////---------------> tentnado entender a logica do outra para ter o overload<-------------


//cliente
bool eq(const int &a, const int &b){return a == b;} 

int main(int argc, char const *argv[])
{
	int A[] = {1,2,3,5,4,8,7,54,-5,3};
	int B[] = {1,2,3,5,4,8,7,54,-5,3};
	int C[] = {1,3,5,7,9,11,13,15,17,19};
	
	auto ret = equal(std::begin(A), std::end(A), std::begin(B), eq);

	auto ret2 = equal(std::begin(A), std::end(A), std::begin(C), eq);

	std::cout << "Por convensão o programa retorna 1 para True e 0 para False:" << std::endl;
	std::cout << "Vetor A e B: " << ret << std::endl << "Vetor A e C: " << ret2 << std::endl;
	
	return 0;
}