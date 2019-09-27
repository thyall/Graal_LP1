#include <iostream>
#include <iostream>

template <typename Itr , typename T, typename Equal>
Itr find(Itr first , Itr last , const T &value, Equal eq)
{
	while(first != last)
	{ 
		if(eq(*first, value))
			return first;

		first++;
	}

	return last;//se o valor da função não for achado no range a função retornar last
}






//cliente
bool eq(const int &a, const int &b){return a == b;} 
int main()
{
	int A[] = {1,2,3,5,4,8,7,54,-5,3};

	//auto ret = find(std::begin(A), std::end(A), 32, eq); aqui ele retorna lixo
	auto ret = find(std::begin(A), std::end(A), 5, eq);


	std::cout << *ret << std::endl;
	
	return 0;
}