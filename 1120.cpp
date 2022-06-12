#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1e4+20;
int n;
int num[maxn];
int vis[37];
int cnt = 0;
int ans[37];
int fn(int x)
{
    int ans = 0;
    while(x>0)
    {
        ans+= x%10;
        x = x/10;
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for(int i=1;i<=n;i++)
        vis[fn(num[i])] = 1;
    for(int i=1;i<=36;i++)
        if(vis[i]) ans[++cnt] = i;
    printf("%d\n",cnt);
    for(int i=1;i<cnt;i++)
        printf("%d ",ans[i]);
    printf("%d",ans[cnt]);
    return 0;
}