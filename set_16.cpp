#include <set>
#include <string>
#include <cstdlib>
#include <utility>
#include "nutility.h"    // see the header

class Employee  {
public:
    Employee(int id, std::string name) : m_id(id), m_name(std::move(name)) {}
    [[nodiscard]] int get_id() const { return m_id; }
    [[nodiscard]] std::string get_name() const { return m_name; }
private:
    int m_id;
    std::string m_name;
};

struct IdCompare
{
    using is_transparent = struct SearchById; 

    bool operator()(Employee const& employee1, Employee const& employee2) const
    {
        return employee1.get_id() < employee2.get_id();
    }

    bool operator()(int id, Employee const& employee) const
    {
        return id < employee.get_id();
    }

    bool operator()(Employee const& employee, int id) const
    {
        return employee.get_id() < id;
    }
};


int main()
{
    std::set<Employee, IdCompare> myset;

    rfill(myset, 10, [] {return Employee{ rand(), random_name() }; });
    myset.insert(Employee{ 45, "necati" });

    if (auto iter = myset.find(45); iter != myset.end()) {
        std::cout << "found : " << iter->get_id() << ' ' << iter->get_name() << '\n';
    }
    else {
        std::cout << "not found\n";
    }
    
}
