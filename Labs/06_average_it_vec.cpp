// Calculating average using vectors and iterators
#include<iostream>
#include<vector>
#include<iterator>

float vec_avg(const std::vector<int>& vec)
{
	int sum = 0;
	const std::vector<int>::iterator it = vec.begin();
	while(it++ != vec.end())
		sum += *it;
	// int sum_acc = std::accumulate(vec.begin(), vec.end(), 0);
	return static_cast<double> (sum / vec.size());
}

int main()
{
	std::vector<int> vec = {1, 2, 3, 4, 5};
	vec_avg(vec);
	return 0;
}

