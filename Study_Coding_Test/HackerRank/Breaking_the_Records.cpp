#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> breakingRecords(vector<int> scores) {
	int highest = scores[0];
	int lowest = scores[0];
	vector<int> newScore(2, 0);

	for (int score : scores)
	{
		if (score > highest)
		{
			newScore[0]++;
			highest = score;
		}
		else if (score < lowest)
		{
			newScore[1]++;
			lowest = score;
		}
	}
	return newScore;
}