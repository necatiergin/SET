#include <cmath>
#include <set>
#include <iostream>

struct Comp {
	bool operator()(int a, int b)const
	{
		return std::abs(a) < std::abs(b);
	}
};

int main()
{
	std::set<int, Comp> s{ -12, 5, -5, 9, -7, 6, 2, -4 };

	for (const auto i : s)
		std::cout << i << ' ';
}
