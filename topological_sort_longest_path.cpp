#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1520;
const int maxx = 5e4+20;
int stack[maxn];
int weight[maxn];
int din[maxn];
int tot;
int num;
struct Edge{
	int next;
	int to;
	int dis;
}edge[maxx];

int head[maxn];
int num_edge;
void add(int from,int to, int dis)
{
	edge[++num_edge].next = head[from];
	edge[num_edge].to = to;
	edge[num_edge].dis = dis;
	head[from] = num_edge;
}
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b,d;scanf("%d%d%d",&a,&b,&d);
		add(a,b,d);
		din[b]++;
	}
	for(int i=1;i<=n;i++)
	{
//		if(din[i]==0)
//			stack[++tot] = i;
		weight[i] = -INF;
	}
	stack[++tot] =1;
	weight[1]=0;
	while(tot>0)
	{
		int u = stack[tot];
		tot--;num++;
		for(int i=head[u];i!=0;i=edge[i].next)
		{
			int v = edge[i].to;
			int dis = edge[i].dis;
			// way-1
//			if(weight[v]<(weight[u]+dis))
//			{
//				weight[v] = weight[u]+dis;
//				stack[++tot] = v; 
//			}
			// way-2
			//if(weight[v]<(weight[u]+dis))
			weight[v] = max(weight[v],weight[u]+dis);
			din[v]--;
			if(din[v]==0)
				stack[++tot] = v; 
		}
	}
	if(weight[n]<0) printf("-1");
	else printf("%d",weight[n]);
	return 0;
}
