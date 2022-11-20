// ���� �����ϱ�
// �� ����ϱ�

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

template<typename T, typename Container = vector<T>, typename Predicate = less<T> >
class PriorityQueue
{
public:
	void push(const T& data)
	{
		// �켱 �� �������� �����ش�.
		_heap.push_back(data);

		// ���� ���� ����
		// ���� ��ġ
		int now = static_cast<int>(_heap.size()) - 1;

		// ��Ʈ ������ ��� �õ�
		while (now > 0)
		{
			// �θ� ����� �����Ϳ� ���ؼ� �� ������ �й�
			int next = (now - 1) / 2; // �θ� �ε���
			/*if (_heap[now] < _heap[next])
				break;*/
			if (_predicate(_heap[now], _heap[next]))
				break;

			// ������ ��ü
			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	void pop()
	{
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;
		while (true)
		{
			int left = 2 * now + 1;
			int right = 2 * now + 2;

			// ������ ������ ��� (���� Ȯ��)
			if (left >= _heap.size())
				break;

			int next = now;

			// ���ʰ� ��
			if (_predicate(_heap[next], _heap[left]))
				// next => �ᱹ ���� �ڸ��ϰ� �� �ε���
				next = left;

			// �� �� ���ڸ� �����ʰ� ��
			if (right < _heap.size() && _predicate(_heap[next], _heap[right]))
				next = right;

			// ����/������ �� �� ���� ������ ������ ����
			if (next == now)
				break;

			::swap(_heap[now], _heap[next]);
			now = next;
		}

	}

	T& top()
	{
		return _heap[0];
	}

	bool empty()
	{
		return _heap.empty();
	}
private:
	Container _heap = {};
	Predicate _predicate = {};
};

int main()
{
	// ���� ������ ����ϰ� �ʹٸ�
	// priority_queue<int, vector<int>, greater<int>> pq;
	PriorityQueue<int, vector<int>, greater<int>> pq;

	pq.push(1);
	pq.push(3);
	pq.push(2);
	pq.push(5);
	pq.push(4);

	while (pq.empty() == false)
	{
		int value = pq.top();
		pq.pop();

		cout << value << endl;
	}
}