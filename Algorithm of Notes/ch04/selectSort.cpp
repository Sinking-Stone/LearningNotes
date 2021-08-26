#include<stdio.h>
// 算法思想就是每次选择最小的元素，对其进行排序
// 然后循环直到排好 
void selectSort(int* A,int n){
	for(int i=0;i<n;i++){
		int k=i;				// 选择要排序的位置 
		for(int j=i;j<n;j++){	// 选择最小的元素 
			if(A[j]<A[k]) k=j; 	
		}	
		int temp=A[i];			// 将最小的元素排在最前面 
		A[i]=A[k];
		A[k]=temp; 
	}
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
}

int main(){
	int a[10]={9,8,1,0,6,3,4,7};
	selectSort(a,10);
	return 0; 
}
