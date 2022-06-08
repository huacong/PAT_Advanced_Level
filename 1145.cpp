#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e4+20;
int maxsize,n,m;
int num[maxn];
int table[maxn];
bool isprime(int x)
{
    for(int i=2;i<(x/2+1);i++)
    {
        if(x%i==0) return false;
    }
    return true;
}

int main()
{
    scanf("%d%d%d",&maxsize,&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    while(!isprime(maxsize))  maxsize++;
    //printf("maxsize:%d \n",maxsize);
    for(int i=0;i<maxsize;i++) table[i] = -1;
    for(int i=0;i<n;i++)
    {
        int flag = false;
        for(int j=0;j<maxsize;j++)
        {
            int hi = (num[i]%maxsize + j*j) % maxsize;
            if(table[hi]==-1)
            {
                flag = true;
                table[hi] = num[i];
                break;
            }
        }
        if(!flag)
            printf("%d cannot be inserted.\n",num[i]);

    }
    int tot = 0;
    //for(int i=0;i<maxsize;i++) printf("%d:%d\n",i,table[i]);
    for(int i=0;i<m;i++)
    {
        bool flag = false;
        int a;scanf("%d",&a);
        for(int j=0;j<maxsize;j++)
        {
            int hi = (a%maxsize + j*j) % maxsize;
            tot++;
            if(table[hi]==a||table[hi]==-1)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            tot++;
        }
        //printf("%d:%d\n",a,tot);
            
    }
    printf("%.1f",tot*1.0/m);
    return 0;
}
/*
11:2
4:3
15:9
2:10*/