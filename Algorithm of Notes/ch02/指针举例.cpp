#include<stdio.h>
void swap(int *a,int *b){
	int temp;
	//注意是temp，不是*temp 
	temp=*a;
	*a=*b;
	*b=temp;
} 
int main(){
	int a=1;
	int b=3;
	int *p=&a;
	int *q=&b;
	//不要忘了& 
	swap(p,q);
	printf("%d %d",a,b);
	return 0;
}
