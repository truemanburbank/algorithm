#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
using namespace std;
// �׷���/Ʈ�� ����
// ������ ����: �ּ� ���д� Ʈ�� (Minimum Spanning Tree)

// ��ȣ ��Ÿ�� ����(Disjoint Set)
// -> ���Ͽ�-���ε� Union-Find 

// Lineage Battleground (ȥ��!)
// ������ + �����̹�
// 1�� �� 1000 ��(�� id 0~999)
// ���� (1���� + 2���� = 1����)

void LineageBattleground()
{
	struct User
	{
		int teamId;

	};

	// TODO : UserManager
	vector<User> users;
	for (int i = 0; i < 1000; i++)
	{
		users.push_back(User{ i });
	}

	// �� ����
	// users[1] <-> users[5]
	users[5].teamId = users[1].teamId; // 1

	// teamId=1�� ���� teamId=2�� ���� ����
	for (User& user : users)
	{
		if (user.teamId == 1)
			user.teamId = 2;
	}

	// ã�� ���� O(1)
	// ��ġ�� ���� O(N)
}

// Ʈ�� ������ �̿��� ��ȣ ��Ÿ�� ������ ǥ��
struct Node
{
	Node* leader;
};

// �ð� ���⵵: Ʈ���� ���̿� ����� �ð��� �ɸ�
class NaiveDisjointSet
{
public:
	NaiveDisjointSet(int n) :_parent(n)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	// �� ������ ��������
	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		return Find(_parent[u]);
	}
	
	// u�� v�� ��ģ�� (u�� v ������)
	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		_parent[u] = v;
	}

private:
	vector<int> _parent;
};

// Ʈ���� �������� ���� ������ �ذ�
// Ʈ���� ��ĥ �� �׻� ���̰� ���� Ʈ���� ���̰� ���� Ʈ�� ������
// (Union-By-Rank)


// �ð����⵵ O(Ackermann(n)) = O(1)
class DisjointSet
{
public:
	DisjointSet(int n) :_parent(n), _rank(n, 1)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	// �� ������ ��������
	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		return _parent[u] = Find(_parent[u]);
	}

	// u�� v�� ��ģ��
	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		if (_rank[u] > _rank[v])
			swap(u, v);

		// rank[u] <= rank[v] �����

		_parent[u] = v;
		if (_rank[u] == _rank[v])
			_rank[v]++;
	}

private:
	vector<int> _parent;
	vector<int> _rank;
};

int main()
{
	DisjointSet teams(1000);

	teams.Merge(10, 1);
	int teamId = teams.Find(1);
	int teamId2 = teams.Find(10);

	teams.Merge(3, 2);
	int teamId3 = teams.Find(3);
	int teamId4 = teams.Find(2);

	teams.Merge(1, 3);
	int teamId5 = teams.Find(1);
	int teamId6 = teams.Find(3);

}