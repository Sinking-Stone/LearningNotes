#include<stdio.h>
#include<math.h>
int main(){
	int num;
	char ch;
	int unuse=scanf("%d %c",&num,&ch);
	for(int i=0;i<ceil(num/2.0);i++){
		for(int j=0;j<num;j++){
			if(i==0||i==ceil(num/2.0)-1) printf("%c",ch);
			if((i>0&&i<ceil(num/2.0)-1)&&(j==0||j==num-1)) printf("%c",ch);
			if((i>0&&i<ceil(num/2.0)-1)&&(j>0&&j<num-1)) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
