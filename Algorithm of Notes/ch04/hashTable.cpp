#include<stdio.h>

const int maxn=10010;

bool hashTable[maxn]={false};

int main(){
	int n,m,x;
	if(scanf("%d %d",&n,&m)){};
	for(int i=0;i<n;i++){
		if(scanf("%d",&x)){};
		hashTable[x]=true;
	}
	for(int i=0;i<m;i++){
		if(scanf("%d",&x)){};
		if(hashTable[x]==true) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
