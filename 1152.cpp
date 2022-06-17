#include<cstdio>
#include<algorithm>
using namespace std;
int len,k;
char num[1020];
bool isPrime(long long x)
{
    for(long long i=2;i*i<=x;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}
int count_digit(long long x)
{
    int cnt = 0;
    while(x!=0)
    {
        x = x/10;
        cnt ++;
    }
    return cnt;
}
int main()
{
    scanf("%d%d",&len,&k);
    getchar();//滤掉回车
    for(int i=1;i<=len;i++)
        scanf("%c",&num[i]);
    for(int i=1;i<=len-(k-1);i++)
    {
        int start = i;
        long long ans = 0;
        for(int j=0;j<k;j++)
            ans = ans*10 + num[j+start]-'0';
        if(isPrime(ans))
        {
            int cnt = count_digit(ans);
            if(cnt==k)
                printf("%lld",ans);
            else{
                for(int i=0;i<(k-cnt);i++) 
                    printf("0");
                printf("%lld",ans);
            }
            return 0;
        }
    }
    printf("404");
    return 0;
    
}