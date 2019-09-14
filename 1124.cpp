#include<iostream>
using namespace std;
int main()
{
	int A[100][100],B[100][100],I,J,li[100][100];
	cin>>I>>J;
	for(int i=0;i<I;i++)
	{
			for(int j=0;j<J;j++)
			{
				cin>>A[i][j]; 
			}
	
	}
		for(int i=0;i<I;i++)
	{
			for(int j=0;j<J;j++)
			{
				cin>>B[i][j]; 
			}
	
	}
		for(int i=0;i<I;i++)
	{
			for(int j=0;j<J;j++)
			{
				li[i][j]=A[i][j]+B[i][j];
			}
	
	}
	for(int i=0;i<I;i++)
	{
			for(int j=0;j<J;j++)
			{
				cout<<li[i][j]<<" ";
			}
		cout<<endl;
	}
	
}
