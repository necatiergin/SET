#include <iostream>
#include <set>
#include <cmath>

int main()
{
	const auto f = [](int a, int b) {return std::abs(a) < std::abs(b); };
	std::set<int, decltype(f)> s{ -12, 5, -5, 9, -7, 6, 2, -4 };

	for (auto i : s)
		std::cout << i << ' ';
}
