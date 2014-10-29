#include <iostream>
#include <vector>

using namespace std;

void Bubble_Sort(vector<int>& a)
{
	for (int i = 0; i != a.size() - 1; i++)
		for (int j = i + 1; j != a.size(); j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
}

void Select_Sort(vector<int>& a)
{
	for (int i = 0; i != a.size() - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j != a.size(); j++)
		{
			if (a[k] > a[j])
				k = j;
		}
		int temp = a[i];
		a[i] = a[k];
		a[k] = temp;
	}
}

void Insert_Sort(vector<int>& a)
{
	for (int i = 1; i != a.size(); i++)
	{
		int temp = a[i];
		int j;
		for (j = i; j > 0 && a[j - 1] > temp; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}
}

void print(const vector<int>& a)
{
	for each (int var in a)
	{
		cout << var << " ";
	}
	cout << endl;
}

int main(int argc,char** argv)
{
	int a[16] = {9,8,7,6,5,4,4,4,3,3,2,14,32,1,1,2};
	
	vector<int> v1(a,a+10);
	vector<int> v2(a,a+11);
	vector<int> v3(a,a+16);
	
	Bubble_Sort(v1);
	Select_Sort(v2);
	Insert_Sort(v3);
	
	print(v1);
	print(v2);
	print(v3);

	return 0;
}