#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
int main()
{
	int n,a[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}	
	for(int j=n;j>0;j--)
	{
		for(int i=0;i<j;i++)
		{
			if(a[i]>a[i+1])swap(a[i],a[i+1]);
		}
	}	
	int x=1,y=a[0];
	for(int j=1;j<n;j++)
	{
		if(a[j]==y)
		{
			x++;
		}
		else
		{
			cout<<a[j-1]<<" "<<x<<endl;
			x=1;
			y=a[j];
		}
	}
	cout<<y<<" "<<x;
	
}
