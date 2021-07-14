#include <iostream>

void permute(const std::string& str, int low, int high)
{
	std::string s = str;
	if (low == high)
	{
		std::cout << s << "\n";
	}
	else
	{
		for (int i = low; i <= high; ++i)
		{
			std::swap(s[low], s[i]);
			permute(s, low + 1, high);
			std::swap(s[low], s[i]);
		}
	}

}

void permute(const std::string& str)
{
	permute(str, 0, str.length() - 1);
}
