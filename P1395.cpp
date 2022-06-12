#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 5e4+20;
struct Edge{
    int to;
    int next;
}edge[maxn<<1];
int head[maxn];
int num_edge;
const int INF = 0x3f3f3f3f;
void add_edge(int from, int to)
{
    edge[++num_edge].next = head[from];
    edge[num_edge].to = to;
    head[from] = num_edge;
}
int n,d[maxn],ct[maxn],fa[maxn];
//ct[x]以x为根的树的节点总数
void dfs(int x, int st)
{
    for(int i=head[x];i!=0;i=edge[i].next)
    {
        if(edge[i].to!=fa[x])
        {
            ++ct[x]; 
            fa[edge[i].to] = x;
            dfs(edge[i].to, st+1);
            ct[x] += ct[edge[i].to];
        }
    }
    d[1]+=st;//所有点到1的距离之和
}
void fd(int x)//进行树状 DP!
{
    for(int i=head[x];i!=0;i=edge[i].next)
    {
        if(edge[i].to!=fa[x])
        {
            d[edge[i].to] = d[x] - ct[edge[i].to] - 1 + (n-ct[edge[i].to]-1);
            // d[child] = d[father] - child'node + other nodes;
            fd(edge[i].to);
        }
    }
    return ;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        add_edge(a,b); add_edge(b,a);
    }
    dfs(1,0);
    // for(int i=1;i<=n;i++)
    //     printf("%d ",ct[i]);
    fd(1);//从1开始，推得各点的D值
    int min_dis = d[1];
    int min_num = 1;
    for(int i=2;i<=n;i++)
    {
        if(d[i]<min_dis)
        {
            min_dis = d[i];
            min_num = i;
        }
    }
    printf("%d %d",min_num,min_dis);
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