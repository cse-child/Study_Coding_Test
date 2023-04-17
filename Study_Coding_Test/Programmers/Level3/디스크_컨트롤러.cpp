#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp
{
	bool operator() (vector<int> arr1, vector<int> arr2)
	{
		return arr1[1] > arr2[1];
	}
};

int solution(vector<vector<int>> jobs) {
	sort(jobs.begin(), jobs.end());

	int time = 0;
	int totalTime = jobs[0][0];
	int index = 1;

	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	pq.push(jobs[0]);

	while (!pq.empty())
	{
		time += (totalTime + pq.top()[1] - pq.top()[0]);
		totalTime += pq.top()[1];
		pq.pop();

		for (; index < jobs.size() && jobs[index][0] <= totalTime; index++)
			pq.push(jobs[index]);

		if (pq.empty() && index < jobs.size())
		{
			pq.push(jobs[index]);
			totalTime = jobs[index][0];
			index++;
		}
	}

	return time / jobs.size();
}

//int main()
//{
//	//vector<vector<int>> jobs = { {0, 3},{2, 6},{1, 9} };
//	vector<vector<int>> jobs = { {0, 5},{2, 10},{10000, 2}};
//
//	solution(jobs);
//}

/*
jobs 배열을 요청시간 기준으로 오름차순으로 정렬하기
저는 요청시간으로 정렬하고 만약 같다면 소요시간을 기준으로 정렬 시켰습니다.

테스크 처리 도중에 들어온 테스크들은 요청시간과 상관없이 소요시간 기준으로 정렬시키는겁니다. (PriorityQueue 로 Comparable 구현해서 소요시간 비교함)
(만약 3ms에 테스크가 끝난다면 3ms에 들어오는 테스크도 포함)

테스크 처리 도중이 아닌 경우에는 그냥 처리하시면됩니다.(이미 jobs 배열을 정렬했으니까)
 */

 //[요청시간, 작업시간]
 //[0,3], [2,6] ,[1,9]
 // (0+3-0) + (3+6 - (2) + (9+9  - (1))
 // 3 + 7 + 17

 //공식: 이전에작업끝난시간 + 요청시간 - 요청시작시간

 // ★ : 하드디스크가 작업을 수행하고 있지 않을 때에는 먼저 요청이 들어온 작업부터 처리합니다.
 // 아... 먼저 요청이 들어온 작업이란게 나는 jobs의 인덱스 순서를 말하는줄 알았는데 [0]번째인 요청시작시간을 말하는거였다..미췬