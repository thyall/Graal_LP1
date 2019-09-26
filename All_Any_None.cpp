#include <iostream>
template <typename itr, typename predicate>
bool all_of(itr first, itr last, predicate p)// Retorna True se todos os elementos do range estiverem de acordo com p
{
	while(first!=last)
	{
		// aqui estou fazendo a negação da negação (pois retorna false)
		if(!p(*first)){return false;}// se a função reotrna true (o dado satisfaz a predicado) será false o laço continua, se ela retornar false será true retorna False e sai do laço

		else
			first++;
	}

	return true;
}

template <typename itr, typename predicate>
bool any_of(itr first, itr last, predicate p)// Retorna True se algum elemento do range estiver de acordo com p
{
	while(first!=last)
	{
		if(p(*first)){return true;}

		else
			first++;
	}

	return false;	
}

template <typename itr, typename predicate>
bool none_of(itr first, itr last, predicate p)// Retorna True se todos os elementos do range NÃO estiverem de acordo com p
{
	while(first!=last)//logica ao contrario da All
	{
		if(p(*first)){return false;}

		else
			first++;
	}

	return true;
}





//cliente
bool p(const int &a){ return a%2 == 0;}//Aqui passamos um predicado para saber se o valor passado é par
int main(int argc, char const *argv[])
{
	int A[] = {1,2,3,5,4,8,7,54,-5,3};
	int B[] = {2, 4, 6, 8, 54, -6, 36, 16, 20, 100};
	int C[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  
	std::cout << "Por convensão o programa retorna 1 para True e 0 para False:" << std::endl;
	auto a1 = all_of(std::begin(A), std::end(A), p);
	auto a2 = any_of(std::begin(A), std::end(A), p);
	auto a3 = none_of(std::begin(A), std::end(A), p);
	std::cout <<"all de A: " << a1 << " any de A: "<< a2 << " None de A: "<< a3 << std::endl;

	auto b1 = all_of(std::begin(B), std::end(B), p);
	auto b2 = any_of(std::begin(B), std::end(B), p);
	auto b3 = none_of(std::begin(B), std::end(B), p);
	std::cout <<"all de B: " << b1 << " any de B: "<< b2 << " None de B: " << b3 << std::endl;

	auto c1 = all_of(std::begin(C), std::end(C), p);
	auto c2 = any_of(std::begin(C), std::end(C), p);
	auto c3 = none_of(std::begin(C), std::end(C), p);
	std::cout <<"all de C: " << c1 << " any de C: "<< c2 << " None de C: " << c3 << std::endl;

	return 0;
}