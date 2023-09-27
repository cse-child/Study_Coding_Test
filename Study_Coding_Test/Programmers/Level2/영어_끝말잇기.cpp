#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer(2);
	unordered_map<string, bool> useWords;

	int curPeople = 1;
	int cycleCnt = 1;

	char last = words[0][words[0].size() - 1];
	useWords[words[0]] = true;

	for (int i = 1; i < words.size(); i++)
	{
		if (curPeople % n == 0)
		{
			curPeople = 0;
			cycleCnt++;
			//cout << "update Cycle Cnt : " << cycleCnt << endl;
		}

		//cout << words[i][0] << "  " << last << endl;
		if (words[i][0] != last || useWords[words[i]])
		{
			answer[0] = curPeople + 1;
			answer[1] = cycleCnt;

			break;
		}

		last = words[i][words[i].size() - 1];
		useWords[words[i]] = true;
		curPeople++;

		//cout << "last word : " << last << endl;
		//cout << "curPeople Num : " << curPeople << endl << endl;
	}

	return answer;
}