#include<stdio.h>
void swap(int* &a,int* &b){
	int *temp=a;
	a=b;
	b=temp;
} 
int main(){
	int a=1;
	int b=3;
	int *p=&a;
	int *q=&b;
	//��Ҫ����& 
	swap(p,q);
	printf("%d %d",*p,*q);
	// Ҫ�Ǵ�ӡab���������1,3 
	return 0;
}
