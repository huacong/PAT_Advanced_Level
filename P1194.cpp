#include<cstdio>
#include<algorithm>
using namespace std;
const int maxm = 25e4+20;
const int maxn = 520;
struct Edge{
    int x,y,dis;
}edge[maxm];
int num_edge = 0;
int fa[maxn];
int a,n;
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
bool cmp(Edge q1, Edge q2)
{
    return q1.dis<q2.dis;
}
int main()
{
    scanf("%d%d",&a,&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int dis; scanf("%d",&dis);
            if(dis<a&&dis>0) // 第一个坑！！
            {
                edge[++num_edge].x = i;
                edge[num_edge].y = j;
                edge[num_edge].dis = dis;
            }
        }
    }
    for(int i=1;i<=n;i++) fa[i] = i;
    sort(edge+1,edge+num_edge+1,cmp);
    int ans = 0;
    int k = 0;
    for(int i=1;i<=num_edge;i++)
    {
        if(find(edge[i].x)!=find(edge[i].y))
        {
            ans += edge[i].dis;
            Union(edge[i].x, edge[i].y);
            k++;
        }
        if(k==n-1) break;
    }
    ans += (n-k)*a; ///第二个坑
    printf("%d",ans);
    return 0;
}

/*
3 3
0 4 4
4 0 4
4 4 0

9

3 4
0 1 0 0
1 0 0 0
0 0 0 0
0 0 0 0

10
*/