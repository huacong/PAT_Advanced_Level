#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 1e3+20; //最大可能的点的个数 
struct Edge{
	int next;
	int to;
}edge[maxn];
int head[maxn];
int num_edge;
int n,m;
int din[maxn];
void add_edge(int from, int to)
{
	edge[++num_edge].next = head[from];
	edge[num_edge].to = to;
	head[from] = num_edge;
}
void dfs(int u)
{
	for(int i=head[u];i!=0;i=edge[i].next)
	{
		int v=  edge[i].to;
		din[v]--;
		if(din[v]==0)
		{
			printf("%d ",v);
			din[v] = -1;
			dfs(v);
		}
		
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;scanf("%d%d",&a,&b);
		add_edge(a,b);
		din[b]++;
	}
	for(int i=1;i<=n;i++)//使用邻接链表的dfs
	{
		if(din[i]==0)
		{
			printf("%d ",i);
			dfs(i);
		}
	 } 
	return 0;
}
/*
6 6
1 2
1 3
1 4
2 5
3 5
4 5
1 4 3 2 5 6
*/
