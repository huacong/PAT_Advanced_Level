#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100;
const int maxx = 1e4+20;
int head[maxn];
int in[maxn];
int stack[maxn];
struct Edge{
    int to;
    int next;
}edge[maxx];
int num_edge;
void add_edge(int from,int to)
{
    edge[++num_edge].next = head[from];
    edge[num_edge].to = to;
    head[from] = num_edge;
}
int n;
int top;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int from;int to;
        scanf("%d%d",&from,&to);
        add_edge(from,to);
        in[to]++;
    }
    for(int i=0;i<n;i++)
    {
        if(in[i]==0) stack[++top] = i;
    }
    while(top>0)
    {
        int u = stack[top];
        top--;
        printf("%d ",u);
        for(int i=head[u];i!=0;i=edge[i].next)
        {
            int v = edge[i].to;
            in[v]--;
            if(in[v]==0) stack[++top] = v;
        }
    }
    return 0;
}

// 