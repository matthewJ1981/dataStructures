#include <iostream>
#include <vector>

// sort numbers by inserting in appropriate place.  Only care about the top kth numbers
void insert(std::vector<int>& sorted, size_t k, int x)
{
	for (size_t i = 0; i < k; i++)
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
	for (size_t i = 0; i < numbers.size(); i++)
		insert(sorted, numbers.size() / 2, numbers[i]);

	//debug output
	for (int i : sorted)
		std::cerr << i << " ";
	std::cerr << "\n";

	//output kth number
	return sorted[k - 1];
}