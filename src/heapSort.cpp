#include <iostream>
#include <vector>

using namespace std;

inline int leftChild(int i)
{
	return 2 * i + 1;
}

void pcreDown(vector<int>& v, int i, int n)
{
	int temp = v[i];
	int Child;
	for (; leftChild(i)<n; i = Child)
	{
		Child = leftChild(i);
		if (Child != n - 1 && v[Child]<v[Child + 1])
		{
			Child = Child + 1;
		}
		if (temp<v[Child])
		{
			v[i] = v[Child];
		}
		else
		{
			break;
		}
	}
	v[i] = temp;
}

void heapSort(vector<int>& a)
{
	for (int i = a.size() / 2; i >= 0; i--)
	{
		pcreDown(a, i, a.size());
	}
	for (int i = a.size() - 1; i>0; i--)
	{
		swap(a[0], a[i]);
		pcreDown(a, 0, i);
	}
}

int main(int argc, char** argv)
{
	vector<int> v;
	cout << "please entry number for sort:" << endl;
	int temp;
	while (cin >> temp)
	{
		v.push_back(temp);
	}
	heapSort(v);
	for (int i = 0; i != v.size() - 1; i++)
	{
		cout << v[i] << " ";
	}
	cout << v[v.size() - 1] << endl;
	system("pause");
	return 0;
}