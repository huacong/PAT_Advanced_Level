#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn = 260;
char str[maxn];
int k;
int main()
{
    scanf("%s%d",str,&k);
    int len = strlen(str);
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<len-1;j++)
        {
            if(str[j+1]<str[j])
            {
                for(int u=j;u<len-1;u++)
                    str[u] = str[u+1];
                break;
            }
        }
        len--;
    }
    int start = 0;
    if(len==1&&str[start]=='0') printf("0");
    else{
        while(str[start]=='0') start++;
        for(int i=start;i<len;i++) 
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}