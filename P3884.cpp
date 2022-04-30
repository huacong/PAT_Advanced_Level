#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 105;
int n;
vector<int>num[maxn];
int depth[maxn];
int depth_vis[maxn];
int visited[maxn];
int fa[maxn][maxn];
int u,v;
int max_depth;
int max_width;
void dfs(int f, int father)
{
    depth[f] = depth[father]+1;
    fa[f][0] = father; // f向上2^0次方层
    for(int i=1;(1<<i)<=depth[f];i++)
        fa[f][i] = fa[fa[f][i-1]][i-1];
    for(int i=0;i<num[f].size();i++)
    {
        if(num[f][i]!=father) dfs(num[f][i],f);
    }
}
int lca(int x, int y)
{
    if(depth[x]<depth[y]) swap(x, y);
    while(depth[x]>depth[y])
        x = fa[x][depth[x]-depth[y]-1];
    if(x==y) return x;
    for(int k=depth[x];k>=0;k--)
    {
        if(fa[x][k]!=fa[y][k])
        {
            x = fa[x][k];
            y = fa[y][k];
        }
    }
    return fa[x][0];// 当前x向上 2^0次方
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        num[a].push_back(b);
    }
    scanf("%d%d",&u,&v);
    depth[1] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<num[i].size();j++)
        {
            depth[num[i][j]] = depth[i] + 1;
            max_depth = max(max_depth, depth[num[i][j]]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        depth_vis[depth[i]]++;
        max_width = max(max_width,depth_vis[depth[i]]);
    }
    printf("%d\n%d\n",max_depth,max_width);
    // 
    dfs(1,0);
    printf("%d",depth[u]*2+depth[v]-3*depth[lca(u,v)]);
    return 0;
}