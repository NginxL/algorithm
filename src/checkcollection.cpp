#include <iostream>
#include <vector>

using namespace std;

void init(vector<int>& v)
{
	for(int i=0;i!=v.size();i++)
	{
		v[i]=-1;
	}
}

int find(vector<int>& v,int x)
{
	if(v[x]<0)
		return x;
	return find(v,v[x]);
}

void union_set(int r1,int r2)
{
	r1=find(r1);
	r2=find(r2);
	if(r1==r2)
	{
		return;
	}
	if(v[r1]>v[r2])
	{
		v[r1]=r2;
	}
	else
	{
		if(v[r1]==v[r2])
		{
			v[r1]--;
		}
		v[r2]=r1;
	}
}

int main(int argc,char** argv)
{
	/*
	 *	¼ÓÈë²Ù×÷
	 */
	return 0;
}