#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e4+20;
struct Edge{
    int to;
    int dis;
    int next;
}edge[maxn<<1];
int head[maxn];
int dis[maxn];
int num_edge;
void add_edge(int from, int to, int dis)
{
    edge[++num_edge].next = head[from];
    edge[num_edge].to = to;
    edge[num_edge].dis = dis;
    head[from] = num_edge;
}
int maxv,maxdis;
int s;
void dfs(int u, int f, int dist)
{
    if(maxdis<dist)
    {
        maxdis = dist;
        maxv = u;
    }
    for(int e=head[u];e!=0;e=edge[e].next)
    {
        if(edge[e].to!=f)
            dfs(edge[e].to,u,dist+edge[e].dis);
    }
}
int d1[maxn];int d2[maxn];
void dfs_(int u,int f,int depth, int* d)
{
    d[u] = depth;
    if(d[maxv]<depth)
    {
        maxv = u;
    }
    for(int e=head[u];e!=0;e=edge[e].next)
    {
        if(edge[e].to!=f)
        {
            dfs_(edge[e].to,u,depth+edge[e].dis,d);
        }
    }
}
int main()
{
    int n;scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int v,w;scanf("%d%d",&v,&w);
        add_edge(i,v,w);
        add_edge(v,i,w);
    }
    dfs(1,0,0);
    s = maxv; maxdis = 0;
    dfs_(s,0,0,d1);
    s = maxv;
    dfs_(s,0,0,d2);
    for(int i=1;i<=n;i++)
        printf("%d\n",max(d1[i],d2[i]));
    return 0;
}
// u:4
// v:4
// 2 0 0 3 0
// 2 0 0 3 0