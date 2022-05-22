#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 2e5+20;
int n,c;
int num[maxn];
long long ans;
// if(num[l]==q)
// {
//     int tmp = 0;
//     for(int i=l;i<=n;i++)
//     {
//         if(num[i]==q) tmp++;
//     }
//     return tmp;
// }
int left_check(int q)
{
    int l=1;int r=n;
    int mid;
    while(l<=r)
    {
        mid = l+(r-l)/2;
        if(num[mid]<q) l=mid+1;
        else r = mid-1;
    }
    if(num[l]==q) return l;
    return 0;
}
int right_check(int q)
{
    int l=1;int r=n;
    int mid;
    while(l<=r)
    {
        mid = l+(r-l)/2;
        //printf("l:%d mid:%d r:%d\n",l,mid,r);
        if(num[mid]>q) r=mid-1;
        else l = mid+1;
    }
    if(num[r]==q) return r;
}
int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    sort(num+1,num+n+1);
    for(int i=1;i<n;i++)
    {
        int query = num[i]+c;
        int lbound = left_check(query);
        //printf("query:%d lbound:%d rbound:",query,lbound);
        if(lbound!=0)
        {
            int rbound = right_check(query); 
            //printf("%d\n",rbound);
            ans += rbound-lbound+1;
        }
    }
    printf("%lld",ans);
    return 0;
}