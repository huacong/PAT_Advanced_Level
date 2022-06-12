#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e4+5;
struct Edge{
    int to; int next;
}edge[maxn];
int num_edge;
int head[maxn];
void add_edge(int from, int to)
{
    edge[++num_edge].next = head[from];
    edge[num_edge].to = to;
    head[from] = num_edge;
}
int n;int maxdis;int maxv;
void dfs(int u,int f,int d)
{
    if(maxdis < d)
    {
        maxdis = d;
        maxv = u;
    }
    for(int e=head[u];e!=0;e=edge[e].next)
    {
        int v = edge[e].to;
        if(v==f) continue;
        dfs(v,u,d+1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add_edge(a,b); add_edge(b,a);
    }
    dfs(1,0,0);
    maxdis = 0;
    dfs(maxv,0,0);
    printf("%d",maxdis);
    return 0;
}





/*
8
1 4
1 3
1 5
4 2
4 6
6 7
7 8

*/