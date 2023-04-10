#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Compare(vector<int> arr1, vector<int> arr2)
{
	return arr1[1] < arr2[1];
}


int solution(vector<vector<int>> jobs) {
	int answer = 0;

	//for(vector<int> job : jobs)
	//	cout << job[1] << " ";
	//cout << endl;

	sort(jobs.begin()+1, jobs.end(), Compare);

	//for (vector<int> job : jobs)
	//	cout << job[1] << " ";
	//cout << endl;

	// 3,9,6
	//0,1,2

	//[0,3], [2,6] ,[1,9]
	// (0+3-0) + (3+6 - (2) + (9+9  - (1))
	// 3 + 7 + 17

	//공식: 요청시작시간 + 요청시간 - 이전에작업끝난시간
	//공식: 이전에작업끝난시간 + 요청시간 - 요청시작시간

	// ★ : 하드디스크가 작업을 수행하고 있지 않을 때에는 먼저 요청이 들어온 작업부터 처리합니다.

	return answer;
}

int main()
{
	vector<vector<int>> jobs = { {0, 3},{1, 9},{2, 6} };

	solution(jobs);
}