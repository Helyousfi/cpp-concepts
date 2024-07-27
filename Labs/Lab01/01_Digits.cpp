// A program to calculate sum of digits

#include<iostream>

int main()
{
	int number, sum = 0;
	// Get the number from user
	std::cout << "Enter number : ";
	std::cin >> number;
	
	// Add modulo 10, 100, ...
	while(number != 0)
	{
		sum += number%10;
		number = number / 10;
	}
	std::cout << sum;
}
