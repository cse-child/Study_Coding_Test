#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	// A: ���� �ö󰡴� �Ÿ�
	// B: �㿡 �̲������� �Ÿ�
	// V: ���������� ����
	int A, B, V;
	int days = 0;
	int curV = 0;

	cin >> A >> B >> V;

	// ���� �ö� �Ŀ��� �����̰� �̲������� �ʱ� ������
	// ��ǥ ������ V�� �ƴ�, V-A�̴�.
	// V-A�� �����ϸ� ������ A��ŭ �ö� ���� �����ϱ� ����
	days += (V - A) / (A - B) + 1;

	// (V-A)%(A-B) �� 0�϶��� ������ A��ŭ �ö� 1�� ���ϸ� ������
	// 0�� �ƴҶ��� ���� �����ϱ⿡ �̵��Ÿ��� A���� ���� ���߶� �Ϸ縦 �߰��� �����ָ� �ȴ�.
	if ((V - A) % (A - B) != 0)
		days++;

	cout << days << endl;
	return 0;
}