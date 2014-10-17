#include <iostream>
#include <string>
#include <vector>

using namespace std;

void get_next(vector<int>& next, string s)
{
	int k = 0;
	int i;
	next.push_back(0);
	for (int i = 1; i != s.size(); i++)
	{
		while (k>0 && s[i] != s[k])
		{
			k = next[k - 1];
		}
		if (s[i] == s[k])
			k++;
		next.push_back(k);
	}
}

int main(int argc, char** argv)
{
	vector<int> next;
	string s1, s2;
	cout << "ÊäÈë³¤×Ö·û´®ºÍ¶Ì×Ö·û´®£º" << endl;
	while (cin >> s1 >> s2)
	{
		next.clear();
		get_next(next, s2);
		int i, q;
		for (i = 0, q = 0; i != s1.size(); i++)
		{
			while (q>0 && s1[i] != s2[q])
			{
				q = next[q - 1];
			}
			if (s1[i] == s2[q])
			{
				q++;
			}
			if (q == s2.size())
			{
				cout << s2 << " in " << s1 << " start from " << i - s2.size() + 1 << endl;
				break;
			}
		}
	}
	return 0;
}