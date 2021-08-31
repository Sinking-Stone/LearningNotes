//
// Created by SinkingStone on 2021/8/31.
//

#include <stdio.h>
#include <iostream>
typedef long long LL;
LL binaryPow(LL a,LL b,LL m){
    LL ans=1;
    while (b>0){
        if(b&1)     // 判断奇偶
            ans=ans*a%m;
        a=a*a%m;    // 平方
        b>>=1;      // b=b/2;
    }
    return ans;
}
int main(){
    LL re= binaryPow(10,18,1673201);
    std::cout<<re;
}