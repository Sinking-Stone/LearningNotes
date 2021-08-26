#include<stdio.h>

int a[100000]={0};

int main(){
	int i,n;
	int re=1,ans=-1;
	(void)scanf("%d",&n);
	for(i=0;i<n;i++){
		int index,temp;
		(void)scanf("%d%d",&index,&temp);
		a[index]+=temp;
	}
	for(i=1;i<100000;i++){
		if(a[i]>ans) {
			ans=a[i];
			re=i;
		}
	}
	printf("%d %d",re,ans);
	return 0;
}
