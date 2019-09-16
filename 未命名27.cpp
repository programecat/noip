#include<iostream> 
using namespace std;

int main(){
	int n,m,num,a[100];
	int g = 0;  //定义变量时给一个初始值，是好习惯。 -- by teacherweng
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int num=n;num>-1;num--){ // for循环语句，用由小变大的写法 for (int i = 0; i < n; n++)
		if (a[num] == m){
			g++;
		}
	}
	cout<<g;
}
