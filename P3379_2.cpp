#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 5e5+20;
int fa[maxn][20];
int depth[maxn];
struct Edge{
    int to;
    int next;
}edge[maxn*2];
int head[maxn];
int num_edge;
void add_edge(int from, int to)
{
    edge[++num_edge].next = head[from];
    edge[num_edge].to = to;
    head[from] = num_edge;
}
int n,m,s;
void dfs(int u,int f)
{
    depth[u] = depth[f] + 1;
    fa[u][0] = f;
    for(int i=1;(1<<i)<=depth[u];i++)
        fa[u][i] = fa[fa[u][i-1]][i-1];
    for(int i=head[u];i!=0;i=edge[i].next)
    {
        if(edge[i].to!=f)
            dfs(edge[i].to, u);
    }
}
int lca(int s, int d)
{
    if(depth[s]<depth[d]) swap(s,d);
    for(int i=19;i>=0;i--)
    {
        if(depth[s]-(1<<i)>=depth[d])
            s = fa[s][i];
    }
    if(s==d) return s;
    for(int i=19;i>=0;i--)
    {
        if(fa[s][i]!=fa[d][i])
        {
            s = fa[s][i];
            d = fa[d][i];
        }
    }
    return fa[s][0];
}
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add_edge(a,b);add_edge(b,a);
    }
    dfs(s,0);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int ans = lca(a,b);
        printf("%d\n",ans);
    }
    return 0;
}
