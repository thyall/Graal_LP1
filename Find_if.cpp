#include <iostream>

template <typename Itr , typename Predicate>
Itr find_if(Itr first , Itr last , Predicate p)
{
	while(first != last)
	{ 
		if(p(*first))
			return first;

		first++;
	}

	return last;//se o valor da função não for achado no range a função retornar last
}





//cliente
//esse predicado pode ser variado por ex "return a%2 == 0" -- > aqui ele retorna o proiemiro par
bool p(const int &a){return a < 0;} // por exemplo esse predicado retorna true se tiver algum valor negativo

int main(int argc, char const *argv[])
{
	int A[] = {1,2,3,5,4,8,7,54,-5,3};

	auto ret = find_if(std::begin(A), std::end(A), p);

	std::cout << *ret << std::endl;
	
	return 0;
}