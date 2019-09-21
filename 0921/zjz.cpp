#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	char tsen[256],num[20]={'0','1','2','3','4','5','6','7','8','9'};
	int snm=0;
	
		cin.getline(tsen,255);
	for(int i=0;i<strlen(tsen);i++)
	{for(int j=0;j<10;j++)
	{if(tsen[i]==num[j])
	{snm++;
	}
	
	}
	
	
	}
	cout<<snm;
}
