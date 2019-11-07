#include <iostream>
using namespace std;
//int main(){
//	int a[110000] = {-1,1,2,3,4,6};
//	int x = 5;
//	int left = 1, right = 5,mid;
//	while(left<=right){
//		mid = (left+right)/2;
//		if(a[mid]<=x) left = mid + 1;
//		else right = mid -1;
//	} 
//	cout<<a[right]<<endl;
//	return 0;
//}

int n,m,a[110000];
int main(){
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[0]=-1;
	
	for(int i=1;i<=m;i++){
		int left = 1, right = n,mid;
		int x;
		cin>>x;
		while(left<=right){
			mid = (left+right)/2;
			if(a[mid]<=x) left = mid + 1;
			else right = mid -1;
		} 
		cout<<a[right]<<endl;
		
	}
	return 0;
}
