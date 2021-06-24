#include <iostream>
#include <vector>

int numOnes(int n)
{
	if (n == 1)
		return 1;
	else
	{
		if (n % 2 == 0)
			return numOnes(n / 2);
		else
			return numOnes(n / 2) + 1;
	}
}