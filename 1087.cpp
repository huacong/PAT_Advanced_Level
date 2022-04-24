#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
map<string,int>str2int;
map<int,string>int2str;
const int maxn  = 205;
const int INF = 0x3f3f3f3f;
int num = 0;
int city2int(string city)
{
	if(str2int[city]==0)
	{
		str2int[city] = ++num;
		int2str[num]  = city;
		return num;
	}
	return str2int[city];
}
int n,k,s;
int happ[maxn];
int head[maxn];
struct Edge{
	int to;
	int dis;
	int next;
}edge[maxn*maxn];
int num_edge;
void add_edge(int from, int to, int dis)
{
	edge[++num_edge].next = head[from];
	edge[num_edge].to = to;
	edge[num_edge].dis = dis;
	head[from] = num_edge;
}
vector<int>pre[maxn];
vector<int>temp_path;
vector<int> path;
// 因为你要看的是 average happiness，这个值无法贪心求得，因此必须将其保存以后再来看 
int visited[maxn];
int dist[maxn];
void dij()
{
	for(int i=1;i<=n;i++)
		dist[i]  = INF;
	dist[s] = 0;
	for(int i=1;i<=n;i++)
	{
		int u = -1;
		int min_dis = INF;
		for(int j=1;j<=n;j++)
		{
			if(!visited[j]&&dist[j]<min_dis)
			{
				u = j;
				min_dis = dist[j];
			}
		}
		if(u==-1) return ;
		visited[u] = 1;
		for(int j=head[u];j!=0;j=edge[j].next)
		{
			int v = edge[j].to;
			int dis = edge[j].dis;
			if(!visited[v]&&dist[v]>=dist[u]+dis)
			{
				if((dist[v]==dist[u]+dis))
				{
					pre[v].push_back(u);
				}
				else if(dist[v]>dist[u]+dis)
				{
					dist[v] = dist[u]+dis;
					pre[v].clear();
					pre[v].push_back(u);
				}
				
			}
		}
	}
} 
int ans_path;
int ans_sum = 0;
int ans_ave;
int cnt_path(int u)
{
	if(u==s) 
	{
		ans_path++;
		temp_path.push_back(u);
		int temp_sum = 0;
		int temp_ave = 0;
		for(int i=temp_path.size()-1;i>=0;i--)
			temp_sum+=happ[temp_path[i]];
		temp_ave = temp_sum/(temp_path.size()-1);
		if(temp_sum>ans_sum) 
		{
			ans_sum = temp_sum;
			ans_ave = temp_ave;
			path = temp_path;
		}
		else if(temp_sum==ans_sum&&temp_ave>ans_ave)
		{
			ans_ave = temp_ave;
			path = temp_path;
		}
		temp_path.pop_back();
	}
	temp_path.push_back(u);
	for(int i=0;i<pre[u].size();i++)
	{
		cnt_path(pre[u][i]);
	}
	temp_path.pop_back();
}
int main()
{
	string str;
	cin>> n >> k >> str;
	s = city2int(str);
	for(int i=1;i<n;i++)
	{
		string city; int happiness;
		cin>>city>>happiness;
		happ[city2int(city)] = happiness;
	}
	for(int i=1;i<=k;i++)
	{
		string city1,city2;int cost;
		cin>>city1>>city2>>cost;
		add_edge(city2int(city1),city2int(city2),cost);
		add_edge(city2int(city2),city2int(city1),cost);
	}
	dij();
	int e = city2int("ROM");
	cnt_path(e);
	printf("%d %d %d %d\n",ans_path,dist[e],ans_sum,ans_ave);
	for(int i=path.size()-1;i>=0;i--)
	{
		if(i!=0)
			cout<<int2str[path[i]]<<"->";
		else cout<<int2str[path[i]];
	}
	return 0;
}
