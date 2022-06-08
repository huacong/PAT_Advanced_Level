#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
int num_edge;
const int maxx = 1e4+20;
const int maxn = 1e3+20;
struct Edge{
    int to;int next;  
};
Edge edge[maxx];
int head[maxn];
int din[maxn];
int tin[maxn];
int num[maxn];
vector<int>ans;
void add_edge(int from,int to)
{
    edge[++num_edge].next = head[from];
    edge[num_edge].to = to;
    head[from] = num_edge;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b; 
        scanf("%d%d",&a,&b);
        add_edge(a,b);
        din[b]++;
    }
    int k; scanf("%d",&k);
    //printf("*********%d*********\n",k);
    for(int index=0;index<k;index++)
    {
        for(int i=1;i<=n;i++) tin[i]=din[i];
        bool flag = true;
        for(int i=1;i<=n;i++) scanf("%d",&num[i]);
        for(int i=1;i<=n;i++)
        {
            int a; a = num[i];
            if(tin[a]==0)
            {
                for(int u=head[a];u!=0;u=edge[u].next)
                    tin[edge[u].to]--;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if(!flag) ans.push_back(index);
    }
    printf("%d",ans[0]);
    for(int i=1;i<ans.size();i++)
        printf(" %d",ans[i]);
    return 0;
}