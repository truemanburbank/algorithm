#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

void CreateGraph_1()
{
	// 연결 리스트와 비슷한 방식으로 구현
	struct Vertex
	{
		// 연결리스트와는 다르게 여러 방향을 가리킬 수 있으므로
		// vector를 사용
		vector<Vertex*> edges;
	};

	vector<Vertex> v;
	v.resize(6); // 6개 생성 (벡터배열 6개)

	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);
	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	v[3].edges.push_back(&v[4]);
	v[5].edges.push_back(&v[4]);

	// Q) 0번과 3번 정점이 연결되어 있나요?
	bool connetced = false;

	// 범위 기반 for문: v[0].edges의 원소를 돈다.
	for (Vertex* edge : v[0].edges)
	{
		if (edge == &v[3])
		{
			connetced = true;
			break;
		}
	}
}

void CreateGraph_2()
{
	struct Vertex
	{

	};

	vector<Vertex> v;
	v.resize(6); // 6개 생성 (벡터배열 6개)
	
	// 연결된 목록을 따로 관리
	// 2차원 배열
	// adjacent[n] -> n번째 정점과 연결된 정점 목록
	vector<vector<int>> adjacent(6);
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	// 정점이 100개
	// - 지하철 노선도 -> 서로 드문 드문 연결 (양옆, 환승역이라면 조금 더 많다)
	// - 페이스북 친구 -> 서로 빽빽하게 연결

	// Q) 0번과 3번 정점이 연결되어 있나요?
	bool connetced = false;

	// 범위 기반 for문: v[0].edges의 원소를 돈다.
	for (int vertex : adjacent[0])
	{
		if (vertex == 3)
		{
			connetced = true;
			break;
		}
	}

	// STL
	vector<int>& adj = adjacent[0];
	bool connected2 = (std::find(adj.begin(), adj.end(), 3) != adj.end());
}

void CreateGraph_3()
{
	struct Vertex
	{

	};

	vector<Vertex> v;
	v.resize(6); // 6개 생성 (벡터배열 6개)

	// 연결된 목록을 따로 관리
	// 2차원 행렬로 생각
	// 메모리를 많이 소모하지만 빠른 접근
	// 간선이 많은 경우 이점이 있다.

	// 읽는 방법: adjacent[from][to]
	vector<vector<bool>> adjacent(6, vector<bool>(6, false));
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	// 정점이 100개
	// - 지하철 노선도 -> 서로 드문 드문 연결 (양옆, 환승역이라면 조금 더 많다)
	// - 페이스북 친구 -> 서로 빽빽하게 연결

	// Q) 0번과 3번 정점이 연결되어 있나요?
	bool connected = adjacent[0][3];

	vector<vector<int>> adjacent2 =
	{
		vector<int> {-1, 15, -1, 35, -1, -1},
		vector<int> {15, -1, 5, 10, -1, -1},
		vector<int> {-1, -1, -1, -1, -1, -1},
		vector<int> {-1, -1, -1, -1, 5, -1},
		vector<int> {-1, -1, -1, -1, -1, -1},
		vector<int> {-1, -1, -1, -1, +5, -1},
	};
}

int main()
{
	CreateGraph_1();
	CreateGraph_2();
}