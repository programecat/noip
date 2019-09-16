#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
	char a [101];
	cin.getline(a,101);
	
	char b,c;
	b = getchar(); // 对于要读取同一行中的多个字符（有空格分隔）的情况，我们统一使用 cin >> b >> c; -- by teacherweng
	getchar();
	c = getchar();
	cout<<b<<" "<<c<<endl;
	
	for(int i = 0; i < strlen(a); i++){
		if (a[i] == b){
			a[i]= c; 
		}
	}
	cout<<a<<endl;
}
