#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn = 2e3+20;
char str1[maxn];
char str2[maxn];
int dp[maxn][maxn];
int len1;
int len2;
int main()
{
    scanf("%s",str1+1); len1 = strlen(str1+1);
    scanf("%s",str2+1); len2 = strlen(str2+1);
    //printf("%d %d\n",len1,len2);
    for(int i=0;i<=len2;i++) dp[0][i] = i; 
    for(int j=0;j<=len1;j++) dp[j][0] = j;
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1);
            if(str1[i] == str2[j]){
                //printf("%d %d\n",i,j);
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
            }
            else{
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]+1) ;
            }
        }
    }
    // for(int i=0;i<=len1;i++)
    // {
    //     for(int j=0;j<=len2;j++)
    //     {
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d",dp[len1][len2]);
}
