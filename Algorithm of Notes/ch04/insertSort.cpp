#include<stdio.h>
// 将元素插入到前面有序的元素中
// 中间会牵涉到已有序的元素的移动问题 
void insrtSort(int* A,int n){
	for(int i=1;i<n;i++){
		int temp=A[i],j=i;
		while(j>0&&temp<A[j-1]){
			A[j]=A[j-1];
			j--;
		}
		A[j]=temp;
	}
	for(int i=0;i<n;i++){
		printf("%d ",A[i]); 
	} 
} 

int main(){
	int a[10]={2,5,9,8,1,0,6,3,4,7};
	insrtSort(a,10);
	return 0; 
}
