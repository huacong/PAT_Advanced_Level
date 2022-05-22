#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 25;
int map[maxn][maxn];//x,y
long long dp[maxn][maxn];
int step_x[9]={0,-1,-2,-2,-1,1,2,2,1};
int step_y[9]={0,-2,-1,1,2,2,1,-1,-2};
int n,m;
int h_n,h_m;
int main()
{
    scanf("%d%d%d%d",&n,&m,&h_n,&h_m);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            map[i][j] = 1;
    for(int i=0;i<=8;i++)
    {
        int x = h_n+step_x[i];
        int y = h_m+step_y[i];
        if(x>=0&&x<=n&&y>=0&&y<=m) 
        {
            map[x][y] = 0;
        }
    }
    for(int i=0;i<=m;i++) 
    {
        if(map[0][i]) dp[0][i]=1;
        else break;
    }
    for(int j=0;j<=n;j++) 
    {
        if(map[j][0]) dp[j][0]=1;
        else break;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(map[i][j]) dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }        
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //         printf("%d ",dp[i][j]);
    //     printf("\n");
    // }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //         printf("%d ",map[i][j]);
    //     printf("\n");
    // }
        
    printf("%lld",dp[n][m]);
    return 0;
}