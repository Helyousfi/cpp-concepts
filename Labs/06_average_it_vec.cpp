// Calculating average using vectors and iterators
#include<iostream>
#include<vector>
#include<iterator>

// Vector average using iterators
float vec_avg(const std::vector<int>& vec)
{
	if(vec.empty())	
		throw std::invalid_argument("Vector is empty!");

	int sum = 0;
	// For learning purpose, I don't use auto
	std::vector<int>::const_iterator it = vec.cbegin(); // cbegin to deduce automatically iterator type, here it's a const_iterator
	while(it != vec.cend()){
		sum += *it;
		++it;
	}
	// int sum_acc = std::accumulate(vec.begin(), vec.end(), 0);
	return static_cast<double> (sum / vec.size());
}

int main()
{
	std::vector<int> vec = {1, 2, 3, 4, 5};
	float avg = vec_avg(vec);
	std::cout << avg;
	return 0;
}

