#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	char tsen[256],num[20]={'0','1','2','3','4','5','6','7','8','9'}; // 其实不需要定义char num[20]这个字符数组
	int snm=0;
	
		cin.getline(tsen,255);
	for(int i=0;i<strlen(tsen);i++)
	{for(int j=0;j<10;j++)  //这个嵌套循环可以用 if (tsen[i] >= '0' && tsen[i] <= '9')替代
	{if(tsen[i]==num[j])
	{snm++;
	}
	
	}
	
	
	}
	cout<<snm;
}
