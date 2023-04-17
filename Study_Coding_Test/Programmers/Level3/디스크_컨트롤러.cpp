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
jobs �迭�� ��û�ð� �������� ������������ �����ϱ�
���� ��û�ð����� �����ϰ� ���� ���ٸ� �ҿ�ð��� �������� ���� ���׽��ϴ�.

�׽�ũ ó�� ���߿� ���� �׽�ũ���� ��û�ð��� ������� �ҿ�ð� �������� ���Ľ�Ű�°̴ϴ�. (PriorityQueue �� Comparable �����ؼ� �ҿ�ð� ����)
(���� 3ms�� �׽�ũ�� �����ٸ� 3ms�� ������ �׽�ũ�� ����)

�׽�ũ ó�� ������ �ƴ� ��쿡�� �׳� ó���Ͻø�˴ϴ�.(�̹� jobs �迭�� ���������ϱ�)
 */

 //[��û�ð�, �۾��ð�]
 //[0,3], [2,6] ,[1,9]
 // (0+3-0) + (3+6 - (2) + (9+9  - (1))
 // 3 + 7 + 17

 //����: �������۾������ð� + ��û�ð� - ��û���۽ð�

 // �� : �ϵ��ũ�� �۾��� �����ϰ� ���� ���� ������ ���� ��û�� ���� �۾����� ó���մϴ�.
 // ��... ���� ��û�� ���� �۾��̶��� ���� jobs�� �ε��� ������ ���ϴ��� �˾Ҵµ� [0]��°�� ��û���۽ð��� ���ϴ°ſ���..����