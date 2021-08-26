#include<stdio.h>

const int maxn=100;
char S[maxn][5],temp[5];
int hashTable[26*26*26+10];
 
// 将A-Z、a-z、0-9这62个数字添加到hash表上 
int hashFunc(char S[],int len){
	int id=0;
	for(int i=0;i<len;i++){
		if(S[i]>'A'&&S[i]<='Z')
			id=id*52+(S[i]-'A');
		else if(S[i]>'a'&&S[i]<='z')
			id=id*52+(S[i]-'a')+26;
		else if(S[i]>'0'&&S[i]<='9')
			id=id*10+(S[len-1]-'0');
	}
	return id;
}

int main(){
	int n,m;
	if(scanf("%d %d",&n,&m)){}; 
	for(int i=0;i<n;i++){
		if(scanf("%s",&S[i])){};
		int id=hashFunc(S[i],3);
		hashTable[id]++;
	}
	for(int i=0;i<m;i++){
		if(scanf("%s",&temp)){};
		int id=hashFunc(temp,3);
		printf("%d",hashTable[id]);
	}
	return 0;
} 
