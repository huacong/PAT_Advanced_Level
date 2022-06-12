#include<cstdio>
#include<algorithm>
#include<map>
#include<string.h>
using namespace std;
map<char,int>shop;
const int maxn = 1e3+20;
char str1[maxn];
char str2[maxn];
int main()
{
    scanf("%s",str1); int len1 = strlen(str1);
    scanf("%s",str2); int len2 = strlen(str2);
    for(int i=0;i<len1;i++)
        shop[str1[i]]++;
    int flag = 1;
    int miss = 0;
    int correct = 0;
    for(int i=0;i<len2;i++)
    {
        if(shop[str2[i]]!=0)
        {
            correct++;
            shop[str2[i]]--;
        }
        else 
        {
            flag = 0;
            miss++;
        }
    }
    if(flag) printf("Yes %d",len1-len2);
    else printf("No %d",miss);
    return 0;
}