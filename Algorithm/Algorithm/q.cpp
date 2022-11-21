#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

template<typename T, typename Container = vector<T>, typename predicate = less<T>>

class Priority_queue
{
public:
	void push(const T& data)
	{
		a.push_back(data);

		// µµÀå ±ú±â
		// now = index
		// int now = static_cast<int>(a.size()) - 1;
		int now = a.size() - 1;

		while (now > 0)
		{
			int next = (now - 1) / 2;
			if (cmp(a[now], a[next]))
				break;

			swap(a[now], a[next]);
			now = next;
		}
	}

	T& top() { return a[0]; }

	void pop()
	{
		a[0] = a.back();
		a.pop_back();

		int now = 0; // index

		while (now <= a.size())
		{
			int left = 2 * now + 1;
			int right = 2 * now + 2;

			if (left >= a.size())
				break;

			int next = now;

			if (cmp(a[next], a[left]))
				next = left;

			if (right <= a.size() - 1 && cmp (a[next], a[right]))
				next = right;

			if (next == now)
				break;

			swap(a[now], a[next]);
			now = next;
		}
	}
private:
	Container a;
	predicate cmp;
};

int main()
{
	Priority_queue<int, vector<int>, greater<int>> q;
	q.push(1);
	q.push(7);
	q.push(6);
	q.push(3);
	q.push(4);

	for (int i = 0; i < 5; i++)
	{
		int top = q.top();
		cout << top << endl;

		q.pop();
	}

}