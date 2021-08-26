#include<stdio.h>
#include<string.h>
void strcat(char *s1, char *s2, char *s3){
	int sl1=strlen(s1);
	int len=strlen(s1)+strlen(s2);
	for(int i=0;i<len;i++){
		if(i<sl1) s3[i]=s1[i];
		else s3[i]=s2[i-sl1];
	}
	for(int i=0;i<len;i++){
	printf("%c",s3[i]);
	}
	return;
}

int main(){
	char s1[]="123";
	char s2[]="12";
	char s3[100];
	strcat(s1,s2,s3);
}
