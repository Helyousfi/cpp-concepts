// Print fibonacci numbers iteratively
// 1, 1, 2, 3, 5, ...
#include<iostream>

int main() 
{
	int a=0, b=1, sum=0;
	while(a < 100)
	{
		sum = a + b;
		a = b;
		b = sum;
		if(b > 100)
			break;
		std::cout << sum << ' ';
	}
	return 0;
}
