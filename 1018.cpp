#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
//最短路径 //边权最小，点权最小
const int maxn = 505;
const int INF = 0x3f3f3f3f;
int cap[maxn];
struct Edge{
	int v,dis;
};
vector<Edge>G[maxn];
vector<int>pre[maxn];
vector<int>temp_path;
vector<int>path;
int dist[maxn];
int vis[maxn];
int maxcap;
int n,m;
int s,e;
int minNeed=  INF;
int minRemain = INF;
void Dijkstra(int s)
{
	fill(dist,end(dist),INF);
	fill(vis,end(vis),false);
	dist[s] = 0;
	for(int i=0;i<=n;i++)
	{
		int u=-1;
		int min = INF;
		for(int j=0;j<=n;j++)
		{
			if(!vis[j]&&dist[j]<min)
			{
				u = j;
				min = dist[j];
			}
		}
		if(u==-1) break;
		vis[u] = true;
		for(int i=0;i<G[u].size();i++)
		{
			Edge edge = G[u][i];
			int v = edge.v;
			int dis = edge.dis;
			if(!vis[v]) 
			{
				if(dist[u]+dis<dist[v])
				{
					dist[v] = dist[u]+dis;
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(dist[u]+dis==dist[v])
					pre[v].push_back(u);//相等的话,看一下设谁的点权值大？ 
			}
		}
	}
}
void Dfs(int u)
{
	//printf("*%d\n",u);
	if(u==s)
	{
		temp_path.push_back(u);
		int need=0, remain=0;
		for(int i=temp_path.size()-1;i>=0;i--)
		{
			int id = temp_path[i];
			if(cap[id]>0)
			{
				remain += cap[id];
			}
			else if(cap[id]<0)
			{
				if(remain<(-cap[id]))
				{
					need+=(-cap[id] -remain);
					remain = 0;
				}
				else remain -= (-cap[id]);
			}
		}
		if(need<minNeed)
		{
			minNeed = need;
			minRemain = remain;
			path = temp_path;
		}
		else if(need==minNeed && remain<minRemain)
		{
			minNeed = need;
			minRemain = remain;
			path = temp_path;
		}
		temp_path.pop_back();
	}
	temp_path.push_back(u);
	for(int i=0;i<pre[u].size();i++)
	{
		Dfs(pre[u][i]);
	}
	temp_path.pop_back();
}
int main()
{
	scanf("%d%d%d%d",&maxcap,&n,&e,&m);//problem station就是终点
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&cap[i]);
		cap[i] -= maxcap/2;
	}
	for(int i=1;i<=m;i++)
	{
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d); 
		G[a].push_back({b,d});
		G[b].push_back({a,d});
	}
	Dijkstra(s);
//	printf("-----------------\n");
//	for(int i=1;i<=3;i++)
//	{
//		printf("%d \n",dist[i]);
//		for(int j = pre[i].size()-1;j>=0;j--)
//			printf("%d ",pre[i][j]);
//		printf("\n");
//	}
	
	Dfs(e);
	printf("%d ",minNeed);
	for(int i=path.size()-1;i>=0;i--)
	{
		if(i!=0) printf("%d->",path[i]);
		else printf("%d ",path[i]);
	}
	printf("%d",minRemain);
	return 0;
	 
	 
} 
