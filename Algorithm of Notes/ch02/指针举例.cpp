#include<stdio.h>
void swap(int *a,int *b){
	int temp;
	//ע����temp������*temp 
	temp=*a;
	*a=*b;
	*b=temp;
} 
int main(){
	int a=1;
	int b=3;
	int *p=&a;
	int *q=&b;
	//��Ҫ����& 
	swap(p,q);
	printf("%d %d",a,b);
	return 0;
}
