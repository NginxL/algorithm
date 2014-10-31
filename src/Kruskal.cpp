#include <iostream>
#include <queue>

using namespace std;

struct EdgeNode
{
	int v1;
	int v2;
	int value;
	bool operator<(const EdgeNode& a)const
	{
		return a.value < value;
	}
};

int* root;

priority_queue<EdgeNode> pq;

int Find(int x)
{
	if (root[x] < 0)
		return x;
	return Find(root[x]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
	{
		root[a] = b;
	}
}

void Kruskal()
{
	EdgeNode b;
	int t1, t2;
	cout << "������С�������еı�һ��Ϊ��" << endl;
	while (!pq.empty())
	{
		b = pq.top();
		pq.pop();

		t1 = Find(b.v1);
		t2 = Find(b.v2);
		if (t1 != t2 )
		{
			cout << b.v1 << "---" << b.v2 << "  ȨֵΪ��" << b.value << endl;
			Union(b.v1, b.v2);
		}
	}
}

int main(int argc,char** argv)
{
	int n = 0;
	int m = 0;
	cout << "������ͼ�еĸ�����" << endl;
	cin >> n;

	root = new int[n+1];

	for (int i = 1; i <= n; i++)
	{
		root[i] = i;
	}
	
	cout << "������ͼ�бߵ�������" << endl;
	cin >> m;

	cout << "����������ÿ���ߵ��������㼰��Ȩ�أ�" << endl;

	EdgeNode a;
	while (m--)
	{
		cin >> a.v1 >> a.v2 >> a.value;
		pq.push(a);
	}
	Kruskal();

	return 0;
}
