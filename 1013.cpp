//Ҫʼ�ձ���ʣ�µĳ���Ϊ��ͨ״̬ 
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int visited[maxn];
int map[maxn][maxn];
int n,m,k; 
void dfs(int u)
{
	visited[u] = 1;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0&&map[u][i]==1)
//			viisted[i] = 1;
			dfs(i);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int v1, v2;
		scanf("%d%d",&v1,&v2);
		map[v1][v2] = 1;
		map[v2][v1] = 1;
	}	
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
			visited[j] = 0; 
		int r; scanf("%d",&r);
		int cnt = 0;
		visited[r] = 1; //�൱�����r�Ѿ������ڱ��α����з�����
		for(int u=1;u<=n;u++)
		{
			if(!visited[u])
			{
				dfs(u);
				cnt++;
			}
		} 
		//cnt�������ǿ��ͨ��������������
		// �����ͼ����k��ǿ��ͨ��������������ͨͼ����������Ҫk-1��·�� 
		printf("%d\n",cnt-1);
	}
	return 0;
} 
