#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>


int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	auto r = v | std::views::filter([](int a) { return a % 2 == 0; })
				| std::views::take(3);

	for (auto n : r)
		std::cout << n << " "; // 2 4 6
	std::cout << std::endl;

	auto iter{std::ranges::min_element(vec)};
	std::cout << *iter;

	std::vector<int> vec = { 1,2,3,4,5 };
	auto view{ std::views::transform(vec, [](int i) { return i * i; }) };



	return 0;
}