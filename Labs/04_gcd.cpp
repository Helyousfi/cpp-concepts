#include<iostream>
#include<vector>

int gcd(int x, int y)
{
	if(x == 0 || y == 0)
		return 0;
	if(x == y)
		return x;
	if(x > y)
		return gcd(x-y, y);
	if(y > x)
		return gcd(x, y-x);
}

int main()
{
	std::cout << gcd(14,10) << std::endl;
	return 0;
}
