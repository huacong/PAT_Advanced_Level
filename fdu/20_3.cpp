#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100;
const int INF = 0x3f3f3f3f;
//初始给出任意两个节点之间的距离
int dis[maxn][maxn];
int vis[maxn];// 0 white 1 black
int n,m;
int father[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j) dis[i][j] = INF;
        }
    }    
    for(int i=1;i<=(n-1);i++) scanf("%d",&father[i]);
    for(int i=1;i<=(n-1);i++)
    {
        int a; scanf("%d",&a);
        dis[i][father[i]] = a;
        dis[father[i]][i] = a;
    }
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<n;j++)
            {
                if((i!=k)&(k!=j)&(i!=j)&(dis[i][j]>dis[i][k]+dis[k][j]))
                    dis[i][j] = dis[i][k]+dis[k][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",dis[i][j]);
        printf("\n");
    }
    for(int i=1;i<=m;i++)
    {
        int t,c; scanf("%d%d",&t,&c);
        int ans = 0;
        if(t==1) vis[c] = 1;
        else if(t==2){
            for(int j=0;j<n;j++)
            {
                if(vis[j])
                    ans+=dis[c][j];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}