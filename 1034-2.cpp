#include<cstdio>
#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
const int maxn = 2e3+20;
map<string, int>stringToInt;
map<int, string>intToString;
map<string, int>ans;
int father[maxn];
int weight[maxn];
int v[maxn];
int edge[maxn][maxn];
int cnt[maxn];
int num;
int n,k;
bool cmp(int x,int y)
{
	return x>y;
}
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
int find(int v)
{
	if(father[v]==v) return v;
	return father[v] = find(father[v]);
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=2*n;i++)
		father[i] = i;
	for(int i=1;i<=n;i++)
	{
		string name1; string name2;
		int w;
		////scanf("%s%s%d",name1,name2,&weight);
		cin >> name1 >> name2 >> w;
		int num1 = str2int(name1); //father[num1] = num1;
		int num2 = str2int(name2); //father[num2] = num2;
		v[num1] += w;
		v[num2] += w;
		edge[num1][num2] = w;
		edge[num2][num1] = w;
		int fx = find(num1); int fy = find(num2);
		if(fx!=fy)
		{
			weight[fy] += weight[fx] + edge[num1][num2];//edge[fy][fx];
			father[fx] = fy;
		}
		else if(fx==fy)
			weight[fy] += edge[num1][num2];
	}
	for(int i=1;i<=num;i++)
		cnt[find(i)] ++;
	int tmp = 0;
	for(int i=1;i<=num;i++)
	{
		//保证是根 同时节点数>2 
		if(cnt[i]>2&&i==find(i)&&weight[i]>k) // 符合规则的root 
		{
			//printf("yes-%d",i);
			int fi = find(i);
			int max_weight = 0;
			int max_weight_num = 0;
			tmp++;
			int member = 0;
			for(int j=1;j<=num;j++)
			{
				 if(fi == find(j))
				 {
				 	member++;
				 	if(v[j]>max_weight)
				 	{
				 		max_weight = v[j];
				 		max_weight_num = j;
					 }
				  } 
			}
			ans[intToString[max_weight_num]] = member;
		}	
	}	
	printf("%d\n",tmp);
	for(auto it:ans)
	{
		cout<<it.first<<" "<<it.second <<endl;
	}	
} 
