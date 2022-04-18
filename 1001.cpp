#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int a,b; scanf("%d%d",&a,&b);
	char str[20];
	char res[20];
	sprintf(str, "%d", a+b);
	// printf("str:%s",str);
	int len = strlen(str);
	int isnegative = (str[0]=='-');
	int cnt = 0;
	int index = 0;
	for(int i=len-1;i>=isnegative;i--)
	{
		res[index++] = str[i];
		cnt = cnt + 1;
		if(cnt%3==0&&i!=isnegative)
			res[index++] = ',';
	}

	if(isnegative)
		printf("%c",str[0]);

	for(int i=index-1;i>=0;i--)
		printf("%c",res[i]);
	return 0;
}

