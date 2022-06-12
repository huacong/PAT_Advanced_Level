#include<cstdio>
#include<algorithm>
#include<map>
#include<string.h>
#include<vector>
using namespace std;
const int maxn = 1e5;
int n,m;
int couple[maxn];
int vis[maxn];
vector<int>vec;
int main()
{
    memset(couple,-1,sizeof(couple));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a,b; scanf("%d%d",&a,&b);
        couple[a] = b;
        couple[b] = a;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int a; scanf("%d",&a);
        vis[a] = 1;
    }
    for(int i=0;i<maxn;i++)
    {
        if(vis[i])//它来了
        {
            if(couple[i]==-1) vec.push_back(i);
            else if(vis[couple[i]]==0) vec.push_back(i);
        }
    }
    printf("%d\n",vec.size());
    for(int i=0;i<vec.size();i++)
    {
        printf("%05d",vec[i]);
        if(i!=vec.size()-1) printf(" ");
    }
    return 0;
}