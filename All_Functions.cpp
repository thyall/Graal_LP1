// All functions

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