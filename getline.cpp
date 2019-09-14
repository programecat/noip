#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char a[101];
	cin.getline(a,101); 
	
	char b,c;
	cin.get(b);
	cin.get(c);
	for(int i;i<strlen(a);i++)
	{
		if(a[i]=b)
		a[i]=c;
	}
	cout<<a;
}
 
