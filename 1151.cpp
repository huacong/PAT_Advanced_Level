#include<cstdio>
#include<algorithm>
#include<stdlib.h>
using namespace std;
const int maxn = 1e4+20;
int preorder[maxn];
int inorder[maxn];
int postorder[maxn];
int m,n;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
int preIndex = 0;
struct Edge{
    int from;
    int to;
    int next;
}edge[maxn];
int head[maxn];
int depth[maxn];
int edge_num = 0;
int fa[maxn][20];
int lg[maxn];
void add_edge(int from, int to)
{
    edge[++edge_num].next = head[from];
    edge[edge_num].to = to;
    head[from] = edge_num;
}
node* newNode(int data)
{
    node* tmp_node = new node();
    tmp_node->data = data;
    tmp_node->left = NULL;
    tmp_node->right = NULL;
    return tmp_node;

}
node* buildTree(int instart, int inend)
{
    if(instart>inend) return NULL;
    node* tNode = newNode(preorder[preIndex++]);
    if(instart == inend) return tNode;
    int inIndex;
    for(int i=instart;i<=inend;i++)
    {
        if(inorder[i]==(tNode->data))
        {
            inIndex = i;
            break;
        }
    }
    tNode->left = buildTree(instart,inIndex-1);
    if(tNode->left!=NULL) add_edge(tNode->data,tNode->left->data);
    tNode->right = buildTree(inIndex+1, inend);
    if(tNode->right!=NULL) add_edge(tNode->data,tNode->right->data);
    return tNode;
}
void dfs(int f, int fath)
{
    depth[f] = depth[fath] + 1;
    fa[f][0] = fath;
    for(int i=1;(1<<i)<=depth[f];i++)
        fa[f][i] = fa[fa[f][i-1]][i-1];
    for(int i=head[f];i;i=edge[i].next)
        dfs(edge[i].to, f);
}
int lca(int x,int y)
{
    if(depth[x]<depth[y]) swap(x,y);
    // for(int i=19;i>=0;i--)
    // {
    //     if(depth[x]-(1<<i)>=depth[y])
    //         x = fa[x][i];
    // }
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
    for(int i=0;i<n;i++) scanf("%d",&inorder[i]);
    for(int i=0;i<n;i++) scanf("%d",&preorder[i]);
    struct node* root = buildTree(0,n-1);
    //printf("num:%d",edge_num);
    for(int i=1;i<maxn;++i){
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    }
    dfs(preorder[0],0);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if((a>n||a<=0)&&(b>n||b<=0))
            printf("ERROR: %d and %d are not found.\n",a,b);
        else if(a>n||a<=0)
            printf("ERROR: %d is not found.\n",a);
        else if(b>n||b<=0)
            printf("ERROR: %d is not found.\n",b);
        else{
            int res = lca(a,b);
            if(res==a)
                printf("%d is an ancestor of %d.\n",a,b);
            else if(res==b)
                printf("%d is an ancestor of %d.\n",b,a);
            else    printf("LCA of %d and %d is %d.\n",a,b,res);
        }
    }
}

/*
6 8
7 2 3 4 6 5 1 9
5 3 7 2 6 4 9 1
2 6
8 1
7 9
12 -3
0 8
99 99

*/