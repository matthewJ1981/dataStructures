#include <iostream>
#include <vector>

//select kth largest number in array (CH1EX1)
extern int select(std::vector<int>, int k);
//Find words in word list (CH1EX2)
extern std::vector<std::vector<std::pair<size_t, size_t>>> findWord(std::vector<char>&, size_t width, std::vector<std::string>&);

int main()
{
	// Chapter 1 Exercise 1 Driver
	//std::vector<int> numbers{ 14, 65,1, 684,1,3, 48,1159, 41, 3154, 81,64,89};
	//std::cout << select(numbers, numbers.size() / 2);

	// Chapter 1 Exercise 2 Driver
	//std::vector<char> board{ 't', 'h', 'i', 's', 'w', 'a', 't', 's', 'o', 'a', 'h', 'g', 'f', 'g', 'd', 't' };
	//std::vector<std::string> wordList{ "this", "two", "fat", "that" };
	//size_t width = 4;
	//auto positions = findWord(board, width, wordList);

	//for (size_t i = 0; i < positions.size(); i++)
	//{
	//	for (size_t j = 0; j < positions[i].size(); j++)
	//		std::cout << "(" << positions[i][j].first << ", " << positions[i][j].second << ")";

	//	std::cout << "\n";

	//}
	//std::cout << "\n";
}




