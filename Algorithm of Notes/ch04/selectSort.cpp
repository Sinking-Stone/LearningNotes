#include<stdio.h>
// �㷨˼�����ÿ��ѡ����С��Ԫ�أ������������
// Ȼ��ѭ��ֱ���ź� 
void selectSort(int* A,int n){
	for(int i=0;i<n;i++){
		int k=i;				// ѡ��Ҫ�����λ�� 
		for(int j=i;j<n;j++){	// ѡ����С��Ԫ�� 
			if(A[j]<A[k]) k=j; 	
		}	
		int temp=A[i];			// ����С��Ԫ��������ǰ�� 
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
