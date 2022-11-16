#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 양방향 리스트
// 리스트 삭제 연산이 빠를 때는 삭제할 데이터의 위치를 알고 있을 때
// 즉, 조건부적으로 맞는 말이다.
template<typename T>
class Node // 노드
{
public:
	Node() : _prev(nullptr), _next(nullptr), _data(T()) // 생성자
	{

	}

	Node(const T& value) : _prev(nullptr), _next(nullptr), _data(value)
	{

	}

public:
	Node*	_prev;
	Node*	_next;
	T		_data;
};

template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr)
	{

	}

	Iterator(Node<T>* node) : _node(node)
	{

	}

	// ++it
	Iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}
	// it++
	Iterator operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}
	// --it
	Iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}
	// it--
	Iterator operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	// *it
	T& operator*()
	{
		return _node->_data;
	}

	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}

	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}
public:
	Node<T>* _node;
};

template<typename T>
class List
{
public:
	List() : _size(0)
	{	// head <-> tail
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->_next = _tail;
		_tail->_prev = _head;
	}

	~List()
	{
		while (_size > 0)
			pop_back();
		delete _head;
		delete _tail;
	}

	void push_back(const T& value) // tail 바로 전에 데이터 삽입
	{
		AddNode(_tail, value);
	}

	void pop_back() // tail 바로 전의 데이터 삭제
	{
		RemoveNode(_tail->_prev);
	}

private:		// before: 새로운 노드의 다음 위치 노드
				// head <-> 1 <-> prevNode  <-> "newNode" <-> before <-> tail
	Node<T>* AddNode(Node<T>* before, const T& value) // insert, push에 사용할 함수
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = before->_prev;

		prevNode->_next = newNode;
		newNode->_prev = prevNode;

		newNode->_next = before;
		before->_prev = newNode;

		_size++;

		return newNode;
	}

	// head <-> 1 <-> prevNode  <-> "deleteNode" <-> nextnode <-> tail
	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode;
	}

	int size() { return _size; }

public:
	using iterator = Iterator<T>;
	iterator begin() { return iterator(_head->_next); }
	iterator end() { return iterator(_tail); }

	// it 앞에 추가
	iterator insert(iterator it, const T& value)
	{
		Node<T>* node = AddNode(it._node, value);
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}

private:
	Node<T>*	_head; // head, tail이 null일 수 있으므로 계속 null 체크를 해 줘야 함
	Node<T>*	_tail;
	int			_size;
};

int main()
{
	List<int> li;

	List<int>::iterator eraselt;
	// 리스트는 임의 접근 불가
	// li[3] = 3 불가
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			// 리스트 end 이전에 데이터를 삽입
			eraselt = li.insert(li.end(), i); // 삽입한 원소의 이터레이터 반환
		}
		else
		{
			li.push_back(i); // void 반환
		}
	}

	li.pop_back(); // 9 pop
	li.erase(eraselt); // eraselt가 5를 가리키고 있는데 그것을 바로 지울 수 있음

	// 리스트 처음부터 끝까지 갈 때까지, 하나씩 증가
	for (List<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << (*it) << endl;
	}
	// vector
	// - push_back -> O(1)
	// - push_front -> 굉장히 느리다. O(N) vector에선 제공 안 함
	// 임의 접근 가능
}