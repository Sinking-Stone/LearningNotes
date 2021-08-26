#include<stdio.h>
#include<string.h>
int main(){
	char str1[50],str2[50];
	gets(str1);
	gets(str2);
	int len=strlen(str1);
	//获取字符串长度 
	printf("%d\n",len);
	int cmp=strcmp(str1,str2);
	// 比较两个字符串大小
	// 第一个参数大，返回正数 
	// 第二个参数大，返回负数 
	// 两个参数一样大，返回0 
	if(cmp<0)
		printf("str1<str2");
	else if(cmp>0)
		printf("str1>str2");
	else printf("str1=str2");
	strcpy(str1,str2);
	puts(str1); 
	return 0;
}
