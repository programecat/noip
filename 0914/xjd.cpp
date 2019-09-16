//#include<iostream>
//using namespace std;
//int main(){
//	int n,m,a[100],g;
//	cin>>n;
//	for (int i=0;i<n;i++){
//		cin>>a[i];
//	} 
//	cin>>m;
//	
//	
//	for (int b=0;b<m;b++){
//		if(a[b] == m)   // 记住if语句后面也要尽量加上两个大括号 -- by teacherweng
//			g++;
//			cout<<g;
//	}
//return 0;
//}



//#include<iostream>
//using namespace std;
//int main(){
//	int n[100][100],a,b;
//	cin>>a>>b;
//	for(int c=0;c<a;c++){
//		for(int d=0;d<b;d++){
//			cout<<n[c][d];
//		}
//	}
//return 0;
//}



#include<iostream>
#include<cstring>
//using namespace std;
//int main(){
//	char a[101];
//	cin.getline(a,101);
//
//	char b,c;
//	b=getchar();
//	getchar();
//	c=getchar();
//	cout<<b<<" "<<c<<endl;
//	
//	for (int i=0;i<strlen(a);i++){
//		if (a[i]==b){
//			a[i]=c;
//		}
//	}
//	cout<<a<<endl;
//return 0;
//}



#include<iostream>
using namespace std;
int main(){
	int g,h;
	h=0;
	g=0;
	char a[101],b[101];
	cin.getline(a,101);
	cin.getline(b,101);
	
	char a1[101],b1[101];
	for(int i=0;i<strlen(a);i++){
		if(a[i]==' '){         // 这里的73到78行的if语句体里面是空的，所以我们可以改成 if (a[i] != ' ') { a1[h++] = a[i]; }
		}
		else{
			a1[h]=a[i];
			h++;
		}
								}
	for(int x=0;x<strlen(b);x++){
		if(b[x]==' '){
		}
		else{
			b1[g]=b[x];
			g++;
		}
	}
	cout<<a1<<endl<<b1;
	return 0;
}
