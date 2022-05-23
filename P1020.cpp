#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 1e5+20;
int dp[maxn];
int dp2[maxn];
int num[maxn];
int n;
int main()
{
    int tmp;
    while(cin>>tmp)
    {
    	num[++n] = tmp;
	}
    int ans = 0;
    int len = 0;
    int len2 = 0;
    dp[++len] = dp2[++len2] = num[1];
    for(int i=2;i<=n;i++)
    {
    	if(num[i]<=dp[len]) dp[++len] = num[i];
        else{
            int index = upper_bound(dp+1,dp+1+len,num[i], greater<int>())-dp;
            dp[index] = num[i];
        }
    	if(num[i]>dp2[len2]) dp2[++len2] = num[i];
    	else{
    		int index = lower_bound(dp2+1,dp2+1+len2,num[i])-dp2;
            dp2[index] = num[i];
		}
	}
    printf("%d\n%d",len,len2);
    return 0;
}
