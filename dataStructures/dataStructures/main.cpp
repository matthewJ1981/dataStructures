#include <iostream>
#include <vector>

//select kth largest number in array
int select(std::vector<int>, int k);

int main()
{
	std::vector<int> numbers{ 14, 65,1, 684,1,3, 48,1159, 41, 3154, 81,64,89};
	std::cout << select(numbers, numbers.size() / 2);
}

// sort numbers by inserting in appropriate place.  Only care about the top kth numbers
void insert(std::vector<int>& sorted, int k, int x)
{
	for (int i = 0; i < k; i++)
		if (i >= sorted.size() || x > sorted[i])
		{
			sorted.insert(sorted.begin() + i, x);
			break;
		}
}

//select kth largest number in array
int select(std::vector<int> numbers, int k)
{
	//sorted array of numbers
	std::vector<int> sorted;

	//sort numbers
	for (int i = 0; i < numbers.size(); i++)
		insert(sorted, numbers.size() / 2, numbers[i]);

	//debug output
	for (int i : sorted)
		std::cerr << i << " ";
	std::cerr << "\n";

	//output kth number
	return sorted[k - 1];
}