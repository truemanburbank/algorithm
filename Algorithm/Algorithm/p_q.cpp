// 구현 연습하기
// 꼭 기억하기

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
		// 우선 힙 구조부터 맞춰준다.
		_heap.push_back(data);

		// 도장 깨기 시작
		// 시작 위치
		int now = static_cast<int>(_heap.size()) - 1;

		// 루트 노드까지 계속 시도
		while (now > 0)
		{
			// 부모 노드의 데이터와 비교해서 더 작으면 패배
			int next = (now - 1) / 2; // 부모 인덱스
			/*if (_heap[now] < _heap[next])
				break;*/
			if (_predicate(_heap[now], _heap[next]))
				break;

			// 데이터 교체
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

			// 리프에 도달한 경우 (범위 확인)
			if (left >= _heap.size())
				break;

			int next = now;

			// 왼쪽과 비교
			if (_predicate(_heap[next], _heap[left]))
				// next => 결국 내가 자리하게 될 인덱스
				next = left;

			// 둘 중 승자를 오른쪽과 비교
			if (right < _heap.size() && _predicate(_heap[next], _heap[right]))
				next = right;

			// 왼쪽/오른쪽 둘 다 현재 값보다 작으면 종료
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
	// 작은 순으로 출력하고 싶다면
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