//
// Created by SinkingStone on 2021/8/31.
//

#include <stdio.h>

const int manx = 100;

void merge(int A[], int L1, int R1, int L2, int R2) {
    int i = L1, j = L2;
    int temp[manx], index = 0;
    while (i <= R1 && j <= R2) {
        if (A[i] <= A[j]) temp[index++] = A[i++];
        else temp[index++] = A[j++];
    }
    while (i <= R1) temp[index++] = A[i++];
    while (j <= R2) temp[index++] = A[j++];
    for (int i = 0; i < index; i++) {
        A[L1 + i] = temp[i];
    }
}

void mergeSort(int A[]) {
    int n=sizeof(A)/sizeof(A[0]);
    for(int step=2;step/2<n;step*=2){
        for(int i=1;i<=n;i++){
            int mid=i+step/2-1;
            if(mid+1<=n)  merge(A,i,mid,mid+1,i+step-1>n?i+step-1:n);
        }
    }
}



void mergeSort2(int A[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort2(A, left, mid);
        mergeSort2(A, mid + 1, right);
        merge(A, left, mid, mid + 1, right);
    }
}

int main() {
    int a[] = {9, 7, 5, 3, 1, 2, 4, 6, 8, 0};
//    mergeSort(a, 0, 9);
    mergeSort(a);
    for (int i = 0; i < 10; ++i) {
        printf("%d", a[i]);
    }
}