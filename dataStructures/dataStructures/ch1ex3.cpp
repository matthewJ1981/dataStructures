#include <iostream>
#include <vector>

//Print a single digit
void printDigit(int n)
{
	std::cout << n;
}

//Recursively print one digit a time backwards
void printOutHelper(int n)
{
	if (n >= 10)
		printOutHelper(n / 10);

	printDigit(n % 10);
}

//Print a double one digit at a time
void printOut(double d)
{
	//get the integer part of the double as an int
	int integer = (int)d;
	//get the fractional part of the double
	double fraction = d - integer;
	//While there is still a frcational component multiple it by 10 to convert it to an int
	while (fraction - floor(fraction) > 0.000000001)
	{
		double test = fraction - floor(fraction);
		fraction *= 10;
	}

	//Print the integer part 
	printOutHelper(integer);
	//Bending the rules, print the decimal point
	std::cout << ".";
	//print the fractional part
	printOutHelper((int)fraction);
	//still being rules, print a new line
	std::cout << "\n";
}