#include<cstdio>
#include<algorithm>
//ʹ�� bfs
using namespace std;
const int maxn = 1e3+20;
int din[maxn];
int stack[maxn];
int tot;
int num;
int num_edge;
int head[maxn];
struct Edge{
	int next;
	int to;
}edge[maxn];
void add(int from,int to)
{
	edge[++num_edge].next = head[from];
	edge[num_edge].to = to;
	head[from] = num_edge;
}
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;scanf("%d%d",&a,&b);
		add(a,b);
		din[b]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(din[i]==0) stack[++tot]=i;
	}
	while(tot>0)
	{
		int u =stack[tot];
		tot--; num++;
		printf("%d ",u);
		for(int i=head[u];i!=0;i=edge[i].next)
		{
			int v = edge[i].to; //
			din[v]--;
			if(din[v]==0)
				stack[++tot] = v;	
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
6 1 2 3 4 5
*/
