#include <iostream>
using namespace std;

int solution(int n)
{
	int pos = n;
	int energy = 0;
	
	while(pos > 0)
	{
		if (pos % 2 == 0)
			pos /= 2;
		else
		{
			pos--;
			energy++;
		}
	}

	return energy;
}

int main()
{
	cout << solution(5000);

	return 0;
}


// ��Ư�� Ǯ��

/*
 public int solution(int n) {
	return Integer.bitCount(n);
}

�ᱹ, ���� �ذ��� ���ؼ� 2�� �󸶳� �������������� ���� �ϱ� ������
n�� 2������ ��ȯ�� �� �߻��ϴ� 1�� ������ ī�����ϸ� �ȴ�.

2������ 1,2,4,8,16,... ���� 2�� ��������ŭ �þ�� ������
2�� ���������� �ʴ� ���� 1�� �߻��ϰ� �ȴ�.
�̷��� Ư���� Ȱ���� 1�� ������ ī�����ϸ� �Ǵ°��̴�.

*/



