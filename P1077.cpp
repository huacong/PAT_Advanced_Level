#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 105;
int num[maxn];
int dp[maxn][maxn];
const int mod = 1000007;
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    //for(int i=1;i<=n;i++) dp[i][i] = 1;
    // for(int i=1;i<=num[1];i++) dp[1][i] = 1;
    // for(int i=1;i<=m;i++) dp[i][1] = i;
    dp[0][0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=max(0,j-num[i]);k<=j;k++)
            {
                //printf("%d %d %d %d %d\n",i,j,i-1,k,dp[i-1][k]);
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
            }
            //printf("%d %d %d\n",i,j,dp[i][j]);
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++) 
    //     {
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d",dp[n][m]);
    return 0;
}