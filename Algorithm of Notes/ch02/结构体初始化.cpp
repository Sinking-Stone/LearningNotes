#include<stdio.h>
struct studentInfo{
	int id;
	char gender;
	// 默认构造函数，用于初始化 
	studentInfo(){}
	// 用于一个值的初始化 
	studentInfo(int _id){
		id=_id;
	}
	// 用于两个值的初始化 
	studentInfo(int _id,char _gender){
		id=_id;
		gender=_gender;
	}
	// 以上三者可同时存在
	// 简化构造函数写法 
	// studentInfo(int _id，char _gender): id(_id),gender(_gender) {}
} stu[10];
int main(){
	int num=0;
	for(int i=0;i<3;i++){
		for(char j='a';j<'z';j++){
			stu[num++]=studentInfo(i,j);
		}
	}
	for(int i=0;i<num;i++){
		printf("%d %c\n",stu[i].id,stu[i].gender);
	}
}
