#include<iostream>
#include<cstring>
using namespace std;

int a[10];

int main(){
	int num=0;
	for(int i=0;i<10;i++){
		if(scanf("%d",&a[i])){};
		num+=a[i];
	}
	int ans[num];
	if(a[0]!=0){
		for(int j=1;j<10;j++){
			if(a[j]!=0){
				printf("%d",j);
				a[j]--;
				break; 
			}
		}
	}
	for(int i=0;i<10;i++){
		if(a[i]!=0){
			for(int j=0;j<a[i];j++){
				printf("%d",i);
			}
		}
	}
}
