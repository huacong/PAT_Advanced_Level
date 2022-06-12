#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e5+20;
int num[maxn];
int vis[maxn];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        if(num[i]>0&&num[i]<=maxn)
            vis[num[i]] = 1;
    }
    for(int i=1;i<=maxn;i++)
    {
        if(!vis[i])
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}