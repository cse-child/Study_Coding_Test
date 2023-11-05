#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print(T value) {
	std::cout << "General version: " << value << std::endl;
}

// int 특수화
template <>
void print<int>(int value) {
	std::cout << "Specialized version for int: " << value << std::endl;
}

int main() {
	print(5);    // 호출: print<int>
	print(5.0);  // 호출: print<double>
	return 0;
}

