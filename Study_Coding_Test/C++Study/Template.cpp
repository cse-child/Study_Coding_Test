#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print(T value) {
	std::cout << "General version: " << value << std::endl;
}

// int Ư��ȭ
template <>
void print<int>(int value) {
	std::cout << "Specialized version for int: " << value << std::endl;
}

int main() {
	print(5);    // ȣ��: print<int>
	print(5.0);  // ȣ��: print<double>
	return 0;
}

