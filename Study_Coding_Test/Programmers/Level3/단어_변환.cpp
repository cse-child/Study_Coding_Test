#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkUse[51];
int result = 100;

bool CheckIncludeWords(const string str1, const string str2)
{
	int cnt = 0;
	for(int i = 0; i < str1.size(); i++)
	{
		if (str1[i] != str2[i])
			cnt++;
		if (cnt > 1)
			return false;
	}
	return cnt > 1 ? false : true;
}

void DFS(string& begin, const string target, vector<string>& words, int findCnt)
{
	if (begin == target)
	{
		result = min(result, findCnt);
		return;
	}
	
	for (int i = 0; i < words.size(); i++)
	{
		if (checkUse[i]) continue;

		if(CheckIncludeWords(begin, words[i]))
		{
			checkUse[i] = true;
			DFS(words[i], target, words, findCnt + 1);
			checkUse[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words) {

	if (find(words.begin(), words.end(), target) == words.end())
		return 0;

	DFS(begin, target, words, 0);

	return result;
}

int main()
{
	string begin = "hit";
	string target = "cog";
	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };

	//string begin = "hit";
	//string target = "cog";
	//vector<string> words = { "hot", "dot", "dog", "lot", "log" };

	cout << solution(begin, target, words);
}