#include<stdio.h>
int main(){
	int a,b;
	// while��EOF���� 
	while(scanf("%d %d",&a,&b)!=EOF,a||b){
		// scanf("%d %d",&a,&b)���뼸�������ͷ��ؼ� 
		printf("%d",a+b);
	}
	return 0;
}
