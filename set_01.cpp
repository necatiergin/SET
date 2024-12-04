#include <iostream>
#include <set>

template <typename T>
void print(const std::set<T>& s)
{
	for (const auto& elem : s)
		std::cout << elem << ' ';

	std::cout << '\n';
}


int main()
{
	using std::set, std::less;

	//set<int, less<int>> s{ 2, 5, 3, 6, 4, 9, 8, 7, 12 };
	//set<int, less<>> s{ 2, 5, 3, 6, 4, 9, 8, 7, 12 };
	//set<int> s{ 2, 5, 3, 6, 4, 9, 8, 7, 12 };
	set s{ 2, 5, 3, 6, 4, 9, 8, 7, 12, 1 };

	print(s);
}
