/*
In this exercise you should develop a series of functions that represent typical algorithms for
array manipulation. Because we are still following an imperative programming paradigm, all
functions should receive the range we wish to operate on as an argument.
The primary goal of this exercise is to practice a higher level of abstract programming,
where our code does not need to know in advance which type of data we are operating on. To
do that our code requires the use of function template in association with function pointers.
The former supports the passage of generic arguments to functions, whereas the latter helps
us to defer some decisions to the client by allowing them to provide the code to operate on
data.
The secondary objective is to acquire programming experience by building a library of
typical algorithms on arrays, called graal —GeneRic Array Algorithms Library. By building
this generic library we want to demonstrate the importance of programming abstraction and
code reuse while developing an application in the next exercise.

- Implemented by 
	Samir Rodrigues
	Thyall Dgreville
*/
#ifndef ATV1_H
#define ATV1_H

#include <iostream>
#include <vector>
#include <iterator>
#include <utility>

namespace graal
{
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

	//-------------------------------------------------------------------------------//

	template <typename itr>
	void reverse(itr first, itr last)
	{
		while(first != last) //percorrendo o range
		{
			std::swap(*first, *(last-1)); // é usado last menos 1 para não pegar "lixo", pois o std::end aponta para um endereço a frente do vetor

			first++;
			last--;
		}	
	}

	//----------------------------------------------------------------------------------//

	template <typename itr>
	itr copy(itr first, itr last, itr d_first)
	{	
		while(first != last)
		{
			*d_first = *first;
			first++;
			d_first++;
		}

		return d_first;
	}

	//---------------------------------------------------------------------------------//

	template <typename Itr , typename Predicate>
	Itr find_if(Itr first , Itr last , Predicate p)
	{
		while(first != last)
		{ 
			if(p(*first))
				return first;

			first++;
		}

		return last;//if the value is noy found in the range, the function returns last
	}

	//---------------------------------------------------------------------------------//

	template <typename Itr , typename T, typename Equal>
	Itr find(Itr first , Itr last , const T &value, Equal eq)
	{
		while(first != last)
		{ 
			if(eq(*first, value))
				return first;

			first++;
		}

		return last;//if the value is noy found in the range, the function returns last
	}

	//---------------------------------------------------------------------------------//

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

	//--------------------------------------------------------------------------------//

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

	//--------------------------------------------------------------------------------//

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

	//---------------------------------------------------------------------------------//

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

	//---------------------------------------------------------------------------------//

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

	//---------------------------------------------------------------------------------//

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
		
		for (int i = 0; i <= size1; i++)
		{
			*first1 = *inicio2;
			std::cout << *first1 << " ";
			first1++;
			inicio2++;
		}

		return ponteiro;
	}

	//------------------------------------------------------------------------------//

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

	//------------------------------------------------------------------------------//


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

	//------------------------------------------------------------------------------//


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

}
#endif