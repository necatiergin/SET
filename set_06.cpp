#include <iostream>
#include <set>

int main()
{
	using std::cout;

	std::set<int> s{ 2, 3, 5, 6, 8, 23, 98, 123, 187 };

	for (const auto val : s)
		cout << val << ' ';

	cout << "\nset size : " << s.size() << '\n';
	cout << "enter the value to insert : ";
	int x;
	std::cin >> x;

	if (auto [iter, inserted] = s.insert(x); inserted) {
		cout << "the value inserted... " << *iter << '\n';
	}
	else {
		cout << "the value not inserted, the set has this value : " << *iter << '\n';
	}

	cout << "set size : " << s.size() << '\n';
	for (auto val : s)
		cout << val << ' ';
}
