#include <iostream>
#include <vector>

using namespace std;

class Item {
public:

	Item(const int _n) : m_nx(_n) { cout << "�Ϲ� ������ ȣ��" << endl; }
	Item(const Item& rhs) : m_nx(rhs.m_nx) { cout << "���� ������ ȣ��" << endl; }
	Item(const Item&& rhs) : m_nx(std::move(rhs.m_nx)) { cout << "�̵� ������ ȣ��" << endl; }
	~Item() { cout << "�Ҹ��� ȣ��" << endl; }

private:
	int m_nx;
};

int main() {
	std::vector<Item> v;

	cout << "push_back ȣ��" << endl;
	v.push_back(Item(3));

	cout << "emplace_back ȣ��" << endl;
	v.emplace_back(3);
}

