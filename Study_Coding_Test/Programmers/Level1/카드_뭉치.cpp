#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {

	for(int i = 0; i < goal.size(); i++)
	{
		if (cards1[0] == goal[i])
			cards1.erase(cards1.begin());
		else if (cards2[0] == goal[i])
			cards2.erase(cards2.begin());
		else
			return "No";
	}
	return "Yes";
}

int main()
{
	//vector<string> cards1 = { "i", "drink", "water" };
	//vector<string> cards2 = { "want", "to" };
	//vector<string> goal = { "i", "want", "to", "drink", "water" };

	vector<string> cards1 = { "i", "water", "drink" };
	vector<string> cards2 = { "want", "to" };
	vector<string> goal = { "i", "want", "to", "drink", "water" };

	cout << solution(cards1, cards2, goal);
}