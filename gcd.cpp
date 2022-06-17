#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100;
int num[maxn];
int gcd(int a,int b)
{
    int c = b;
    while(a%b!=0)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return c;
}
int main()
{
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    int ans_gcd = num[1];
    int ans_lcm = num[1];
    for(int i=2;i<=n;i++)
        ans_gcd = gcd(ans_gcd,num[i]);
    for(int i=2;i<=n;i++)
        ans_lcm = ans_lcm*num[i]/gcd(ans_lcm,num[i]);
        
    printf("gcd:%d lcm:%d",ans_gcd,ans_lcm);
    return 0;
}