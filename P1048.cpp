#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e3+20;
int f[maxn];
int t[maxn];
int v[maxn];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&t[i],&v[i]);
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=t[i];j--)
        {
            f[j] = max(f[j-t[i]]+v[i],f[j]);
        }
    }
    int ans = 0;
    for(int i=0;i<=n;i++)
        ans = max(ans,f[i]);
    printf("%d",ans);
    return 0;
}