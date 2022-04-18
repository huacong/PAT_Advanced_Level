#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
long long convert(char str[], long long radix) // ���ַ���n,����radixת��Ϊʮ���� 
{
	long long res = 0;
	for(int i=0;i<=strlen(str)-1;i++)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			if (str[i]-'0'>=radix) return 0;// 15 -17
			res = res*radix + str[i]-'0';
		}
		else if(str[i]>='a' && str[i]<='z')
		{
			if (str[i]-'a'+10>=radix) return 0; // 15 -17
			res = res*radix + str[i]-'a' +10;
		}
	}
	return res;
}
long long find_radix(char str[], long long num) // ʹ��n�ܹ���ʾnum,������Ϊ���ٱȽϺ��� 
{
	//������������
	// low��Ѱ��str���������ֲ���1��Ϊ���ƣ����������� num 
	long long  high = 0;
	long long  low = 2;
	// char charmax = '0';
	for(int i=0;i<=strlen(str)-1;i++)
	{
		if (str[i]>='0' && str[i]<='9')
			low = low > (str[i]-'0')?low:(str[i]-'0'+1);
		else if(str[i]>='a' && str[i]<='z')
			low = low > (str[i]-'a'+10)?low:(str[i]-'a'+10+1);
	}
//	if(charmax>='a') low = charmax-'a' + 11;
//	else low = charmax-'0' + 1;
//	if (low<2) low = 2;
	high = max(num+1,low+1);
	while(low<=high)
	{
		long long mid = (low+high)/2;
		long long tmp = convert(str, mid);
		if (tmp<0 || tmp>num ) high = mid - 1;
		else if(tmp == num) 
		{
			high =  mid;
			if (convert(str, low)==num) 
				return low;
		}
		else low = mid + 1; 
	}
	return -1;
}
int main()
{
	//Ѱ��ʹ����������ͬ�Ľ���
//	string n1,n2;
//	cin>>n1>>n2;
//	cout<<n1<<" "<<n2;
//  input: hello word
//  output: hello word

//	char str1[10];
//	char str2[10]; ���Ҳ�ǵ��ո��ֹͣ 
//	scanf("%s%s",str1,str2);
//	printf("%s\n%s",str1,str2);
//hello word
//hello
//word  
	char str1[11];
	char str2[11];
	long long tag, radix, res_radix;
	scanf("%s%s%lld%lld",str1,str2,&tag,&radix);
	if (tag)
		res_radix = find_radix(str2, convert(str1, radix));
	else
		res_radix = find_radix(str1, convert(str2, radix));
	if (res_radix==-1) printf("Impossible\n");
	else printf("%lld\n",res_radix);
	return 0;
}
/*0 0 1 0*/
