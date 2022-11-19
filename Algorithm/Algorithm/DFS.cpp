// DFS�� ���� ���, ���� ����Ʈ�� ǥ���� �� �־�� ��

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// DFS (Depth First Search) ���� �켱 Ž��
// BFS (Breadth First Search) �ʺ� �켱 Ž��

struct Vertex
{
	// int data
};

vector<Vertex> vertices; // vertex��

// ���� adjacent�� �����ϴµ�, adjacent�� ���빰�� vector<int>�̴�.
vector<vector<int>> adjacent; // vertex �� vertex���� ����
vector<bool> visited;

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
	adjacent[5].push_back(4);
	*/

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

// DFS

// Dfs(0)
// - Dfs(1)
// -- Dfs(2)
// -- Dfs(3)
// --- Dfs(4)
void Dfs(int here)
{
	// �湮
	visited[here] = true;
	cout << "Visited: " << here << endl;

	// ���� ����Ʈ version
	//// ��� ���� ������ ��ȸ�Ѵ�.
	//for (int i = 0; i < adjacent[here].size(); i++)
	//{
	//	int there = adjacent[here][i];

	//	if (visited[there] == false)
	//		Dfs(there);
	//}

	// ���� ��� version
	// ��� ���� ������ ��ȸ�Ѵ�.
	for (int there = 0; there < 6; there++)
	{
		if (adjacent[here][there] == 0)
			continue; // for���� �׳� ó������ �ѱ��.

		// ���� �湮���� ���� ���� ������ �湮�Ѵ�.
		if (visited[there] == false)
			Dfs(there);
	}
}

// ���� �ִ� ������ Ž���Ϸ���
void DfsAll()
{
	visited = vector<bool>(6, false);

	for (int i = 5; i >= 0; i--)
		if (visited[i] == false)
			Dfs(i);
}

int main()
{
	CreateGraph();

	//visited = vector<bool>(6, false);
	//Dfs(0);
	
	DfsAll();
}