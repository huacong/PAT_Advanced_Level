#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
map<int,int>contest;
int vis[10005];
int n,k;
bool isPrime(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int num; scanf("%d",&num);
        contest[num] = i;
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int num; scanf("%d",&num);
        
        int rank = contest[num];
        if(rank==0) printf("%04d: Are you kidding?",num);
        else{
            if(vis[num]==0)
            {
                if(rank==1) printf("%04d: Mystery Award",num);
                else if(isPrime(rank)) printf("%04d: Minion",num);
                else printf("%04d: Chocolate",num);
                vis[num] = 1;
            }
            else printf("%04d: Checked",num);
        }
        if(i!=k) printf("\n");   
    }
}
