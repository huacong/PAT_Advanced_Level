#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn = 10;
char str1[maxn];
char str2[maxn];
int find(int l1, int r1, char c)
{
    for(int i=l1;i<=r1;i++)
    {
        if(str1[i]==c) return i;
    }
    return -1;
}
void dfs(int l1,int r1,int l2, int r2)
{
    printf("%c",str2[r2]);
    int m = find(l1,r1,str2[r2]);
    if(m==-1){ return; }
    if(m>l1) dfs(l1,m-1,l2,l2+(m-1-l1));
    if(m<r1) dfs(m+1,r1,l2+m-l1,r2-1);
}
int main()
{
    scanf("%s%s",str1,str2);
    int l1 = 0; int l2 = 0;
    int r1= strlen(str1)-1; int r2 = strlen(str2)-1;
    dfs(l1,r1,l2,r2);
    return 0;
}