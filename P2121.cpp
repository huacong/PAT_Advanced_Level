#include<cstdio>
#include<algorithm>
using namespace std;
// 每一个连通块找
const int maxn = 1e5+20;
const int maxm = 1e5+20;
int fa[maxn];
struct Edge{
    int x,y,dis;
}edge[maxm];
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x] = find(fa[x]);
}
void Union(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}
bool cmp(Edge x, Edge y)
{
    return x.dis > y.dis;
}
int n,m,k;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int x,y,dis;
        scanf("%d%d%d",&x,&y,&dis);
        edge[i].x = x;
        edge[i].y = y;
        edge[i].dis = dis;
    }
    sort(edge+1,edge+1+m,cmp);
    for(int i=1;i<=n;i++) fa[i] = i;
    int ans = 0;
    for(int i=1;i<=m;i++)
    {
        if(find(edge[i].x)!=find(edge[i].y))
        {
            Union(edge[i].x, edge[i].y);
            ans += edge[i].dis;
            k--;
        }
        if(k==0) break;
    }
    printf("%d",ans);
    return 0;
}