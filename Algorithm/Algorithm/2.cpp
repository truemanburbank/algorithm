#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// BFS (행렬 ver)

struct Vertex
{
	// int data;
};

vector<Vertex> vertexes; // vertex들

vector<vector<int>> adjacent; // 인접
vector<bool> discovered(6, false);

void CreateGraph()
{
	vertexes.resize(6);
	adjacent = vector<vector<int>>(6); // 2차원 행렬

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

void Bfs(int here)
{
	queue<int> q;
	q.push(here);
	discovered[here] = true;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		cout << "Visited: " << here << endl;

		for (int there = 0; there < 6; there++)
		{
			if (adjacent[here][there] == 0)
				continue;

			if (discovered[there] == true)
				continue;

			q.push(there);
			discovered[there] = true;
		}
	}
}

void BfsAll()
{
	for (int i = 0; i < 6; i++)
	{
		if (discovered[i] == false)
			Bfs(i);
	}
}

int main()
{
	CreateGraph();
	BfsAll();

	return 0;
}