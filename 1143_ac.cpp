#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int n,m;
    scanf("%d %d",&m,&n);
    vector<int> pre(n);
    map<int,bool> mark;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&pre[i]);
        mark[pre[i]] = true;
    }
    for(int i = 0;i < m; i++)
    {
        int v,a,b;
        scanf("%d %d",&a,&b);
        for(int  j = 0; j < n; j++)		//for循环寻找可能的LCA
        {
            v = pre[j];
            if((v < a && v > b) || (v > a && v < b) || (v == a) || (v == b))
                break;
        }
        if(mark[a] == false && mark[b] == false)
            printf("ERROR: %d and %d are not found.\n",a,b);
        else if(mark[a] == false)
            printf("ERROR: %d is not found.\n",a);
        else if(mark[b] == false)
            printf("ERROR: %d is not found.\n",b);
        else if(a == v || b == v)
            printf("%d is an ancestor of %d.\n",v,v == a ? b:a);
        else
            printf("LCA of %d and %d is %d.\n",a,b,v);
    }
    return 0;
}

