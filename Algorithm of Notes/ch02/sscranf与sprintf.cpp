#include<stdio.h>
int main(){
	int n; 
	char str[100]="123";
	sscanf(str,"%d",&n);
	// 将 str 中的数据以 %d 的形式传给 n 
	printf("%d\n",n);
	sprintf(str,"%d",n);
	printf("%s\n",str);
	// 将 n 以 %d 的形式写到 str中 
	return 0;
} 
