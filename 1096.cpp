#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int factor[33];
int main()
{
    scanf("%d",&n);
    int maxn = sqrt(n);
    for(int len=12;len>=1;len--)
    {
        for(int x=2;x<=maxn;x++)
        {
            int start = x;
            int ans = 1;
            for(int i=0;i<len;i++)
                ans = ans*(start+i);
            if(n%ans==0)
            {
                printf("%d\n%d",len,start);
                for(int i=1;i<len;i++)
                    printf("*%d",start+i);
                return 0;
            }
        }
    }
    printf("1\n%d", n);
    return 0;
    
}