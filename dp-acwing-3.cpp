#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int f[maxn];
int n,v;
int vol[maxn];
int c[maxn];
int main()
{
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&vol[i],&c[i]);
    for(int i=1;i<=n;i++)
        for(int j=vol[i];j<=v;j++)
        {
            f[j] = max(f[j],f[j-vol[i]]+c[i]);
        }
            
    printf("%d",f[v]);
    return 0;
}
