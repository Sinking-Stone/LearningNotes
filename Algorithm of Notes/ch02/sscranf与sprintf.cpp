#include<stdio.h>
int main(){
	int n; 
	char str[100]="123";
	sscanf(str,"%d",&n);
	// �� str �е������� %d ����ʽ���� n 
	printf("%d\n",n);
	sprintf(str,"%d",n);
	printf("%s\n",str);
	// �� n �� %d ����ʽд�� str�� 
	return 0;
} 
