#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e3+20;
int father[maxn];
int hobby[maxn]; //一个兴趣对应多个人 
int cnt[maxn];
int n;
int find(int v)
{
	if(father[v]==v) return v;
	return father[v]=find(father[v]);
}
void Union(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx!=fy) father[fy] = fx;
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		father[i] = i;
	for(int i=1;i<=n;i++)
	{
		int k;scanf("%d:",&k);
		for(int j=1;j<=k;j++)
		{
			int h; scanf("%d",&h);
			if(hobby[h]==0)
				hobby[h] = i;
			else //有人已经有这个兴趣了 
			{
				if(find(hobby[h])!=find(i))
					Union(hobby[h],i);
			} 
		}
	}
	for(int i=1;i<=n;i++)
		cnt[find(i)]++;
	sort(cnt+1,cnt+n+1,cmp);
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]!=0) ans++;
		else break;
	}
	printf("%d\n",ans);
	for(int i=1;i<ans;i++)
		printf("%d ",cnt[i]);
	printf("%d",cnt[ans]);
	return 0;
}
