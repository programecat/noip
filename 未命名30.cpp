#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int i1,j1;
	char a[101],b[101];
	cin.getline(a,101);
	cin.getline(b,101);
	char a1[101],b1[101];
	for (int i = 0; i < strlen(a);i++){
		if(a[i]==' '){
			i1++; 
		}
		else{
			a1[i1]=a[i];
			i1++;
		}
	}
	for (int j = 0; j < strlen(b);j++){
		if(b[j]==' '){
			j1++;
		}
		else{
			b1[j1]=b[j];
			j1++;
		}
	}
	cout<<a1<<endl<<b1;
}
