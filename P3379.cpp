#include<bits/stdc++.h>
using namespace std;
const int N =5e5+5;
struct node{
	int t,nex;
}edge[N<<1];int head[N];int tot;//这些是辅助完成邻接表存储的
int depth[N];//跳跃的深度很重要
int fa[N][23];//一个人最多可能有23个父亲
int lg[N];
void add(int x,int y)
{
	edge[++tot].t=y;
	edge[tot].nex=head[x];
	head[x]=tot;
 } 
void dfs(int f,int fath)
{
	depth[f]=depth[fath]+1;
	fa[f][0]=fath;//f上面的2^0层的祖先 
	for(int i=1;(1<<i)<=depth[f];i++)
		fa[f][i]=fa[fa[f][i-1]][i-1];
		///f的上k层祖先即为f的上k/2 层祖先的第 k/2 个祖先
	for(int i=head[f];i;i=edge[i].nex) 
		if(edge[i].t!=fath)
			dfs(edge[i].t,f);
}
//下面的lca部分
//我们先把两个点提到同一高度，在统一开始跳。我们要跳到它们LCA
//的下面一层，然后输出它们的父节点这样就不会误判。
int lca(int x,int y)
{//
	if(depth[x]<depth[y]) swap(x,y);//保证一定次序 
	while(depth[x]>depth[y])
		x=fa[x][lg[depth[x]-depth[y]]-1];
	if(x==y) return x;//其中一个是根的情况
	for(int k=lg[depth[x]-1];k>=0;k--)//能跳的最大高度
		if(fa[x][k]!=fa[y][k])//两个人父亲相同就不要动了，在减一点试试看
			x=fa[x][k],y=fa[y][k];//往上数k 
	return fa[x][0]; 
}
int n,m,s;//n为树的结点个数、m表示询问的个数、s是树根 
int x,y;//临时变量储存 
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);//加边！ 
	 } 
	for(int i=1;i<=n;i++)
	 	lg[i]=lg[i-1]+(1<<lg[i-1]==i);//o（1）求对数
	dfs(s,0);//预处理 树根的父亲当然是0 
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0; 
} 