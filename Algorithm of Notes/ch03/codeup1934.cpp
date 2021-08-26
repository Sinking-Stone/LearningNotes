#include<stdio.h>
int main(){
	int num,search,flag=0;
	scanf("%d",&num);
	int a[num];
	for(int i=0;i<num;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&search);
	for(int i=0;i<num;i++){
		if(search==a[i]) {
			printf("%d",i);
			flag=1;
			break;
		}
	}
	if(flag==0) printf("-1");
	return 0;
}
