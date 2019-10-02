#include <iostream>
template<typename Itr, typename Comparison>
    void sort(Itr first, Itr last, Comparison comp)
    {
        for (int i = 0; i < (last - first); ++i)
        {
            int aux = i;
            for (int j = i + 1; j <= (last - first); ++j)
            {
                if (comp (*(first + j), *(first+aux)))
                {
                    aux = j;
                }
            }
            std::swap(*(first+i),*(first+aux));
        }
    }


//cliente
int main()
{
	int A[] = {1,2,7,5,4,8,7,54,-5,12};

	std::cout << "Antes:" << std::endl;
	for(int i = 0; i < 10; ++i)
	{
	  std::cout << A[i] << " ";
	}std::cout << std::endl;

	auto a = sort(std::begin(A), std::begin(A)+4, );

	std::cout << "Depois:" << std::endl;
	while(a != a+4)
	{
		std::cout << *a << " ";
		a++;
	}

	//std::cout << "Ponteiro apontando para o primeiro elemento apos a rotação do vetor:" << std::endl << *a << std::endl;
	return 0;

}