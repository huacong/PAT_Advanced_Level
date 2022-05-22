#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int map[maxn][maxn];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<i+1;j++)
            scanf("%d",&map[i][j]);
    for(int i=n-2;i>=0;i--)
        for(int j=0;j<n-1;j++)
            map[i][j] = max(map[i+1][j],map[i+1][j+1]) + map[i][j];
    printf("%d",map[0][0]);
    return 0;
}