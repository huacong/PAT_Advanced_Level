#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 1e4+20;
int n;
vector<int>map[maxn];
int visited[maxn];
int ans[maxn];
int dfs(int u)
{
	visited[u] = 1;
	int ans = 0;
	// for(int i=1;i<=n;i++)
	//for(int i:map[u])
	for(int i=0;i<map[u].size();i++)
	{
		int v = map[u][i];
		if(visited[v]==0)//&&map[u][i]==1)
			ans = max(ans,1+dfs(v)) ;
	}
	return ans;
}
bool cmp(int x,int y)
{
	return x>y;
}
int check()
{
	int cnt =0;
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			dfs(i);
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=(n-1);i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		//map[a][b] = 1;
		map[a].push_back(b);
		//map[b][a] = 1;
		map[b].push_back(a);
	}
	int istree = check();
	int max_ans = 0;
	if(istree==1) // ÊÇÊ÷ 
	{
		for(int i=1;i<=n;i++)
		{
			memset(visited,0,sizeof(visited));
			int cnt = dfs(i);
			ans[i] = cnt; 
			if (cnt>max_ans) max_ans = cnt;
		}
		for(int i=1;i<=n;i++)
		{
			if(ans[i]==max_ans) printf("%d\n",i);
		}
	}
	else
	{
		printf("Error: %d components",istree);
	}
	return 0;
}
