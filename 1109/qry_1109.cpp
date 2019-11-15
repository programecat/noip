//1239：统计数字 
#include<iostream>
using namespace std;

void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
	
}
int main(){
	
	int n;
	cin>>n; 
	int a[n];
	for (int i = 0;i<n;i++){
		cout<<endl;
		cin>>a[i];

	}
	
	
	
	for(int j = 0;j<n-1;j++){
		for (int i = 0;i<n-j-1;i++){
		if (a[i] > a[i+1]) swap(a[i],a[i+1]);
		} 
		
	
	}
	
	cout<<endl;
	
	int t=a[0],c=1;
	for (int i = 1;i<n;i++){
		int x = a[i];
		if (t == x) c++;
		if (t != x){
			cout<<t<<" "<<c<<endl;
			c=0;
			t =a[i];
			c++;
		} 
	}
	cout<<t<<" "<<c<<endl;
	return 0;
}






























































































































































































































































































































































//int main(){
//	int s[10001];//桶 
//	int n,a[10001];
//	cin>>n;
//	cout<<endl;
//	for (int i=0;i<n;i++){
//		cin>>a[i];//导入每个数字 
//		cout<<endl;
//	}
//	
//	for(int i=0;i<n;i++){
//		int pos=a[i];
//		s[pos]++;//从数字推出桶的下标 
//	}  
//	int times,d;
//	cout<<endl;
//	
//
//	for(int i=0;i<10001;i++){
//
//			times=s[i];
//			cout<<a[i]<<" "<<times<<endl;
//
//	}
//
//	return 0;
//} 

