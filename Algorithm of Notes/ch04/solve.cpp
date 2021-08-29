//
// Created by SinkingStone on 2021/8/29.
//
#include <stdio.h>
const double eps=1e-5;

double  f(double x){
    return x*x-2;
}

double solve(double L,double R){
    double left=L,right=R,mid;
    while (right-left>eps){
        mid=(left+right)/2;
        if(f(mid)>0) right=mid;
        else left=mid;
    }
    return mid;
}

int main(){
    double ans=solve(1,2);
    printf("%lf",ans);
    return 0;
}
