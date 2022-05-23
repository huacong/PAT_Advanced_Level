#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e5+20;
int num1[maxn];
int dp[maxn];
int n;
int ans = 0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&num1[i]);
    for(int i=1;i<=n;i++) dp[i]=1;
    // for(int i=2;i<=n;i++)
    // {
    //     for(int j=1;j<i;j++)
    //     {
    //         if(num1[i]>=num1[j]) dp[i] = max(dp[i],dp[j]+1);
    //     }
    //     ans = max(ans, dp[i]);
    // }
    // printf("%d",ans);
    int len = 0;
    for(int i=1;i<=n;i++)
    {
        if(i==1) dp[++len] = num1[i];
        else{
            if(num1[i]>=dp[len]) dp[++len] = num1[i];
            else{
                int index = upper_bound(dp+1,dp+1+len,num1[i])-dp;
                dp[index] = num1[i];
            }
        }
    }
    printf("%d",len);
}
/*
8
1 2 3 -9 3 9 0 11
6
*/