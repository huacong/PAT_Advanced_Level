#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k;
const int maxn = 1e3+20;
const int maxx = 1e4+20;
int head[maxn];
int num_edge;
struct Edge
{
    int to; int next;
}edge[maxx];
void add_edge(int from,int to)
{
    edge[++num_edge].next = head[from];
    edge[num_edge].to = to;
    head[from] = num_edge;
}
int num[maxn];
int vis[maxn];
int index = 1;
bool dfs(int s,int index)
{
    vis[s] = 1;
    //printf("%d : %d\n",s,index);
    if(head[s]==0) return true;
    bool flag = true;
    
    for(int u=head[s];u!=0;u=edge[u].next)
    {
        if(!vis[edge[u].to])
        {
            flag = false;
            if (num[index+1]==edge[u].to)
            {
                //printf("*%d : %d*\n",num[index+1],edge[u].to);
                return dfs(edge[u].to,index+1);
            }
        }
    }
    return flag;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        add_edge(a,b);
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
            scanf("%d",&num[j]);
        for(int j=1;j<=n;j++) vis[j]=0;
        bool flag = true;
        for(int u=1;u<=n;u++)
        {
            if(!vis[num[u]])
            {
                flag = dfs(num[u],u);
                if(!flag) break;
            }
        }
        if(flag) 
        {
            int print_flag = true;
            for(int u=1;u<=n;u++)
            {
                if(!vis[u]) 
                {
                    printf("no\n");
                    print_flag = false;
                    break;
                }
            }   
            if(print_flag) printf("yes\n");
        }
        else printf("no\n");
    }
}