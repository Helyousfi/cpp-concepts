// Program to find if a number is prime

#include<iostream>

int main() 
{
	int number, isPrime = 0;
	std::cout << "Enter Number : ";
	std::cin >> number;
	
	for(int k=2; k < number/2; ++k)
	{
		if(number % k == 0){
			isPrime++;
			break;
		}
	}
	if(isPrime != 0)
		std::cout << "Number is not prime";
	else
		std::cout << "Number is prime";
	
	return 0;
}
