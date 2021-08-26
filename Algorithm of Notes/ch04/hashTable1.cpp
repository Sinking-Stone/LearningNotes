#include<stdio.h>

const int maxn=10010;

int hashTable[maxn]={0};

int main(){
	int n,m,x;
	if(scanf("%d %d",&n,&m)){};
	for(int i=0;i<n;i++){
		if(scanf("%d",&x)){};
		hashTable[x]++;
	}
	for(int i=0;i<m;i++){
		if(scanf("%d",&x)){};
		printf("%d\n",hashTable[x]);
	}
	return 0;
}
