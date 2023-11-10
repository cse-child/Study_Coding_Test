#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
	A()
	{
		cout << "Call A" << endl;
	}
};

int main()
{
	vector<A> v;
	v.resize(100);

	return 0;
}