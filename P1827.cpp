#include<cstdio>
#include<algorithm>
#include<stack>
#include<string.h>
using namespace std;
stack<char> st;
const int maxn = 30;
char str1[maxn];
char str2[maxn];
int find(int l1, int r1, char c)
{
    for(int i=l1;i<=r1;i++)
    {
        if(str1[i]==c) return i;
    }
}
void dfs(int l1,int r1, int l2, int r2)
{
    int m = find(l1,r1,str2[l2]);
    st.push(str2[l2]);
    if(m<r1) dfs(m+1,r1,r2-r1+m+1,r2);
    if(m>l1) dfs(l1,m-1,l2+1,l2+m-l1);
}
int main()
{
    scanf("%s%s",str1,str2);
    int l1 = 0; int r1 = strlen(str1)-1;
    int l2 = 0; int r2 = strlen(str2)-1;
    dfs(l1,r1,l2,r2);
    while(!st.empty())
    {
        printf("%c",st.top());
        st.pop();
    }
}