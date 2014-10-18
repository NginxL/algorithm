#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>

using namespace std;

void Dijkstra(const int startVertex,int map[13][13],int* distance,int* prevVertex)
{
	vector<bool> isInS;
	isInS.reserve(0);
	isInS.assign(13,false);

	for(int i=1;i<=12;i++)
	{
		distance[i]=map[startVertex][i];
		if(map[startVertex][i]<INT_MAX)
		{
			prevVertex[i]=startVertex;
		}
		else
		{
			prevVertex[i]=-1;
		}
	}
	prevVertex[startVertex]=-1;

	isInS[startVertex]=true;
	int u=startVertex;

	for(int i=1;i<12;i++)
	{
		int nextVertex=u;
		int tempDistance=INT_MAX;
		for(int j=1;j<=12;j++)
		{
			if(isInS[j]==false && distance[j]<tempDistance)
			{
				nextVertex=j;
				tempDistance=distance[j];
			}
		}
		isInS[nextVertex]=true;
		u=nextVertex;
		for(int j=1;j<=12;j++)
		{
			if(isInS[j]==false && map[u][j]<INT_MAX)
			{
				int temp=distance[u]+map[u][j];
				if(temp<distance[j])
				{
					distance[j]=temp;
					prevVertex[j]=u;
				}
			}
		}
	}
}

int main(int argc,char** argv)
{
	int map[13][13];
	for(int i=1;i<=12;i++)
	{
		for(int j=1;j<=12;j++)
		{
			if(i==j)
			{
				map[i][j]=0;
			}
			else
			{
				map[i][j]=INT_MAX;
			}
		}
	}

	for(int i=1;i<=12;i++)
	{
		for(int j=1;j<=12;j++)
		{
			int temp;
			cin>>temp;
			map[i][j]=temp;
		}
	}

	int distance[13]={0};
	int preVertex[13]={0};
	cout<<"your start node£º";
	int startVertex;
	stack<int> st;
	while(cin>>startVertex)
	{
		while(!st.empty())
		{
			st.pop();
		}
		Dijkstra(startVertex,map,distance,preVertex);
		for(int i=1;i<=12;i++)
		{
			if(distance[i]==INT_MAX)
			{
				continue;
			}
			cout<<startVertex<<"->"<<i<<" shortest distance is:"<<distance[i]<<endl;
			cout<<"path is:";
			int j;
			j=i;
			st.push(j);
			while(preVertex[j]!=-1)
			{
				st.push(preVertex[j]);
				j=preVertex[j];
			}
			while(!st.empty())
			{
				cout<<st.top()<<" ";
				st.pop();
			}
		}
	}
	return 0;
}
