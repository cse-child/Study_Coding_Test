#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// ȿ���� �׽�Ʈ ��� ���� -> ���ڿ� ������ �ϸ� ���������� ���ĵȴ�
bool solution(vector<string> phone_book) {
	for (string b : phone_book)
		cout << b << endl;

	sort(phone_book.begin(), phone_book.end());

	cout << endl;
	for (string b : phone_book)
		cout << b << endl;

	for (int i = 0; i < phone_book.size() - 1; i++)
		if (phone_book[i + 1].find(phone_book[i]) == 0) return false;

	return true;
}

//int main()
//{
//	vector<string> v = { "119", "97674223", "1195524421" };
//	solution(v);
//}