#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int m,n;
const int maxn = 1e4+20;
int num[maxn];
map<int,int>pos;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct Edge{
    int to;
    int next;
};
struct node* root = NULL;
Edge edge[maxn];
int head[maxn];
int num_edge;
void add_edge(int from,int to)
{
    edge[++num_edge].next = head[from];
    edge[num_edge].to = to;
    head[from] = num_edge;
}
node* insert(node* root,int data)
{
    if(root==NULL)
    {
        root = new node();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        if(data<root->data)
        {
            if(root->left==NULL) add_edge(pos[root->data],pos[data]);
            root->left = insert(root->left,data);
        }
        else 
        {
            if(root->right==NULL) add_edge(pos[root->data],pos[data]);
            root->right = insert(root->right,data);
        }
    }
    return root;
}
int fa[maxn][20];
int depth[maxn];
int lg[maxn];
void dfs(int f, int fath)
{
    depth[f] = depth[fath] + 1;
    fa[f][0] = fath;
    for(int i=1;(1<<i)<=depth[f];i++)
        fa[f][i] = fa[fa[f][i-1]][i-1];
    for(int i=head[f];i!=0;i=edge[i].next)
        dfs(edge[i].to,f);
}
int lca(int x,int y)
{
    if(depth[x]<depth[y]) swap(x,y);
    // for(int i=19;i>=0;i--)
    // {
    //     if(depth[x]-(1<<i)>=depth[y])
    //         x = fa[x][i];
    // }//保证跳到同一深度
    // if(x==y) return x;
    // for(int i=19;i>=0;i--)
    // {
    //     if(fa[x][i]!=fa[y][i])
    //     {
    //         x = fa[x][i];
    //         y = fa[y][i];
    //     }
    // }
    // return fa[x][0];
    while(depth[x]>depth[y]){
        x=fa[x][lg[depth[x]-depth[y]]-1];//一直跳直到深度相同
    }
    if(x==y)return x;
    for(int k=lg[depth[x]]-1;k>=0;--k){
        if(fa[x][k]!=fa[y][k])//向上跳从大->小，第一个不相等的点就是公共祖先的儿子
            x=fa[x][k],y=fa[y][k];
    }
    return fa[x][0];
}

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        pos[num[i]] = i;
        root = insert(root,num[i]);
    }
    //output module
    // for(int i=1;i<=n;i++)
    // {
    //     printf("%d:",i);
    //     for(int u=head[i];u!=0;u=edge[u].next)
    //     {
    //         printf("%d ",edge[u].to);
    //     }
    //     printf("\n");
    // }
    for(int i=1;i<maxn;++i){
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    }
    dfs(pos[root->data],0);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(pos[a]==0&&pos[b]==0) 
            printf("ERROR: %d and %d are not found.\n",a,b);
        else if(pos[a]==0)
            printf("ERROR: %d is not found.\n",a);
        else if(pos[b]==0)
            printf("ERROR: %d is not found.\n",b);
        else{
            int res_index = lca(pos[a],pos[b]);
            int res = num[res_index];
            if(res==a)
                printf("%d is an ancestor of %d.\n",a,b);
            else if(res==b)
                printf("%d is an ancestor of %d.\n",b,a);
            else    printf("LCA of %d and %d is %d.\n",a,b,res);
        }
    }
    return 0;
}