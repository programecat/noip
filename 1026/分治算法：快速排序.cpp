#include <stdio.h>
#include <iostream>
using namespace std;
int a[8] = {6,10,11,8,4,1,9,7};

void qsort(int left,int right){
	int i=left,j=right,mid=a[(left+right)/2];
	while(i<=j){
		while(a[i]<mid) i++; //在左边找大于等于mid的数 
		while(a[j]>mid) j--; //在右边找小于等于mid的数
		if(i<=j){
			swap(a[i],a[j]); //交换 
			i++,j--;		 //继续找 
		}		
	}	
	if(left<j) qsort(left,j); //左右两个部分分别递归，继续排序 
	if(i<right) qsort(i,right);
}

void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	
	for(int i=0;i<8;i++) cout<<a[i]<<endl;
	cout<<"Let's make a sort"<<endl;
	
	qsort(0,7);
	
	for(int i=0;i<8;i++) cout<<a[i]<<endl;

	return 0;
}

