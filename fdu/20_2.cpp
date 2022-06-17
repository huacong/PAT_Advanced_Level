#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 100;
int num[maxn][maxn];
int n,m; // n*m
int dp[maxn][maxn];
int ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&num[i][j]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(num[i][j]==0) dp[i][j] = 0;
            else{
                if(i==0||j==0) dp[i][j] = 1;
                else{
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                    ans = max(dp[i][j], ans);
                }
            }
        }
    }
    printf("answer:%d",ans);
    return 0;
}