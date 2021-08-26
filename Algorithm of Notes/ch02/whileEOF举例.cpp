#include<stdio.h>
int main(){
	int a,b;
	// while，EOF举例 
	while(scanf("%d %d",&a,&b)!=EOF,a||b){
		// scanf("%d %d",&a,&b)读入几个整数就返回几 
		printf("%d",a+b);
	}
	return 0;
}
