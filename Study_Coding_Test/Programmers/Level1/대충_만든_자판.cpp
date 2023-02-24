#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
	vector<int> answer(targets.size(), 0);

	for (int i = 0; i < targets.size(); i++)
	{
		for (int j = 0; j < targets[i].length(); j++)
		{
			int minIdx = -1;
			for (string key : keymap)
			{
				int findIdx = key.find(targets[i][j]);

				minIdx = (findIdx == -1) ? minIdx : (minIdx == -1) ? findIdx : min(minIdx, findIdx);
			}
			if (minIdx == -1)
			{
				answer[i] = -1;
				break;
			}
			answer[i] += (minIdx + 1);
		}
	}

	return answer;
}