#include<cstdio>
#include<algorithm>
using namespace std;
int n,v;
const int maxn = 1005;
int f[maxn];
int vol[maxn];
int c[maxn];
int g[maxn][maxn];
int main()
{
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&vol[i],&c[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=v;j>=vol[i];j--)
        {
            f[j] = max(f[j],f[j-vol[i]]+c[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=v;j>=0;j--)
        {
            if(j>=vol[i])
                g[i][j] = max(g[i-1][j-vol[i]]+c[i],g[i-1][j]);
            else g[i][j] = g[i-1][j];
        }
    }
    if(g[n][v]==f[v])
        printf("%d",f[v]);
    return 0;
}