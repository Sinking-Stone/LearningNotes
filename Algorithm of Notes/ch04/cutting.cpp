//
// Created by SinkingStone on 2021/8/29.
//

#include <stdio.h>
int N; //N个木棒
//最长的木棒
int Max(int arr[]){
    int max=0;
    for(int i=0;i<N;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
//计算切割后小木棒总数
int f(int arr[],int L){
    int sum=0; //切成sum个小木棒
    for(int i=0;i<N;i++){
        sum=sum+arr[i]/L;
    }
    return sum;
}
//二分法
int solve(int K,int arr[]){
    int left=0,right=Max(arr),mid;
    while(left<right){
        mid=(left+right)/2;
        if(f(arr,mid)<K){ //小木棒个数K-1时
            right=mid;
        }else{
            left=mid+1;
        }
    }
    return right-1; //返回长度
}
int main(){
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);//N个木棒的原始长度
    }
    int K; //K个长度相同的小木棒
    scanf("%d",&K);
    printf("%d",solve(K,arr));
    return 0;
}