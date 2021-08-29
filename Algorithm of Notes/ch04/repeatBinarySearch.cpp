//
// Created by SinkingStone on 2021/8/29.
//

#include <stdio.h>
int lower_bound(int A[],int left,int right,int x){
    int mid;
    while(left<right){
        mid=left+(right-left)/2;
        if(A[mid]>=x) right=mid;
        else left=mid+1;
    }
    return left;
}
int upper_bound(int A[],int left,int right,int x){
    int mid;
    while(left<right){
        mid=left+(right-left)/2;
        if(A[mid]> x) right=mid;
        else left=mid+1;
    }
    return left;
}
int main(){
    const int n=18;
    int A[n]={1,3,4,6,6,6,6,6,6,6,6,6,7,8,10,11,12,15};
    printf("%d %d", lower_bound(A,0,n-1,6), upper_bound(A,0,n-1,6));
    return 0;
}