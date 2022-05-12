#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1e4+20;
const int maxm = 2e4+20;
struct Edge{
    int x,y,dis;
}edge[maxm];
int n, m, s, t;
int fa[maxn];
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x] = find(fa[x]);
}
void Union(int x, int y)
{
    int fx = fa[x];
    int fy = fa[y];
    fa[fx] = fy;
}
bool cmp(Edge x, Edge y)
{
    return x.dis<y.dis;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int x, y, dis;
        scanf("%d%d%d",&x,&y,&dis);
        edge[i].x = x;
        edge[i].y = y;
        edge[i].dis = dis;
    }
    sort(edge+1,edge+1+m,cmp);
    for(int i=1;i<=n;i++) fa[i] = i;
    int k = 0;
    int ans = 0;
    for(int i=1;i<=m;i++)
    {
        if(find(edge[i].x)!=find(edge[i].y))
        {
            ans = edge[i].dis;
            Union(edge[i].x,edge[i].y);
        }
        if(find(s)==find(t)) break;
    }
    printf("%d",ans);
    return 0;
}