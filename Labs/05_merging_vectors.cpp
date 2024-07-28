// Include necessary headers
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

#define dec_vector std::vector<int>
#define DEACTIVATE

// Function to print a vector 
void print_vec(const dec_vector& vec)
{
	for(const int& i : vec)
		std::cout << i << ' ';
	std::cout << std::endl;
}

// Function to merge two vectors
void merging(dec_vector& vec1, 
		dec_vector& vec2, 
		dec_vector& output)
{

	// Sorting the three vectors
	std::sort(vec1.begin(), vec1.end());
	std::sort(vec2.begin(), vec2.end());
	
	// Resize output
	output.resize(vec1.size() + vec2.size());
		

	// Merging vectors
	std::vector<int>::iterator it_vec1 = vec1.begin();
	std::vector<int>::iterator it_vec2 = vec2.begin();
	std::vector<int>::iterator it_output = output.begin();


	while(it_vec1 != vec1.end() && it_vec2 != vec2.end())
	{
		if(*it_vec1 < *it_vec2){
			*(it_output++) = *it_vec1;
			++it_vec1;
		}
		else{
			*(it_output++) = *it_vec2;
			++it_vec2;
		}
	}
	
	while(it_vec2 != vec2.end())
		*(it_output++) = *(it_vec2++);
	while(it_vec1 != vec1.end())
		*(it_output++) = *(it_vec1++);

}

int main()
{
	dec_vector vec1 = {1, 5, 6, 9, 55, 7, 99};
	dec_vector vec2 = {0, 4, 9, 3, 1, 2};
	dec_vector output;
	
	merging(vec1, vec2, output);	
	print_vec(output);
	return 0;
}
