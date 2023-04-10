#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct MyCompare
{
	bool operator() (string s1, string s2)
	{
		return s1.length() > s2.length();
	}
};

int main()
{
	// �켱���� ť�� Default �� ��������
	priority_queue<int> pq;

	pq.push(30);
	pq.push(10);
	pq.push(20);

	while(!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	// ���: 30 20 10
	cout << endl;

	///////////////////////////////////////////////////////////////////////////

	/* �������� ���� ��� */
	// �켱���� ť�� ���� �̿��� Ʈ������ �̹Ƿ� ������ �����͸� ������ ���� vector<int> �� �ʿ��ϴ�.
	priority_queue<int, vector<int>, greater<int>> pq2;

	pq2.push(30);
	pq2.push(10);
	pq2.push(20);

	while (!pq2.empty())
	{
		cout << pq2.top() << " ";
		pq2.pop();
	}
	// ���: 10 20 30
	cout << endl;

	///////////////////////////////////////////////////////////////////////////

	priority_queue<string, vector<string>> pq3;

	pq3.push("C");
	pq3.push("B");
	pq3.push("A");

	while (!pq3.empty())
	{
		cout << pq3.top() << " ";
		pq3.pop();
	}
	// ���: C B A
	cout << endl;

	///////////////////////////////////////////////////////////////////////////

	priority_queue<string, vector<string>, MyCompare> pq4;

	pq4.push("Hello");
	pq4.push("c++");
	pq4.push("world~");

	while (!pq4.empty())
	{
		cout << pq4.top() << " ";
		pq4.pop();
	}
	// ���: C B A
	cout << endl;
}