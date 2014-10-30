#include <iostream>

using namespace std;

#define MAXV 100
#define INF 32767

typedef int InfoType;
typedef struct{
	int no;
	InfoType info;
}VertexType;

typedef struct{
	int edges[MAXV][MAXV];
	int vexnum, arcnum;
	VertexType vexs[MAXV];
}MGraph;

void print_matrix(MGraph g)
{
	int i, j;
	for (i = 0; i < g.vexnum; i++)
	{
		for (j = 0; j < g.vexnum; j++)
		{
			if (g.edges[i][j] == INF)
			{
				cout << "¡Þ" << " ";
			}
			else
			{
				cout << g.edges[i][j] << " ";
			}
		}
		cout << endl;
	}
}

void prim(MGraph g, int v)
{
	int distance[MAXV];
	int i, j, k;
	int priev[MAXV];
	int min;
	for (i = 0; i < g.vexnum; i++)
	{
		distance[i] = g.edges[v][i];
		if (g.edges[v][i] != 0 && g.edges[v][i] != INF)
		{
			priev[i] = v;
		}
		else
		{
			priev[i] = -1;
		}
	}
	for (i = 1; i < g.vexnum; i++)
	{
		min = INF;
		for (j = 0; j < g.vexnum; j++)
		{
			if (distance[j] != 0 && distance[j] < min)
			{
				min = distance[j];
				k = j;
			}
		}
		cout << priev[k] << "¡ª¡ª>" << k << " È¨ÖµÎª:" << distance[k] << endl;
		distance[k]=0;
		for (j = 0; j < g.vexnum; j++)
		{
			if (g.edges[k][j] != 0 && g.edges[k][j] < distance[j])
			{
				distance[j] = g.edges[k][j];
				priev[j] = k;
			}
		}
	}
}

int main(int argc, char** argv)
{
	int i, j, u = 3;
	MGraph g;
	int A[MAXV][11];
	g.vexnum = 6; g.arcnum = 10;
	for (i = 0; i<g.vexnum; i++)
	for (j = 0; j<g.vexnum; j++)
		A[i][j] = INF;
	A[0][1] = 5; A[0][2] = 8; A[0][3] = 7; A[0][5] = 3;
	A[1][2] = 4;
	A[2][3] = 5; A[2][5] = 9;
	A[3][4] = 5;
	A[4][5] = 1;
	for (i = 0; i<g.vexnum; i++)
	for (j = 0; j<g.vexnum; j++)
		A[j][i] = A[i][j];
	for (i = 0; i<g.vexnum; i++)
	for (j = 0; j<g.vexnum; j++)
		g.edges[i][j] = A[i][j];
	prim(g, 0);
	return 0;
}
