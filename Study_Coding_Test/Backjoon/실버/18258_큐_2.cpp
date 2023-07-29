#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[2000001];
int front = -1, rear = -1;

bool Empty()
{
	return front == rear;
}

int Size()
{
	return rear - front;
}

void Push()
{
	int num;
	cin >> num;
	arr[++rear] = num;
}

int Pop()
{
	if (Empty())
		return -1;

	int temp = arr[++front];
	arr[front] = 0;
	return temp;
}

int Front()
{
	if (Empty())
		return -1;

	return arr[front + 1];
}

int Back()
{
	if (Empty())
		return -1;
	
	return arr[rear];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	cin >> N;
	while(N--)
	{
		string str;
		cin >> str;

		if (str == "push")
			Push();
		else if (str == "pop")
			cout << Pop() << '\n';
		else if (str == "size")
			cout << Size() << '\n';
		else if (str == "empty")
			cout << Empty() << '\n';
		else if (str == "front")
			cout << Front() << '\n';
		else if (str == "back")
			cout << Back() << '\n';
	}

	return 0;
}