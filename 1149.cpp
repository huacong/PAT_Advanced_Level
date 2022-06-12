#include<cstdio>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
const int maxn = 1e5+20;
vector<int>incom[maxn];
int vis[maxn];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int a,b; scanf("%d%d",&a,&b);
        incom[a].push_back(b);
    }
    for(int i=1;i<=m;i++)
    {
        int k; scanf("%d",&k);
        int G[1003];
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=k;j++)
        {
            scanf("%d",&G[j]);
            vis[G[j]] = 1;
        }
        int flag = 1;
        for(int j=1;j<=k;j++)
        {
            if(incom[G[j]].size()!=0)//有相克的
            {
                for(int u=0;u<incom[G[j]].size();u++)
                {
                    if(vis[incom[G[j]][u]])
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if(!flag) break;
        }
        if(flag) printf("Yes");
        else printf("No");
        if(i!=m) printf("\n");
    }
    return 0;
}