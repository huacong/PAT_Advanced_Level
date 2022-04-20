#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int maxn = 2e3+20;
int n,k;
map<string, int>stringToInt;
map<int, string>intToString;
map<string, int>ans;
int edge[maxn][maxn];
int v[maxn]; // 每个节点的对应的权重 
int visited[maxn];
int num; //对应name的编号 
int str2int(string s)
{
	if(stringToInt[s]==0)
	{
		stringToInt[s] = ++num;
		intToString[num] = s;
		return num;
	}
	else return stringToInt[s];
}
int dfs(int u,int flag)
{
	visited[u] =flag;
	
	int ans = 0;
	for(int i=1;i<=num;i++)
	{
		if(!visited[i]&&edge[u][i]>0)
		{
			ans += edge[u][i];
			ans += dfs(i,flag);
		}	
		else if(visited[i]&&edge[u][i]>0) ans += edge[u][i];
	}
	//printf("***%d %d %d\n",u,flag,ans);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		char name1[4]; char name2[4];
		int weight;
		//scanf("%s%s%d",name1,name2,&weight);
		cin >> name1 >> name2 >> weight;
		int num1 = str2int(name1);
		int num2 = str2int(name2);
		v[num1] += weight;
		v[num2] += weight;
		edge[num1][num2] += weight;
		edge[num2][num1] += weight;
	}
	int cnt = 0; 
	int flag = 1;

	for(int i=1;i<=num;i++) // num个节点 
	{
		int max_weight = 0;
		int max_weightnum = 0;
		int members = 0;
		int sum_weight = 0;
		if(!visited[i])
		{
			sum_weight = dfs(i,flag);
			sum_weight = sum_weight / 2;
			for(int j=1;j<=n;j++)
			{
				if(visited[j]==flag)
				{
					members++;
					if(v[j]>max_weight) 
					{
						max_weight = v[j];
						max_weightnum = j;
					}
				}
			}
		}
		//printf("%d %d\n",i,sum_weight);
		flag++;
		if(sum_weight>k&&members>2)
		{
			cnt++;
			ans[intToString[max_weightnum]] = members;
		}
			
	}
	printf("%d\n",cnt);
	for(auto it:ans)
	{
		cout<<it.first<<" "<<it.second <<endl;
	}
	return 0;
}
