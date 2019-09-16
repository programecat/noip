#include <iostream>
using namespace std;
int main(){
int n,m,b,c;
cout<<"输入数字数量："; 
cin>>n;
cout<<"输入："; 
b=n;
c=0;
int a[100000];  // 定义数组的时候，也不要太大，程序中的栈空间容易不够用，一般100或者1000 -- by teacherweng
for(b=0;b<n;b++){
	cin>>a[b];}
	cout<<"要查找的数："; 
	cin>>m;

for(b=0;b<n;b++){
	if(a[b]==m){c++;
		}
		}
cout<<"相同数数量："<<c;
return 0;
} 
