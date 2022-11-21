#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

struct Vertex
{
	// int data;
};

vector<Vertex> vertexes; // vertex들

vector<vector<int>> adjacent; // 인접

void CreateGraph()
{
	vertexes.resize(6);
	adjacent = vector<vector<int>>(6, vector<int>(6, -1)); // 2차원 행렬

	adjacent[0][1] = 15;
	adjacent[0][3] = 35;
	adjacent[1][0] = 15;
	adjacent[1][2] = 5;
	adjacent[1][3] = 35;
	adjacent[3][4] = 5;
	adjacent[5][4] = 5;
}

void dijkstra(int here)
{
	struct VertexCost
	{
		int vertex;
		int cost;
	};

	list<VertexCost> discovered;

	vector<int> best(6, INT32_MAX);
	vector<int> parent(6, -1);

	discovered.push_back(VertexCost{ here, 0 });
	best[here] = 0; // 시작점
	parent[here] = here;

	cout << "Vertex: " <<  here << endl;
	cout << "cost: " << best[here] << endl;
	cout << "parent: " << parent[here] << endl;
	cout << endl;

	while (discovered.empty() == false)
	{
		list<VertexCost>::iterator bestit;
		int bestcost = INT32_MAX;

		for (auto it = discovered.begin(); it != discovered.end(); it++)
		{
			if (it->cost < bestcost)
			{
				bestcost = it->cost;
				bestit = it;
			}
		}

		here = bestit->vertex;
		int cost = bestit->cost;
		discovered.erase(bestit);

		if (best[here] < cost) //??
			continue;

		for (int there = 0; there < 6; there++)
		{
			if (adjacent[here][there] == -1)
				continue;

			int nextcost = best[here] + adjacent[here][there];
			if (nextcost >= best[there])
				continue;

			discovered.push_back(VertexCost{ there, nextcost });
			parent[there] = here;
			best[there] = nextcost;

			cout << "Vertex: " << there << endl;
			cout << "cost: " << best[there] << endl;
			cout << "parent: " << parent[there] << endl;
			cout << endl;
		}
	}
}


int main()
{
	CreateGraph();
	dijkstra(0);

	return 0;
}