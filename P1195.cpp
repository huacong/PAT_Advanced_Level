#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k;
const int maxm = 1e4+20;
const int maxn = 1e3+20;
int fa[maxn];
struct Edge{
    int x,y,dis;
}edge[maxm];
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x] = find(fa[x]);
}
void Union(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}
bool cmp(Edge e1,Edge e2)
{
    return e1.dis < e2.dis;
}
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
    int  t =n;
    int ans = 0;
    for(int i=1;i<=m;i++)
    {
        if(find(edge[i].x)!=find(edge[i].y))
        {
            ans += edge[i].dis;
            Union(edge[i].x,edge[i].y);
            t--;
        }
        if(t==k) break;
    }
    if(t!=k) printf("No Answer");
    else printf("%d",ans);
    return 0;
}