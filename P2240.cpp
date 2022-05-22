#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e5+30;
int num[maxn];
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    sort(num,num+n);
    long long tot=0;
    for(int i=0;i<n;i++) tot+=num[i];
    if(tot<k) printf("0");
    else{
    int l = num[n-1]/k;
    int r = num[n-1];
    int mid;
    long long ans = 0;
    while(l<=r)
    {
        ans = 0;
        mid = l+(r-l)/2;
        for(int i=0;i<n;i++) ans+=num[i]/mid;
        if(ans<k) r=mid-1;
        else l=mid+1;
    }
    printf("%d",r);
    }
    return 0;
}