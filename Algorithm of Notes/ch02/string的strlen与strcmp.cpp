#include<stdio.h>
#include<string.h>
int main(){
	char str1[50],str2[50];
	gets(str1);
	gets(str2);
	int len=strlen(str1);
	//��ȡ�ַ������� 
	printf("%d\n",len);
	int cmp=strcmp(str1,str2);
	// �Ƚ������ַ�����С
	// ��һ�������󣬷������� 
	// �ڶ��������󣬷��ظ��� 
	// ��������һ���󣬷���0 
	if(cmp<0)
		printf("str1<str2");
	else if(cmp>0)
		printf("str1>str2");
	else printf("str1=str2");
	strcpy(str1,str2);
	puts(str1); 
	return 0;
}
