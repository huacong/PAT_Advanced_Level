#include<cstdio>
#include<algorithm>
using namespace std;
long long n;
const int maxn = 105;
struct Ratio{
    long long a;
    long long b;
    int flag;//0 is -, 1 is +
}ration[maxn];
long long gcd(long long a,long long b)
{
    long long c = b;
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
    scanf("%lld",&n);getchar();//滤掉回车
    for(int i=0;i<n;i++)
    {
        char s1;
        scanf("%c",&s1);
        if(s1=='-')
        {
            ration[i].flag = 0;
            scanf("%lld/%lld",&ration[i].a,&ration[i].b);
        }
        else{
            ration[i].flag = 1;
            ration[i].a = s1-'0';
            scanf("%c",&s1);
            while(s1!='/')
            {
                ration[i].a = ration[i].a*10 + (s1-'0');
                scanf("%c",&s1);
            }
            scanf("%lld",&ration[i].b);
        }
        getchar();//滤掉空格
    }
    // for(int i=0;i<n;i++)
    // {
    //     if(ration[i].flag) 
    //         printf("%d/%d",ration[i].a,ration[i].b);
    //     else printf("-%d/%d",ration[i].a,ration[i].b);
    //     printf("\n");
    // }
    long long b_lcm = ration[0].b;
    for(int i=1;i<n;i++)
        b_lcm = b_lcm*ration[i].b/gcd(b_lcm,ration[i].b);
    long long a_sum = 0;
    for(int i=0;i<n;i++)
    {
        if(ration[i].flag)
            a_sum += (b_lcm/ration[i].b)*ration[i].a;
        else a_sum -= (b_lcm/ration[i].b)*ration[i].a;
    }
    if(a_sum/b_lcm)
        printf("%lld",a_sum/b_lcm);
    long long a = a_sum - (a_sum/b_lcm)*b_lcm;
    if(a!=0)
    {
        if(a_sum/b_lcm) printf(" %d/%d",a/gcd(a,b_lcm),b_lcm/gcd(a,b_lcm));
        else printf("%lld/%lld",a/gcd(a,b_lcm),b_lcm/gcd(a,b_lcm));
    }
    else{
        if(a_sum/b_lcm==0) printf("0");
    }
        
    return 0;
}