#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
const int maxn = 505;
const int maxx = 3e5+20;
const int INF = 0x3f3f3f3f;
int vis[maxn];
int dist[maxn];
int head[maxn];
int num_edge;
struct Edge
{
    int to; int next; int dis;
};
Edge edge[maxx];
int rescue[maxn];
int hands[maxn];
int road[maxn];
int s,e;
void add_edge(int from,int to,int dis)
{
    edge[++num_edge].next = head[from];
    edge[num_edge].to = to;
    edge[num_edge].dis = dis;
    head[from] = num_edge;
}
void dij()
{
    for(int i=0;i<n;i++) dist[i] = INF;
    dist[s] = 0;
    hands[s] = rescue[s];
    road[s] = 1;
    for(int j=0;j<n;j++)
    {
        int min_value = INF;
        int k = -1;
        for(int u=0;u<n;u++)
        {
            if(!vis[u]&&dist[u]<min_value)
            {
                k = u;
                min_value = dist[u];
            }
        }
        if(k==-1) break;
        vis[k] = 1;
        for(int v=head[k];v!=0;v=edge[v].next)
        {
            int t = edge[v].to;
            int dis = edge[v].dis;
            if(!vis[t]) // never visited
            {
                if(dist[t]>(dist[k]+dis))
                {
                    dist[t] = dist[k] + dis;
                    road[t] = road[k];
                    hands[t] = hands[k] + rescue[t];
                }
                else if(dist[t]==(dist[k]+dis))
                {
                    road[t] += road[k];
                    if(hands[t] <(hands[k] + rescue[t]))
                        hands[t] = hands[k] + rescue[t];
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&e);
    for(int i=0;i<n;i++) scanf("%d",&rescue[i]);
    for(int i=0;i<m;i++)
    {
        int a,b,dis;
        scanf("%d%d%d",&a,&b,&dis);
        add_edge(a,b,dis);
        add_edge(b,a,dis);
    }
    dij();
    printf("%d %d",road[e],hands[e]);
    return 0;
}
