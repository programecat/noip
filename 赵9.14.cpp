//#include<iostream>
//using namespace std;
//int main()
//{
//	int n,m,x;
//	cin>>n;
//	int a[100];
//	for(int i=0;i<n;i++)
//	{
//		cin>>a[i];
//	}
//	cin>>m;
//	for(int i=0;i<n;i++)
//	{
//		if(a[i]==m)
//		{
//			x++;
//		}
//	}
//	cout<<x<<endl;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a[100][100];
//	int n,m;
//	cin>>n>>m;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cin>>a[i][j];
//		}
//	}
//}
//#include<iostream>
//#include<cstring>
//using namespace std;
//int main()
//{
//	char a[101];
//	cin.getline(a,101); 
////	cout<<a;
//	char b,c;
//	b=getchar();
//	getchar();
//	c=getchar();
//	for(int i=0;i<strlen(a);i++)
//	{
//		if(a[i]==b)
//		{
//			a[i]=c;
//		}
//	}
//	cout<<a<<endl;
//}
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char a[101];
	char b[101];
	cin.getline(a,101);
	cin.getline(b,101);
	char a1[101],b1[101];
	int n=0,m=0;  //在定义一个变量的时候给它一个初始值，是很好的习惯 --by teacherweng
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i] !=' ')
		{
			a1[n]=a[i]; //逻辑很清楚，73和74行也可以合并写成 a1[n++] = a[i]; -- by teacherweng
			n++;
		}
	}
	for(int j=0;j<strlen(b);j++)
	{
		if(b[j]!=' ')
		{
			b1[m]=b[j];
			m++;
		}
	}
	strlwr(a1);
	strlwr(b1);
	//根据题目，这里还需要再比较一下a1和b1: strcmp(a1, b1) 两者相等返回0 -- by teacherweng
	
	cout<<a1<<endl<<b1<<endl;
}
