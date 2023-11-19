#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>


int main()
{
	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto rng = std::ranges::views::all(v)
		| std::ranges::views::filter([](int a) {
		return a % 2 == 0; }); // 짝수만 필터링

	std::cout << rng << std::endl; // [2,4,6,8,10]

	// 원본은 수정되지 않음.
	auto orinRange = std::ranges::views::all(v);
	std::cout << orinRange << std::endl; // [1,2,3,4,5,6,7,8,9,10]

	for (auto n : r)
		std::cout << n << " "; // 2 4 6
	std::cout << std::endl;

	auto iter{std::ranges::min_element(vec)};
	std::cout << *iter;

	std::vector<int> vec = { 1,2,3,4,5 };
	auto view{ std::views::transform(vec, [](int i) { return i * i; }) };



	return 0;
}