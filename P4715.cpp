#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1<<7+20;
int n;
struct country{
    int power;
    int id;
}num[maxn];
bool cmp(country x, country y)
{
    return x.power > y.power;
}
int main()
{
    scanf("%d",&n);
    int tot = 1<<n;
    for(int i=1;i<=tot;i++)
    {
        scanf("%d",&num[i].power);
        num[i].id = i;
    }
    // sort(num+1,num+1+(tot/2),cmp);
    // sort(num+1+(tot/2),num+tot+1,cmp);
    // if(num[1].power<num[1+(tot/2)].power) printf("%d", num[1].id); 
    // else printf("%d",num[1+(tot/2)].id);
    // return 0;
    int begin = 1; 
    int end = tot;
    for(int i=1;i<n;i++)
    {
        int k = 0;
        for(int j=begin;j<=end;j+=2)
        {
            if(num[j].power>num[j+1].power)
            {
                num[++k].power = num[j].power;
                num[k].id = num[j].id;
            }
            else
            {
                num[++k].power = num[j+1].power;
                num[k].id = num[j+1].id;
            }
        }
        end = k;
    }
    if(num[1].power>num[2].power) printf("%d",num[2].id);
    else printf("%d",num[1].id);
    return 0;
}
