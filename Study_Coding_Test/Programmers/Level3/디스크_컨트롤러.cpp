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

	//[��û�ð�, �۾��ð�]
	//[0,3], [2,6] ,[1,9]
	// (0+3-0) + (3+6 - (2) + (9+9  - (1))
	// 3 + 7 + 17

	//����: ��û���۽ð� + ��û�ð� - �������۾������ð�
	//����: �������۾������ð� + ��û�ð� - ��û���۽ð�

	// �� : �ϵ��ũ�� �۾��� �����ϰ� ���� ���� ������ ���� ��û�� ���� �۾����� ó���մϴ�.
	// ��... ���� ��û�� ���� �۾��̶��� ���� jobs�� �ε��� ������ ���ϴ��� �˾Ҵµ� [0]��°�� ��û���۽ð��� ���ϴ°ſ���..����

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