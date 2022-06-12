#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int y1,t1,m1;
int y2,t2,m2;
int correct1;
int correct2;
int fy1,ft1,fm1;
int fy2,ft2,fm2;
char str[7][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
void calc1(int today)
{
    if((y1+1)%7==today) 
    {
        correct1++;
        fy1 = 1;
    }
    if(t1%7==today) 
    {
        correct1++;
        ft1 = 1;
    }
    if((m1+6)%7==today) 
    {
        correct1++;
        fm1 = 1;
    }
}
void calc2(int today)
{
    if((y2+1)%7==today) 
    {
        correct2++;
        fy2 = 1;
    }
    if(t2%7==today) 
    {
        correct2++;
        ft2 = 1;
    }
    if((m2+6)%7==today) 
    {
        correct2++;
        fm2 = 1;
    }
}
int main(){
    scanf("%d%d%d",&y1,&t1,&m1);
    scanf("%d%d%d",&y2,&t2,&m2);
    // if y1 correct
    
    for(int i=0;i<=6;i++)
    {
        fy1 = ft1 = fm1 = 0;
        fy2 = ft2 = fm2 = 0;
        correct1 = correct2 = 0;
        calc1(i);calc2(i);
        if((correct1==1)&&(correct2==1))
        {
            printf("%s\n",str[i]);
            if(fy1==1) printf("yesterday\n");
            else if(ft1) printf("today\n");
            else printf("tomorrow\n");
            if(fy2) printf("yesterday");
            else if(ft2) printf("today");
            else printf("tomorrow");
        }
    }
    return 0;
}