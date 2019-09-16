#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char a[101];
	cin.getline(a,101); 
	
	char b,c; // 对于要读取同一行中的多个字符（有空格分隔）的情况，我们统一使用 cin >> b >> c; -- by teacherweng
	cin.get(b);
	cin.get(c);
	for(int i;i<strlen(a);i++)
	{
		if(a[i]=b)  // 抓到一个bug ~, 另外if语句后面也尽量补上大括号
		a[i]=c;
	}
	cout<<a;
}
 
