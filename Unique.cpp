#include <iostream>

template<typename Itr, typename Equal>
    Itr unique(Itr first1, Itr last1, Equal eq)
    {        
        Itr inicio = first1;
        Itr auxiliar = first1 + 1;

        int size1 = (last1 - 1) - inicio;
        int array2[size1];

        Itr ponteiro = first1; 
        Itr first2 = &array2[0];
        Itr inicio2 = &array2[0];
        Itr last2 = &array2[size1];

        while(inicio < last1)
        {
            if (auxiliar != inicio && eq(*auxiliar,*inicio))
            {
                *last2 = *inicio;
                last2--;
                inicio++;
                auxiliar = first1;
            }
            else if(auxiliar == last1 && !eq(*auxiliar,*inicio))
            {
                *first2 = *inicio;
                first2++;
                inicio++;
                auxiliar = first1;
                ponteiro++;                
            }
            else
            {
                auxiliar++;
            }
        }
        
        /*for (int i = 0; i <= size1; i++)
        {
            *first1 = *inicio2;
            std::cout << *first1 << " ";
            first1++;
            inicio2++;
        }*/

        return ponteiro;
    }



//cliente
bool eq(const int &a, const int &b){return a == b;} 
int main()
{
	int A[] = {1,1,2,2,3,3,5,5,4,8,7,54,-5,3};

	auto ret = unique(std::begin(A), std::end(A),  eq);

	std::cout << *ret << std::endl;

	for (int i = 0; i < 14; ++i)
	{
		std::cout << ret[i];
	}
	
	return 0;
}