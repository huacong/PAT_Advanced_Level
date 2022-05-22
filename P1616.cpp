#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e7+20;
const int maxm = 1e4+20;
long long  f[maxn];
int t[maxm];
int v[maxm];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&t[i],&v[i]);
    for(int i=1;i<=m;i++)
        for(int j=t[i];j<=n;j++)
            f[j] = max(f[j-t[i]]+v[i],f[j]);
    long long ans = 0;
    for(int i=0;i<=n;i++)
        ans = max(ans,f[i]);
    printf("%lld",ans);
    return 0;
}