#include <iostream>

template <typename itr, typename Compare>
std::pair<itr,itr> min(itr first, itr last, Compare cmp)
{
	itr min = first;
	itr max = first++;	

	while(first != last)
	{
		if(cmp(*first, *min))
			min = first;

		else if(cmp(*max, *first))
			max = first;

		first ++;
	}

	return std::make_pair(min,max);
}








bool cmp(const int &a, const int &b)
{
	return a < b;
}

int main()
{
	int A[] = {1,2,3,5,4,8,7,54,-5,3};
	//int *x;
	std::pair<int*, int*> result;

	for(int i = 0; i < 10; ++i)
	{
		std::cout << A[i] << " ";
	}std::cout << std::endl;


	result = min(std::begin(A), std::end(A), cmp);

	std::cout << *result.first << " "<<*result.second<< std::endl; // first e second pertecence ao pair 

	return 0;
}

