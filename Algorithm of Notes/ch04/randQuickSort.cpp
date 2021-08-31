//
// Created by SinkingStone on 2021/8/31.
//


#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>

int randPartition(int A[],int left,int right){
    srand((unsigned)time(NULL));
    int p=(round(1.0*rand()/RAND_MAX*(right-left)+left));
    std::swap(A[p],A[left]);
    int temp=A[left];
    while(left<right){
        while (left<right&&A[right]>temp) right--;
        A[left]=A[right];
        while (left<right&&A[left]<temp) left++;
        A[right]=A[left];
    }
    A[left]=temp;
    return left;
}
void quickSort(int A[],int left,int right){
    if(left<right){
        int pos= randPartition(A,left,right);
        quickSort(A,left,pos-1);
        quickSort(A,pos+1,right);
    }
}

int main(){
    int a[]={9,1,2,8,3,7,6,4,5};
    quickSort(a,0,9);
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {

        printf("%d ",a[i]);
    }
}