#include<stdio.h>
#include<string.h>
int main(){
	char str1[50],str2[50];
	gets(str1);
	gets(str2);
	int len=strlen(str1);
	// ��ȡ�ַ������� 
	printf("str1���� :%d\n",len);
	int cmp=strcmp(str1,str2);
	// �Ƚ������ַ�����С
	// ��һ�������󣬷������� 
	// �ڶ��������󣬷��ظ��� 
	// ��������һ���󣬷���0 
	if(cmp<0)
		printf("str1<str2\n");
	else if(cmp>0)
		printf("str1>str2\n");
	else printf("str1=str2\n");
	strcpy(str1,str2);
	// str2�����ݸ��Ƹ�str1��Ҳ��������'\0' 
	puts(str1); 
	strcat(str1,str2);
	// str2����ƴ�ӵ�str1���棬str2���ֲ��� 
	puts(str1);
	puts(str2);
	return 0;
}
