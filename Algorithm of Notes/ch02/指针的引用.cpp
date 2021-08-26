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
	//不要忘了& 
	swap(p,q);
	printf("%d %d",*p,*q);
	// 要是打印ab，结果还是1,3 
	return 0;
}
