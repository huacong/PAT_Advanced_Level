#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e5+20;
int num1[maxn];
int num2[maxn];
int c[maxn];
int b[maxn];
int dp[maxn];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp); c[tmp] = i;

    }
    for(int i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp); b[i] = c[tmp];
    }
    int len = 0;
    for(int i=1;i<=n;i++)
    {
        if(i==1) dp[++len] = b[i];
        else{
            if(b[i]>=dp[len]) dp[++len] = b[i];
            else{
                int index = upper_bound(dp+1,dp+1+len,b[i])-dp;
                dp[index] =  b[i];
            }
        }
    }
    printf("%d",len);
    return 0;
}