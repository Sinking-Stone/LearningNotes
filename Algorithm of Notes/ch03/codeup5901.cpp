#include<stdio.h>
#include<string.h>
int main(){
	char str[256];
	gets(str);
	int len=strlen(str);
	int flag=0;
	if(len%2==0){
		for(int i=len/2-1,j=len/2;j<len;j++,i--){
			if(str[i]!=str[j]){
				printf("NO");
				flag=1;
				break;
			}
		}
	}
	else{
		for(int i=len/2-1,j=len/2+1;j<len;j++,i--){
			if(str[i]!=str[j]){
				printf("NO");
				flag=1;
				break;
			}
		}
	}
	if(flag==0) printf("YES");
}
