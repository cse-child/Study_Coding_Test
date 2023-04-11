#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool TaskCompare(vector<int> arr1, vector<int> arr2)
{
	return arr1[1] < arr2[1];
}

bool StartTimeCompare(vector<int> arr1, vector<int> arr2)
{
	return arr1[0] < arr2[0];
}

int solution(vector<vector<int>> jobs) {
	int answer = 0;

	// 3,9,6
	//0,1,2

	//[요청시간, 작업시간]
	//[0,3], [2,6] ,[1,9]
	// (0+3-0) + (3+6 - (2) + (9+9  - (1))
	// 3 + 7 + 17

	//공식: 요청시작시간 + 요청시간 - 이전에작업끝난시간
	//공식: 이전에작업끝난시간 + 요청시간 - 요청시작시간

	// ★ : 하드디스크가 작업을 수행하고 있지 않을 때에는 먼저 요청이 들어온 작업부터 처리합니다.
	// 아... 먼저 요청이 들어온 작업이란게 나는 jobs의 인덱스 순서를 말하는줄 알았는데 [0]번째인 요청시작시간을 말하는거였다..미췬

	//for (vector<int> job : jobs)
	//	cout << job[0] << " ";
	//cout << endl;

	sort(jobs.begin(), jobs.end(), StartTimeCompare);

	for(vector<int> job : jobs)
	{
		sort(jobs.begin()+job, jobs.end());
	}


	return answer;
}

int main()
{
	vector<vector<int>> jobs = { {0, 3},{2, 6},{1, 9} };

	solution(jobs);
}


/*
#include <string>
#include <bits/stdc++.h>

using namespace std;

struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0, n = 0, used = 0;
	priority_queue <vector<int>, vector<vector<int>>, cmp> heap;
	vector<bool> check(jobs.size(), true);

	while (used < jobs.size()) {
		for (int i = 0; i < jobs.size(); i++) {
			if (check[i] && jobs[i][0] <= n) {
				heap.push(jobs[i]);
				check[i] = false;
			}
		}
		if (heap.empty()) {
			n++; continue;
		}
		answer += n - heap.top()[0] + heap.top()[1];
		n += heap.top()[1];
		heap.pop();
		used++;
	}
	return answer / jobs.size();
}




 */