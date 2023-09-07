#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
	vector<int> answer;

	unordered_map<string, int> score;
	for (int i = 0; i < name.size(); i++)
		score[name[i]] = yearning[i];

	for(vector<string> group : photo)
	{
		int result = 0;
		for (string name : group)
			result += score[name];
		answer.push_back(result);
	}

	return answer;
}