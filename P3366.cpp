#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int num_edge;
const int maxn = 5e3+20;
const int maxm = 2e5+20;
struct Edge{
    int x;
    int y;
    int dis;
}edge[maxm];
int fa[maxn];
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
bool cmp(Edge a,Edge b)
{
    return a.dis < b.dis;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y,dis;
        scanf("%d%d%d",&x,&y,&dis);
        edge[i].dis = dis;
        edge[i].x = x;
        edge[i].y = y;
    }
    for(int i=1;i<=n;i++)
        fa[i] = i;
    sort(edge+1,edge+m+1,cmp);
    int ans = 0;
    int  k = 0;
    for(int i=1;i<=m;i++)
    {
        int x,y,dis;
        x = edge[i].x;
        y = edge[i].y;
        dis = edge[i].dis;
        if(find(x)!=find(y))
        {
            Union(x,y);
            ans += dis;
            k ++;
        }
        //if(k==(n-1)) break;
    }
    if(k==(n-1))
        printf("%d",ans);
    else printf("orz");
    return 0;
}