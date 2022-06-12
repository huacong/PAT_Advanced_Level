#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    int key;
    int data;
    vector<node>children;
    int father;
};
int n,degree;
int depth = 3;
node create_tree(node root,int fa,int d)
{
    int data;
    //scanf("%d",&data);
    n--;
    root.data = data;
    root.father = fa;
    if(d<depth)
    {
        for(int i=1;i<=degree;i++)
        {
        node child; child.data = -1;
        root.children.push_back(child);
        }
        for(int i=0;i<degree;i++)
        {
        if(n-(degree-i)>0) root.children[i] = create_tree(root.children[i],data,d+1);
        else break;
        }
    } 
    return root;
}

int main()
{
    scanf("%d%d",&n,&degree);
    
    //根据完全的性质以及前序，可以求得最终的树的形状
    node root;
    //for(int i=1;i<)
    root = create_tree(root,-1,1);
    for(int i=0;i<root.children.size();i++)
        printf("%d  ",root.children[i].data);
}