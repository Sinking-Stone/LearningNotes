#include<stdio.h>

void change(int num,int sys){
	if(num!=0){
		change(num/sys,sys);
		printf("%d",num%sys);
	}
}
int main(){
	int num1,num2,sys,sum;
	if(scanf("%d %d %d",&num1,&num2,&sys)){};
	sum=num1+num2;
	if(sum==0) printf("0");
	else change(sum,sys);
	return 0;
} 

