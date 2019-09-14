#include<iostream> 
using namespace std;

int main(){
	int n,m,num,a[100];
	int g = 0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int num=n;num>-1;num--){
		if (a[num] == m){
			g++;
		}
	}
	cout<<g;
}
