// 要让它的最小距离尽可能的大
// N个 candidate距离map的最短距离 N个dij，dij可以计算出所有点距离 
//源点的最小距离，从中选取一个最大的 
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,d_max;
const int maxn = 1e3+20;
const int maxx = 1e4+20;
const int INF = 0x3f3f3f3f;
int head[maxn];
struct Edge{
	int dis;
	int to;
	int next;
}edge[maxx];
int num_edge;
void add_edge(int from, int to, int dis)
{
	edge[++num_edge].next = head[from];
	edge[num_edge].to = to;
	edge[num_edge].dis = dis;
	head[from] = num_edge;
}
int visited[maxn];
int dist[maxn];
void dij()
{
	for(int j=1;j<=n+m;j++)
	{
		int u = -1;
		int min_dis = INF;
		for(int i=1;i<=n+m;i++)
		{
			if((dist[i]<min_dis)&&(!visited[i]))
			{
				min_dis = dist[i];
				u  = i;
			}
		}
		if(u == -1) break;
		visited[u] = 1;
		for(int i= head[u];i!=0;i=edge[i].next)
		{
			int v = edge[i].to;
			int dis = edge[i].dis;
			if(!visited[v]&&dist[v]>dist[u]+dis)
				dist[v] = dist[u] + dis;
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&d_max);
	for(int i=1;i<=k;i++)
	{
		int a,b,weight;
		char str1[3],str2[3],str3[3];
		scanf("%s%s%s",str1,str2,str3);
		if(str1[0]=='G')
			a = n + str1[1]-'0';
		else a = str1[0]-'0';
		if(str2[0]=='G')
			b = n + str2[1]-'0';
		else b = str2[0]-'0';	
		weight = str3[0]-'0';
			
		add_edge(a,b,weight);
		add_edge(b,a,weight);
		// printf("%s %s %s\n",str1,str2,str3);
	}
	float ans_min_dis = 0;
	int flag = 0;
	float ans_ave_dis = 0;
	int ans = 0;
	// printf("-----------------\n");
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n+m;j++)
		{
			dist[j] = INF;
			visited[j] = 0;
		}
		dist[n+i] =0;
		dij();//源点是n+i,i从1到m
		int min_dis = 0;
		sort(dist+1,dist+1+n);
		if(dist[1]>=ans_min_dis&&dist[n]<=k) // 最小和最大 
		{
			double sum = 0, ave = 0;
			for(int j=1;j<=n;j++)
				sum += dist[j];
			// printf("sum:%f\n",sum);
			ave = sum*1.0/n;
			// printf("ave:%f\n",ave);
			if(dist[1]==ans_min_dis&&ave<ans_ave_dis)
			{
				ans_ave_dis = ave; 
				ans = i; 
			}
			else if(dist[1]>ans_min_dis)//dist[1]>ans_min_dis
			{
				ans_min_dis = dist[1];
				ans_ave_dis = ave;
				ans = i;
			}
			flag = 1;
		}
	}
	if(flag)
	{
		printf("G%d\n",ans);
		printf("%.1lf %.1lf",ans_min_dis,ans_ave_dis);
	}
	else printf("No Solution");
	return 0;
} 
