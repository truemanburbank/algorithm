#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// DFS (행렬 ver)

struct Vertex
{
	// int data;
};

vector<Vertex> vertexes; // vertex들

vector<vector<int>> adjacent; // 인접
vector<bool> visited(6, false);

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

void Dfs(int here)
{
	visited[here] = true;

	cout << "Visited: " << here << endl;

	for (int there = 0; there < 6; there++)
	{
		if (adjacent[here][there] == 0)
			continue;

		if (visited[there] == false)
			Dfs(there);
	}
}

void DfsAll()
{
	for (int i = 0; i < 6; i++)
	{
		if (visited[i] == false)
			Dfs(i);
	}
}

void main()
{
	CreateGraph();
	DfsAll();
}