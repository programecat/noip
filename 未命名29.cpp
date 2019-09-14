#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
	char a [101];
	cin.getline(a,101);
	
	char b,c;
	b = getchar();
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
