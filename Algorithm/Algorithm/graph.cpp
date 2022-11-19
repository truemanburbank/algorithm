#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

void CreateGraph_1()
{
	// ���� ����Ʈ�� ����� ������� ����
	struct Vertex
	{
		// ���Ḯ��Ʈ�ʹ� �ٸ��� ���� ������ ����ų �� �����Ƿ�
		// vector�� ���
		vector<Vertex*> edges;
	};

	vector<Vertex> v;
	v.resize(6); // 6�� ���� (���͹迭 6��)

	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);
	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	v[3].edges.push_back(&v[4]);
	v[5].edges.push_back(&v[4]);

	// Q) 0���� 3�� ������ ����Ǿ� �ֳ���?
	bool connetced = false;

	// ���� ��� for��: v[0].edges�� ���Ҹ� ����.
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
	v.resize(6); // 6�� ���� (���͹迭 6��)
	
	// ����� ����� ���� ����
	// 2���� �迭
	// adjacent[n] -> n��° ������ ����� ���� ���
	vector<vector<int>> adjacent(6);
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	// ������ 100��
	// - ����ö �뼱�� -> ���� �幮 �幮 ���� (�翷, ȯ�¿��̶�� ���� �� ����)
	// - ���̽��� ģ�� -> ���� �����ϰ� ����

	// Q) 0���� 3�� ������ ����Ǿ� �ֳ���?
	bool connetced = false;

	// ���� ��� for��: v[0].edges�� ���Ҹ� ����.
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
	v.resize(6); // 6�� ���� (���͹迭 6��)

	// ����� ����� ���� ����
	// 2���� ��ķ� ����
	// �޸𸮸� ���� �Ҹ������� ���� ����
	// ������ ���� ��� ������ �ִ�.

	// �д� ���: adjacent[from][to]
	vector<vector<bool>> adjacent(6, vector<bool>(6, false));
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	// ������ 100��
	// - ����ö �뼱�� -> ���� �幮 �幮 ���� (�翷, ȯ�¿��̶�� ���� �� ����)
	// - ���̽��� ģ�� -> ���� �����ϰ� ����

	// Q) 0���� 3�� ������ ����Ǿ� �ֳ���?
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