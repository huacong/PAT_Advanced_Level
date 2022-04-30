#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int v[maxn];
int c[maxn];
int num[maxn];
int f[maxn];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    //朴素做法
    // for(int i=1;i<=n;i++)
    //     scanf("%d%d%d",&v[i],&c[i],&num[i]);
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=m;j>=0;j--)
    //     {
    //         for(int k=0;k<=num[i];k++)
    //         {
    //             if(j >= k*v[i])
    //             {
    //                 f[j] = max(f[j],f[j-k*v[i]]+k*c[i]);
    //             }
    //         }
    //     }
    // }
    // printf("%d",f[m]);

    //转为0-1背包问题
    // int tot = 0;
    // for(int i=1;i<=n;i++)
    // {
    //     int temp_v, temp_c, temp_num;
    //     scanf("%d%d%d",&temp_v,&temp_c,&temp_num);
    //     for(int j=1;j<=temp_num;j++)
    //     {
    //         v[++tot] = temp_v;
    //         c[tot] = temp_c;
    //     }
    // }
    // for(int i=1;i<=tot;i++)
    //     for(int j=m;j>=v[i];j--)
    //         f[j] = max(f[j],f[j-v[i]]+c[i]);
    // printf("%d",f[m]);
    
    //通过二进制的思想
    int tot = 0;
    for(int i=1;i<=n;i++)
    {
        int temp_v, temp_c, temp_num;
        scanf("%d%d%d",&temp_v,&temp_c,&temp_num);
        int t = 1;
        while(temp_num>=t){
            v[++tot] = temp_v*t;
            c[tot] = temp_c*t;
            temp_num-=t;
            t=t*2;
        }
        v[++tot] = temp_v*temp_num;
        c[tot] = temp_c*temp_num;
    }
    for(int i=1;i<=tot;i++)
        for(int j=m;j>=v[i];j--)
            f[j] = max(f[j],f[j-v[i]]+c[i]);
    printf("%d",f[m]);
    return 0;
}