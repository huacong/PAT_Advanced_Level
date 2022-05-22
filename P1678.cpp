#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e5+20;
int num[maxn];
int m,n;
int check(int query)
{
    int l=1;int r=m;
    int mid;
    while(l<=r)
    {
        mid = l+(r-l)/2;
        if(num[mid]>query) r= mid-1;
        else l=mid+1; 
    }
    return l;
}
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++) scanf("%d",&num[i]);
    sort(num+1,num+1+m);
    long long ans = 0;
    while(n--)
    {
        int b; scanf("%d",&b);
        int rbound; rbound= check(b);
        //printf("r:%d\n",rbound);
        if(rbound==1) ans+=abs(num[1]-b);
        else if(rbound==(m+1)) ans+=abs(num[m]-b);
        else{
            if((num[rbound]-b)<(b-num[rbound-1])) ans+=(num[rbound]-b);
            else ans+=(b-num[rbound-1]);
        }
        //printf("ans:%lld\n",ans);
    }
    printf("%lld",ans);
    return 0;
}
