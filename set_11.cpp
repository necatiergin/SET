#include <iostream>
#include <set>

class Person {
public:
	Person() = default;
	Person(int id, std::string name) : m_id{ id }, m_name{ std::move(name) } {}
	auto operator<=>(const Person&)const = default;

	friend std::ostream& operator<<(std::ostream& os, const Person& p)
	{
		return os << p.m_id << ", " << p.m_name;
	}

private:
	int m_id{};
	std::string m_name{};
};

int main()
{
	std::set<Person> pset;

	pset.emplace(12, "ali");
	pset.emplace(24, "selim");
	pset.emplace(33, "nalan");
	pset.emplace(9, "ferit");

	for (const auto& p : pset)
		std::cout << p << '\n';

	if (auto handle = pset.extract(Person{ 33, "nalan" }); !handle.empty()) {
		handle.value() = Person{ 97, "sinem" };
		pset.insert(std::move(handle));
	}
	else {
		std::cout << "not found\n";
	}
	std::cout << "\n\n";
	for (const auto& p : pset)
		std::cout << p << '\n';
}
