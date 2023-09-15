#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

map<int, int> toppingType;

int solution(vector<int> topping) {
	int answer = 0;

	for (int i = 0; i < topping.size(); i++)
		toppingType[topping[i]]++;

	map<int, int> chulsu;
	for(int i = 0; i < topping.size(); i++)
	{
		if(toppingType[topping[i]] > 0)
		{
			toppingType[topping[i]] -= 1;
			chulsu[topping[i]] += 1;

			if (toppingType[topping[i]] == 0)
				toppingType.erase(topping[i]);
		}

		if (chulsu.size() == toppingType.size())
			answer += 1;
	}

	return answer;
}

int main()
{
	vector<int> topping = { 1, 2, 1, 3, 1, 4, 1, 2 };
	//vector<int> topping = { 1, 2, 3, 1, 4 };

	cout << solution(topping);
}