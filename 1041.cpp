#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e5+20;
int n;
int num[maxn];
int cnt[maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        cnt[num[i]]++;
    }
    int flag=0;
    int ans;
    for(int i=1;i<=n;i++)
    {
        if(cnt[num[i]]==1)
        {
            flag = 1;
            ans = num[i];
            break;
        }
    }
    if(flag) printf("%d",ans);
    else printf("None");
    return 0;
    // sort(num+1,num+1+n);
    // int cnt = 1;
    // int flag = 1;
    // int ans = 0;
    // for(int i=2;i<=n;i++)
    // {
    //     if(num[i]==num[i-1]) cnt++;
    //     else if(num[i]!=num[i-1]){
    //         if(cnt==1){
    //             flag = 0;
    //             ans = num[i-1];
    //             break;
    //         }
    //         else cnt = 1;
    //     }
    // }
    // if(flag) printf("None");
    // else printf("%d",ans);
    // return 0;
}