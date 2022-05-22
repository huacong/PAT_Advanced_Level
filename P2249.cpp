#include<cstdio>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e6+20;
int num[maxn];
int n,m;
// int check(int q)
// {
//     int l = 1;int r = n;
//     if (r==0) return -1;
//     int mid;
//     while(l<r)
//     {
//         mid = l + (r-l)/2;//防止溢出
//         printf("l:%d mid:%d r:%d\n",l,mid,r);
//         if(num[mid]<q) l=mid+1;
//         else r=mid;
//     }
//     if(num[l]==q) return l;
//     return -1;
// }
int check(int q)
{
    int l=1;int r=n;
    int mid;
    while(l<r)
    {
        mid = l+(r-l)/2;
        printf("l:%d mid:%d r:%d\n",l,mid,r);
        if(num[mid]>q) r=mid-1;
        else l = mid+1;
    }
    if(num[r]==q) return r;
    return -1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for(int i=1;i<=m;i++)
    {
        int query;scanf("%d",&query);
        printf("%d ",check(query));
    }
}