#include<stdio.h>
int main() {
	int a[10]={3,21,15,34,2}; 
	for(int i=1;i<5;i++){
	//һ������n-1�� 
		for(int j=0;j<5-i;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(int i=0;i<5;i++){
		printf("%d ",a[i]);
	}
}
