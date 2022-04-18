#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 2500; //10 10 -> 20 
float coefficient[maxn];
float A_coefficient[maxn];
float B_coefficient[maxn];
int main(){
	int ka; scanf("%d",&ka);
	for(int i=1;i<=ka;i++)
	{
		int e; float c;scanf("%d%f",&e,&c);
		// printf("%d %f\n",e,c);
		A_coefficient[e] = c; // x^e的系数是c 
		// printf("%f\n",A_coefficient[e]);
	}
	int kb; scanf("%d",&kb);
	for(int j=1;j<=kb;j++)
	{
		int e; float c;scanf("%d%f",&e,&c);
		// printf("%d %f\n",e,c);
		B_coefficient[e] = c;
		// printf("%f\n",B_coefficient[e]);
	}
	
	int cnt = 0;
	for(int i=0;i<=maxn;i++)
	{
		if (abs(A_coefficient[i])>1e-6)
		{
			for(int j=0;j<=maxn;j++)
			{
				if(abs(B_coefficient[j])>1e-6)
				{
//					if (coefficient[i+j] == 0)
//						cnt = cnt + 1;
					coefficient[i+j] += A_coefficient[i] * B_coefficient[j]; //
					// printf("%d %d %f %f\n",i,j,A_coefficient[i],B_coefficient[j]);
				}
			}
		}
	}
	for(int i=maxn;i>=0;i--)
	{
		if(coefficient[i]!=0) cnt ++;
	}
	printf("%d",cnt);
	for(int i=maxn;i>=0;i--)
	{
		if(coefficient[i]!=0)
		{
			printf(" %d %.1f",i,coefficient[i]);
		}
	}
	return 0;
}
