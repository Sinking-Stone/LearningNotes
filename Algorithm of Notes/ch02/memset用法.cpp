#include<stdio.h>
#include<string.h>
int main(){
	int a[5]={1,2,3,4,5};
	memset(a,0,sizeof(a)); 
	// memset依赖于 string.h 头标签 
	// 作用是在一段内存块中填充某个给定的值
	// 第一个参数是要初始化的单元首地址
	// 第二个参数一般使用“0”初始化内存单元，而且通常是给数组或结构体进行初始化 
	// 第三个参数的值一般用 sizeof()获取，填充数据空间的字节数 
	for(int i=0;i<5;i++){
		printf("%d ",a[i]);
	}
	printf("\n ");
	memset(a,-1,sizeof(a)); 
	for(int i=0;i<5;i++){
		printf("%d ",a[i]);
	}
	return 0;
} 
