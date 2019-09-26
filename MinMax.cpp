#include <iostream>

template <typename itr, typename Compare>
std::pair<itr,itr> minmax(itr first, itr last, Compare cmp)
{
	// criando variaveis auxiliares
	itr min = first;
	itr max = first++;	

	while(first != last) //percorrendo o range
	{
		if(cmp(*first, *min))
			min = first;

		else if(cmp(*max, *first))
			max = first;

		first ++;
	}

	return std::make_pair(min,max);//retornando os vlores min e max
}

bool cmp(const int &a, const int &b){return a < b;}// função de comparação


//cliente
int main()
{
	int A[] = {1,2,3,5,4,8,7,54,-5,3};

	std::pair<int*, int*> result;//criando variavel "pair"

	for(int i = 0; i < 10; ++i)
	{
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	result = minmax(std::begin(A), std::end(A), cmp);// passando o range para a funcao e atirbuindo a variavel result

	std::cout << *result.first << " "<< *result.second<< std::endl; // first e second pertecence ao pair 

	return 0;
}

