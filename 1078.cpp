#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
bool isprime(int x)
{
    if(x==1) return false;//判断素数这一步
    for(int i=2;i<(x/2+1);i++)
    {
        if(x%i==0) return false;
    }
    return true;
}
const int maxn = 1e4+20;
int num[maxn];
int maxsize,n;
int table[maxn];
int flag_array[maxn];
int main()
{
    scanf("%d%d",&maxsize,&n);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    while(!isprime(maxsize)) maxsize++;
    for(int i=0;i<maxsize;i++) table[i]=-1;
    for(int i=0;i<n;i++) flag_array[i]=0;
    for(int i=0;i<n;i++)
    {
        bool flag = false;
        int hi;
        for(int j=0;j<maxsize;j++)
        {
            hi = (num[i]+j*j)%maxsize;
            if(table[hi]==-1)
            {
                table[hi] = num[i];
                flag = true;
                break;
            }
        }
        if(i==(n-1))
        {
            if(!flag) printf("-");
            else printf("%d",hi);
        }
        else 
        {
            if(!flag) printf("- ");
            else printf("%d ",hi);
        }
    }
    return 0;
}