#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn = 1e6+20;
char pre[maxn];
char post[maxn];
int cnt = 0;
int main()
{
    scanf("%s%s",pre,post);
    int len = strlen(pre);
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-1;j++)
        {
            if(pre[i]==post[j+1]&&pre[i+1]==post[j])
                cnt++;
        }
    }
    printf("%d",1<<cnt);
    return 0;
}