#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
	vector<int> answer;
	vector<int> kList(k);
	int minN = score[0];
	if (score.size() < k)
	{
		for (int i = 0; i < score.size(); i++)
		{
			kList[i] = score[i];
			minN = min(minN, score[i]);
			answer.push_back(minN);
		}
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			kList[i] = score[i];
			minN = min(minN, score[i]);
			answer.push_back(minN);
		}
	}


	sort(kList.begin(), kList.end());

	for (int i = k; i < score.size(); i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (kList[j] < score[i])
			{
				kList[j] = score[i];
				break;
			}
		}

		sort(kList.begin(), kList.end());

		answer.push_back(kList[0]);
	}
	return answer;
}


/* Best Ç®ÀÌ */
/*
vector<int> solution(int k, vector<int> score) {
	vector<int> answer, tmp;

	for (auto s : score) 
	{
		tmp.push_back(s);

		sort(tmp.begin(), tmp.end(), greater<int>());

		if (tmp.size() > k) 
			tmp.erase(tmp.begin() + k, tmp.end());

		answer.push_back(tmp.back());
	}

	return answer;
}
*/
int main()
{
	//vector<int> score = { 10, 100, 20, 150, 1, 100, 200 };
	//solution(3, score);

	//vector<int> score = { 0, 300, 40, 300, 20, 70, 150, 50, 500, 1000 };
	//solution(4, score);

	//[100, 30, 30, 40, 100, 150, 200]
	vector<int> score = { 100, 30, 40, 150, 300, 200, 200 };
	solution(3, score);

	//vector<int> score = { 20,30,50,100 };
	//solution(5, score);
}