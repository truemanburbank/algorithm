// BFS�� ���� ���, ���� ����Ʈ�� ǥ���� �� �־�� ��
// BFS�� ť�� ������ �Ѵ�.

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// DFS (Depth First Search) ���� �켱 Ž��
// BFS (Breadth First Search) �ʺ� �켱 Ž��, ��ã�⿡ ����

struct Vertex
{
	// int data
};

vector<Vertex> vertices; // vertex��

// ���� adjacent�� �����ϴµ�, adjacent�� ���빰�� vector<int>�̴�.
vector<vector<int>> adjacent; // vertex �� vertex���� ����
vector<bool> discovered;

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6); // 2���� ����� ����� ��

	// ���� ����Ʈ
	/*
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);*/
	

	 // ���� ���
	adjacent = vector<vector<int>>
	{
		{0, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
	};
}

// BFS

void Bfs(int here)
{
	// ������ ���� �߰ߵǾ�����?
	vector<int> parent(6, -1);

	// ���������� ��ŭ ������ �ִ���?
	vector<int> distance(6, -1);

	queue<int> q;
	q.push(here);
	discovered[here] = true;

	parent[here] = here;
	distance[here] = 0;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		cout << "Visited: " << here << endl;

		// for (int there : adjacent[here]) //����Ʈ
		for(int there = 0; there < 6; there++) // ���
		{
			if (adjacent[here][there] == 0) // ���
				continue;

			if (discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;

			parent[there] = here;
			distance[there] = distance[here] + 1;
		}
	}
}

void BfsAll()
{
	for (int i = 0; i < 6; i++)
		if (discovered[i] == false)
			Bfs(i);
}

int main()
{
	CreateGraph();

	//visited = vector<bool>(6, false);
	//Dfs(0);

	discovered = vector<bool>(6, false);

	Bfs(0);
}