#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e3+20;
int lose[maxn];
int win[maxn];
int use[maxn];
int f[maxn];
int dp[maxn][maxn];
int n,x;
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&lose[i],&win[i],&use[i]);
    // for(int i=1;i<=n;i++)
    // {
    //     for(int u=x;u>=use[i];u--)
    //     {
    //         // for(int j=0;j<use[i];j++)
    //         //     f[u] = max(f[u-j]+lose[i],f[u]);
    //         f[u] += lose[i];
    //         f[u] = max(f[u-use[i]]+win[i],f[u]);
    //     }
    // }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            dp[i][j]=dp[i-1][j]+lose[i];
            if(j>=use[i])
            {
                dp[i][j]=max(dp[i-1][j-use[i]]+win[i],dp[i][j]);
            }
        }
    }
    printf("%lld",dp[n][x]*5);
    // int ans = 0;
    // for(int i=0;i<=x;i++)
    //     ans = max(ans,f[i]);
    // printf("%d",ans*5);
    return 0;
}

