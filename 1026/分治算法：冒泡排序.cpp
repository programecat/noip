#include <stdio.h>
#include <iostream>
using namespace std;
int a[8] = {6,10,11,8,4,1,9,7};

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	int n = 8;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
		}
	}
	
	for(int i=0;i<=7;i++) cout<<a[i]<<"-";
	return 0;
}
