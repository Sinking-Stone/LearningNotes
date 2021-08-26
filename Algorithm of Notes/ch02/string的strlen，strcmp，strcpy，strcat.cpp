#include<stdio.h>
#include<string.h>
int main(){
	char str1[50],str2[50];
	gets(str1);
	gets(str2);
	int len=strlen(str1);
	// 获取字符串长度 
	printf("str1长度 :%d\n",len);
	int cmp=strcmp(str1,str2);
	// 比较两个字符串大小
	// 第一个参数大，返回正数 
	// 第二个参数大，返回负数 
	// 两个参数一样大，返回0 
	if(cmp<0)
		printf("str1<str2\n");
	else if(cmp>0)
		printf("str1>str2\n");
	else printf("str1=str2\n");
	strcpy(str1,str2);
	// str2的内容复制给str1，也包括复制'\0' 
	puts(str1); 
	strcat(str1,str2);
	// str2内容拼接到str1后面，str2保持不变 
	puts(str1);
	puts(str2);
	return 0;
}
