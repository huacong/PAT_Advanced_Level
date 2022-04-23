#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 505;
const int maxn = 3e5+20; 
const int INF = 0x3f3f3f3f;
struct Edge{
	int next; // 数组模拟邻接表，next指向下一条边 
	int to;// 这个边所对应的下一个节点
	int dis;//这条边的距离 
	int cost;//这条边的花费 
}edge[maxn];
int head[N];
int num_edge;
void add_edge(int from,int to,int dis,int cos)
{
	edge[++num_edge].next = head[from];
	edge[num_edge].to = to;
	edge[num_edge].dis = dis;
	edge[num_edge].cost = cos;
	head[from] = num_edge;
}

int n,m,src,dst;
int dist[maxn];
int cost[maxn];
int pre[maxn];
int vis[maxn];
void print(int x)
{
	//printf("*%d\n",x);
	if(pre[x]==-1) printf("%d ",x);
	else {
		print(pre[x]);
		printf("%d ",x);
	}
}
void Dij()
{
	for(int i=0;i<n;i++)
		dist[i]=cost[i]=INF;
	for(int i=0;i<n;i++)
		pre[i] = -1;
	dist[src] = 0;
	cost[src] = 0;
	for(int i=0;i<n;i++)
	{
		int u=-1;
		int min_dis = INF;
		for(int j=0;j<n;j++)
		{
			if(!vis[j]&&dist[j]<min_dis)
			{
				u = j;
				min_dis = dist[j];
			}
		}
		if(u==-1) break;
		vis[u] = 1;
		for(int i=head[u];i!=0;i=edge[i].next)
		{
			int v = edge[i].to;
			int dis = edge[i].dis;
			int cos = edge[i].cost;
			if(!vis[v])
			{
				if(dist[v]>dist[u]+dis)
				{
					dist[v] = dist[u]+dis;
					cost[v] = cost[u]+cos;
					pre[v] = u;
				}
				else if(dist[v]==dist[u]+dis&&cost[v]>cost[u]+cos)
				{
					cost[v] = cost[u]+cos;
					pre[v] = u;
				}
			}
		}
	} 
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&src,&dst);
	for(int i=1;i<=m;i++)
	{
		int a,b,d,c;
		scanf("%d%d%d%d",&a,&b,&d,&c);
		add_edge(a,b,d,c);
		add_edge(b,a,d,c);
	}
	Dij();
//	for(int i=0;i<n;i++)
//		printf("i:%d dis:%d pre:%d\n",i,dist[i],pre[i]);
//	printf("\n");
	print(dst);
	printf("%d %d",dist[dst],cost[dst]);
	return 0;
}
