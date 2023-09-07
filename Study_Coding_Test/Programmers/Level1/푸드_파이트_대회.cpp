#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
	string answer = "0";

	for(int i = food.size()-1; i >= 1; i--)
	{
		string num = to_string(i);
		for (int j = 0; j < food[i] / 2; j++)
			answer = num + answer + num;
	}

	return answer;
}