#include<stdio.h>
#include<string.h>
int main(){
	int a[5]={1,2,3,4,5};
	memset(a,0,sizeof(a)); 
	// memset������ string.h ͷ��ǩ 
	// ��������һ���ڴ�������ĳ��������ֵ
	// ��һ��������Ҫ��ʼ���ĵ�Ԫ�׵�ַ
	// �ڶ�������һ��ʹ�á�0����ʼ���ڴ浥Ԫ������ͨ���Ǹ������ṹ����г�ʼ�� 
	// ������������ֵһ���� sizeof()��ȡ��������ݿռ���ֽ��� 
	for(int i=0;i<5;i++){
		printf("%d ",a[i]);
	}
	printf("\n ");
	memset(a,-1,sizeof(a)); 
	for(int i=0;i<5;i++){
		printf("%d ",a[i]);
	}
	return 0;
} 
