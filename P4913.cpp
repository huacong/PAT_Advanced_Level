#include<cstdio>
struct node{
	int left,right;
}tree[1000060];
int ans=0;
void dfs(int id,int depth)
{
	if(id==0) return;
	if(depth>ans) ans=depth;
	dfs(tree[id].left,depth+1);//这和遍历差不多！！！ 
	dfs(tree[id].right,depth+1);
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d%d",&tree[i].left,&tree[i].right);
	dfs(1,1);//从节点1然后层数1
	printf("%d",ans); 
	return 0; 
}