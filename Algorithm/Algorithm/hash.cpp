#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <thread>
using namespace std;

// ������ ����: �ؽ� ���̺�

// Q) map vs hash_map (C+11 ǥ�� unordered_map)

// map : Red-Black Tree
// - �߰�/Ž��/���� O(logN)

// C# dictionary = C++ map (X)
// C# dictionary = C++ unordered_map

// hash_map (unordered_map)
// - �߰�/Ž��/���� O(1)

// ���� ���ְ� ���� ���Ѵ�...
// �޸𸮸� ���ְ� �ӵ��� ���Ѵ�.

// ����Ʈ ������
// [201][202][203][204][205]
// [101][102][103][104][105]

// 1~1000 user(userId = 1~999)

// [1][2][3][][]...[999]

// '�ؽ�' '���̺�'
// O(1)
void TestTable()
{
	struct User
	{
		int userId = 0; // 1~999
		string username;
	};

	vector<User> users;
	users.resize(1000);

	// 777 �� ���� ���� ����
	users[777] = User{ 777, "Rookiss" };

	// 777 �� ���� �̸���?
	string name = users[777].username;
	cout << name << endl;

	// ���̺�
	// Ű�� �˸�, �����͸� �ܹ��� ã�� �� �ִ�.

	// ������ ��Ȳ
	// int32_max(3��~)
	// �޸𸮵� ������ �ƴϴ�.
}

// ����
// id: rookiss + pw: qwer1234
// id: rookiss + pw: hash(qwer1234) -> sdafjfj23$@$!#$!

// DB [rookiss][sdafjfj23$@$!#$!]
// ��й�ȣ ã�� -> ���̵� �Է� �� ���� -> �� ��й�ȣ�� �Է��ϼ���

void TestHash()
{
	struct User
	{
		int userId = 0; // 1~int32_max
		string username;
	};

	vector<User> users;
	users.resize(1000);

	const int userId = 123456789;
	int key = (userId % 1000); // hash < ���� ��ȣ
	// 123456789 �� ���� ���� ����
	users[key] = User{ userId, "Rookiss" };

	// 123456789 �� ���� �̸���?
	User& user = users[key];
	if (user.userId == userId)
	{
		string name = user.username;
		cout << name << endl;
	}

	// �浹 ����
	// �浹�� �߻��� �ڸ��� ����ؼ� �ٸ� ���ڸ��� ã�Ƴ�����.
	// - ���� ����� (linear probing)
	// hash(key) + 1 -> hash(key) + 2
	// - ���� ����� (quadratic probing)
	// hash(key)+ 1^2 -> hash(key) + 2^2
	// etc

	// ü�̴�
	// 
}
// O(1)
void TestHashTableChaining()
{
	struct User
	{
		int userId = 0; // 1~int32_max
		string username;
	};
	vector<vector<User>> users;
	users.resize(1000);

	const int userId = 123456789;
	int key = (userId % 1000); // hash < ���� ��ȣ

	// 123456789 �� ���� ���� ����
	users[key].push_back(User{ userId, "Rookiss" });
	users[789].push_back(User{ 789, "Faker" });

	// 123456789 ���� �̸���?
	vector<User>& bucket = users[key];
	for (User& user : bucket)
	{
		if (user.userId == userId)
		{
			string name = user.username;
			cout << name << endl;
		}
	}
}

int main()
{
	// TestTable();
	// TestHash();
	TestHashTableChaining();
}