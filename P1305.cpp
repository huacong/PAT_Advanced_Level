#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn  = 100;
int n;
struct node{
    int left;
    int right;
    int father;
}tree[maxn];
void print(int root)
{
    if(root!=0)
    {
        printf("%c",root-1+'a');
        print(tree[root].left);
        print(tree[root].right);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char str[5]; scanf("%s",str);
        int id = str[0]-'a'+1;
        int l,r;
        if(str[1]=='*') l = 0;
        else l = str[1] - 'a' + 1;
        if(str[2]=='*') r = 0;
        else r = str[2] - 'a' + 1;
        tree[id].left = l; tree[l].father = id;
        tree[id].right = r; tree[r].father = id;
    }
    int root;
    for(int i=1;i<=n;i++)
    {
        if(tree[i].father==0)
        {
            root = i;
            break;
        }
    }
    print(root);
    return 0;
}