#include <iostream>
using namespace std;

class Test
{
private:
	int x;
public:
	//explicit Test(int i)
	Test(int i)
	{
		x = i;
		cout << "Called" << endl;
	}
};

int main()
{
	Test t(20);
	t = 30; // conversion constructor is called here.
	return 0;
}

// ���
// Called Called

// Test �����ڴ� 1���� �Ű����� i�� �޴´�.
// �̶� t = 30; �̶�� �������� ��ȯ �����ڰ� ȣ��Ǿ� Test(30);���� �Ͻ��� ��ȯ�Ǿ���
// �׷����� Called ��±����� �ѹ� �� ȣ��� ���̴�.

// �����Ϸ��� �ڵ� ����ȯ�� ���ֱ� ������ �߻��ϴ� ��

//���� Test(int i) ������ �տ� "explicit" Ű���带 �ٿ��ָ� ��ȯ �������� ������ ȣ���� ������
//������ ������ �߻��Ѵ�!


////////////////////// �ٸ� ��ȯ������ ���� ///////////////////////////
/*
class CMyData
{
public:
	CMyData(int x) : nData(x)
	{
		cout << "��ȯ ������ ȣ��" << endl;
	}

private:
	int nData;
};

void TestFunc(const CMyData &rhs) // �и� TestFunc �Լ��� �Ű������� CMyData ��ü�� ������ �޴´�.
{
	cout << "TestFunc(): " << rhs.GetData() << endl;
}

int main()
{
	CMyData a(100);
	TestFunc(a); // �Ϲ����� �Լ� ȣ�� ���

	TestFunc(1000); // ���ڰ����� 1000�� �־��µ��� ������ ������ �߻����� �ʴ´�.
	return 0;
}
 
 */

