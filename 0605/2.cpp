#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1e5+20;
struct Page{
    int id;
    int tag;//表明时间
}page[maxn];
int num[maxn];
int maxsize,m;
vector<Page>cache;
vector<int>ans;
int main()
{
    scanf("%d%d",&maxsize,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&num[i]);
    int index = 1;
    while(cache.size()<maxsize&&index<=m){
        Page new_page; 
        int flag = true;
        new_page.id = num[index++];
        new_page.tag = 1;
        for(int i=0;i<cache.size();i++)
        {
            if(new_page.id == cache[i].id) 
            {
                cache[i].tag=1;
                flag = false;
            }
            else cache[i].tag++;
        }
        if(flag) cache.push_back(new_page);
    }
    while(index<=m)
    {
        Page new_page; 
        int flag = true;
        new_page.id = num[index++];
        new_page.tag = 1;
        for(int i=0;i<cache.size();i++)
        {
            if(new_page.id == cache[i].id)
            {
                cache[i].tag=1;
                flag = false;
            }
            else cache[i].tag++;
        }
        if(flag)
        {
            int tmp_tag = -1;
            int key = 0;
            for(int i=0;i<cache.size();i++)
            {
                if(cache[i].tag>tmp_tag)
                {
                    tmp_tag = cache[i].tag;
                    key = i;
                }
            }
            ans.push_back(cache[key].id);
            cache[key] = new_page;
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        if(i==0) printf("%d",ans[i]);
        else printf(" %d",ans[i]);
    }
}