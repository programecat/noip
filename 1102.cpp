#include<iostream>
using namespace std;
int main()
{
	int a,b[100],c,d;
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>b[i];
		
	}
	cin>>c;
	for(int i=0;i<a;i++)
	{
		if(b[i]==c)
		{
			d++;
		}
		
	}
	cout<<d;
 } 
